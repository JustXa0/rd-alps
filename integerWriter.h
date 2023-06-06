#pragma once
#include <Windows.h>
#include <cwchar>
class integerWriter
{
private:
	HDC hdc;
	HWND hWnd;

public:
	void intWrite(int num, int r, int g, int b);
	integerWriter(HDC uHdc, HWND uHWnd);

};

