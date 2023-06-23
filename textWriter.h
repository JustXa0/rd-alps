#pragma once
#include <Windows.h>
#include <string>

class textWriter
{
private: 
	HDC hdc;
	HWND hWnd;
	

public: 
	void write(std::string, int, int, int);
	void write(std::string, int, int, int, int, int);
	void write(std::wstring, int, int, int, int, int);
	textWriter(HDC, HWND);
};

