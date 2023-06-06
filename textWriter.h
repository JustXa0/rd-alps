#pragma once
#include <Windows.h>
#include <string>
class textWriter
{
private: 
	HDC hdc;
	HWND hWnd;
	

public: 
	void write(std::string message, int R, int G, int B);
	textWriter(HDC uHdc, HWND uHWnd);
};

