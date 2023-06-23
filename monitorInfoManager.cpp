#include "monitorInfoManager.h"

void monitorInfoManager::RetrieveMonitorInfo(MonitorInfo& monitorInfo)
{
	std::vector<DISPLAYCONFIG_PATH_INFO> paths;
	std::vector<DISPLAYCONFIG_MODE_INFO> modes;
	UINT32 flags = QDC_ONLY_ACTIVE_PATHS;
	LONG isError = ERROR_INSUFFICIENT_BUFFER;

	UINT32 pathCount;
	UINT32 modeCount;
	isError = GetDisplayConfigBufferSizes(flags, &pathCount, &modeCount);

	if (isError)
	{
		return;
	}

	paths.resize(pathCount);
	modes.resize(modeCount);

	isError = QueryDisplayConfig(flags, &pathCount, paths.data(), &modeCount, modes.data(), nullptr);

	paths.resize(pathCount);
	modes.resize(modeCount);

	if (isError)
	{
		return;
	}

	int len = paths.size();
	for (int i = 0; i < len; i++)
	{
		DISPLAYCONFIG_TARGET_DEVICE_NAME targetName = {};
		targetName.header.adapterId = paths[i].targetInfo.adapterId;
		targetName.header.id = paths[i].targetInfo.id;
		targetName.header.type = DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_NAME;
		targetName.header.size = sizeof(targetName);
		isError = DisplayConfigGetDeviceInfo(&targetName.header);

		if (isError)
		{
			return;
		}

		monitorInfo.friendlyName = targetName.monitorFriendlyDeviceName;
	}
	
}

void monitorInfoManager::update()
{
	RetrieveMonitorInfo(monitorInfo);
}