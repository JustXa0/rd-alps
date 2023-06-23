#include "monitorInfoManager.h"

void monitorInfoManager::RetrieveMonitorInfo(MonitorInfo& monitorInfo)
{
	HMONITOR hMonitor = MonitorFromWindow(GetDesktopWindow(), MONITOR_DEFAULTTOPRIMARY);

	if (hMonitor != NULL)
	{
		MONITORINFOEX monitorInfoEX;
		monitorInfoEX.cbSize = sizeof(MONITORINFOEX);

		if (GetMonitorInfoW(hMonitor, &monitorInfoEX))
		{
			
			int requiredSize = WideCharToMultiByte(CP_UTF8, 0, monitorInfoEX.szDevice, -1, nullptr, 0, nullptr, nullptr);
			std::vector<char> buffer(requiredSize);
			WideCharToMultiByte(CP_UTF8, 0, monitorInfoEX.szDevice, -1, buffer.data(), requiredSize, nullptr, nullptr);
			monitorInfo.friendlyName = std::string(buffer.data());
		}
	}
}

void monitorInfoManager::update()
{
	RetrieveMonitorInfo(monitorInfo);
}