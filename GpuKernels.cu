#include "GpuKernels.cuh"

//This is where all of our kernels code is :

#define PI 3.14159265
#define PIr (180/PI) // I CHANGED FROM PI/180 TO THIS !

void cudaCheckErrors(std::string msg)
{
	cudaError_t err = cudaGetLastError();
	if (err != cudaSuccess)
	{
		fprintf(stderr, "Fatal error: %s (%s at %s:%d)\n",
			msg, cudaGetErrorString(err),
			__FILE__, __LINE__);
		fprintf(stderr, "*** FAILED - ABORTING\n");
		exit(1);
	}
}

__global__ void RenderingKernel(VertexBuffer *output)
{
	//(*output).getValue(0);
}

void Launch_Rendering(VertexBuffer &c, FaceBuffer &a, int View_Angle ,int HEIGHT, int WIDTH, int View_Distance)
{
	Triangle **dev_a;
	VertexBuffer *dev_c;
	cudaError_t cudaStatus;

	int size = a.getSize();

	// Choose which GPU to run on, change this on a multi-GPU system.
	cudaStatus = cudaSetDevice(0);

	// Allocate GPU memory for our classes    .
	cudaStatus = cudaMalloc((void**)&dev_a, sizeof(Triangle)*size);
	cudaCheckErrors("malloc2");

	cudaStatus = cudaMalloc((void**)&dev_c, sizeof(VertexBuffer));
	cudaCheckErrors("malloc1");

	// copy our classes to allocated memory
	cudaStatus = cudaMemcpy(dev_c, &c, sizeof(VertexBuffer), cudaMemcpyHostToDevice);
	cudaCheckErrors("MEMCPY2");
	
	cudaMemcpy(dev_a, a.getValues(), sizeof(Triangle)*size, cudaMemcpyHostToDevice);


	//cudaStatus = cudaMemcpy(dev_a, &a, sizeof(FaceBuffer), cudaMemcpyHostToDevice);
	//cudaCheckErrors("MEMCPY1");

	/*Copy input vectors from host memory to GPU classes .
	Triangle * data;
	cudaMalloc((void**)&data, sizeof(Triangle)*size);
	cudaMemcpy(data, a.getValues(), sizeof(Triangle)*size, cudaMemcpyHostToDevice);
	cudaMemcpy(&(dev_c), &data, sizeof(Triangle *)*size, cudaMemcpyHostToDevice); //cant access data of dev_c
	*/

	Vector3 up(0, 1, 0);
	float angle_bith = View_Angle / HEIGHT;
	float angle_bitw = View_Angle / WIDTH;
	// Launch a kernel on the GPU with one thread for each element.
	RenderingKernel << <size, 3>> > (dev_c);

	// Check for any errors launching the kernel
	cudaStatus = cudaGetLastError();

	// cudaDeviceSynchronize waits for the kernel to finish, and returns
	// any errors encountered during the launch.
	cudaStatus = cudaDeviceSynchronize();
}