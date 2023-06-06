#pragma once
#include <Windows.h>

class enumerate
{
private:
	int display;
	

public:
	int numMonitor() {
		return GetSystemMetrics(SM_CMONITORS);
	}


};

