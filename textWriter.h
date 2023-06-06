#pragma once
#include <Windows.h>
#include <string>
class textWriter
{

public: 
	void write(HDC hdc, HWND hWnd, std::string message, int R, int G, int B);
};

