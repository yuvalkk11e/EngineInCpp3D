
#include <iostream>
using namespace std;
#include "Matrix.h"
#include "Vector.h"
#include <Windows.h>
#include "wtypes.h"
//#include <GLFW\glfw3.h>
#include "VertexBuffer.h"

const char g_szClassName[] = "myWindowClass";

// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	Point p_array[6] = { Point(0, 0, 0), Point(100, 100, 100), Point(200, 0, 20), Point(200, 250, 30), Point(200, 300, 40), Point(300,300,0) };
	VertexBuffer buffer(p_array,6);
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	switch (msg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);

		//buffer.DrawBufferLines(hdc);
		buffer.DrawBufferTriangles(hdc);

		

		//
		// Draw a blue ellipse
		//HPEN hEllipsePen;
		//COLORREF qEllipseColor;
		//qEllipseColor = RGB(0, 0, 255);
		//hEllipsePen = CreatePen(PS_SOLID, 3, qEllipseColor);
		//hPenOld = (HPEN)SelectObject(hdc, hEllipsePen);1

		//Arc(hdc, 100, 100, 500, 250, 0, 0, 0, 0);

		//SelectObject(hdc, hPenOld);
		//DeleteObject(hEllipsePen);
		EndPaint(hwnd, &ps);

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
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 800,
		NULL, NULL, hInstance, NULL);

	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	// Step 3: The Message Loop
	while (GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}

