
#include <iostream>
#include <Windows.h>
#include "wtypes.h"
#include <math.h>
//#include <GLFW\glfw3.h>
#include "Matrix.h"
#include "Vector3.h"
#include "VertexBuffer.h"
#include "TransformationMatrixes.h"
#include "Rendering.h"
using namespace std;

const char g_szClassName[] = "myWindowClass";

#define PI 3.14159265
Vector3 v_array[6] = { Vector3(0, 0, 0), Vector3(100, 100, 100), Vector3(-200, 200, 100), Vector3(0, 400, 30), Vector3(500, 300, 40), Vector3(600, -600, 100) };
//Vector3 v_array[3] = { Vector3(100, 100, 100), Vector3(300, 100, 100), Vector3(200, 300, 100) };
VertexBuffer buffer(v_array, 6);
Matrix m = TransformationMatrixes::rotationMatrix(3, 0,0 );
Matrix m3 = Matrix::IdentityMatrix(3);
float mi = m3.getValue(0, 0);
Matrix mdouble = Matrix::ScalarMultiplication(3, 2);
int Screen_Width = 1000, Screen_Height = 1000;
int View_Angle = 90;
Vector3  Camera_Pos(0, 0, -1000);
Vector3 Camera_Look(0, 0, 0);
int View_Distance = 1500;
bool running = true;

/*
int main()
{
	Vector3 v2(2, 2, 2);
	Vector3 b0 = buffer.getValue(0);
	for (int i = 0; i < 10;i++)
	{
		//m.toString();
		buffer.getValue(0).toString();
		buffer.TransforMatrix(m);
	}
	while (true)
	{

	}
	return 0;

}



// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	switch (msg)
	{
	case WM_CREATE:

		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		running = false; 
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		//buffer.DrawBufferLines(hdc);
		//buffer.DrawBufferTriangles(hdc);
		Rendering::LinesFromCamera(hdc, Camera_Pos, Camera_Look, buffer, View_Angle, Screen_Height, Screen_Width, View_Distance);
		EndPaint(hwnd, &ps);
		break;
	case WM_KEYDOWN:
		break;
	case WM_TIMER:
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;
	
	


	//Step 1: Registering the Window Class
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Window Registration Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	// Step 2: Creating the Window
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		g_szClassName,
		"3D Engine ! ",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 1000, 1000,
		NULL, NULL, hInstance, NULL);

	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	while (running)
	{
		ShowWindow(hwnd, nCmdShow);
		UpdateWindow(hwnd);

		// Step 3: The Message Loop
		while (GetMessage(&Msg, NULL, 0, 0) > 0)
		{
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
	}
	return Msg.wParam;
}

*/