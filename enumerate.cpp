#include "enumerate.h"

int enumerate::numMonitor()
{
	return GetSystemMetrics(SM_CMONITORS);
}
