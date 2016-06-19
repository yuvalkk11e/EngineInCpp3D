#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include "FaceBuffer.h"
#include "VertexBuffer.h"

void Launch_Rendering(VertexBuffer &c, FaceBuffer &a, int View_Angle, int HEIGHT, int WIDTH, int View_Distance);