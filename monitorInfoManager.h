#pragma once
#include <Windows.h>
#include <vector>
#include <string>
#include <comdef.h>
#include <Wbemidl.h>

#pragma comment(lib, "wbemuuid.lib")

struct MonitorInfo
{
	std::string friendlyName;
	RECT displayArea;
	RECT workArea;
};

class monitorInfoManager
{
private:
	void RetrieveMonitorInfo(MonitorInfo& monitorInfo);
	

public:
	MonitorInfo monitorInfo;
	void update();



};