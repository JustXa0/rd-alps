#include "monitorInfoManager.h"

BOOL CALLBACK MonitorInfoManager::MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData) {
    std::vector<monitorInfo>* monitors = reinterpret_cast<std::vector<monitorInfo>*>(dwData);

    MONITORINFOEX mi{};
    mi.cbSize = sizeof(MONITORINFOEX);
    if (GetMonitorInfo(hMonitor, &mi)) {
        monitorInfo info;

        // Convert wide character array to string
        int bufferSize = WideCharToMultiByte(CP_UTF8, 0, mi.szDevice, -1, nullptr, 0, nullptr, nullptr);
        std::vector<char> buffer(bufferSize);
        WideCharToMultiByte(CP_UTF8, 0, mi.szDevice, -1, buffer.data(), bufferSize, nullptr, nullptr);
        info.name = buffer.data();

        info.displayArea = mi.rcMonitor;
        info.workArea = mi.rcWork;

        monitors->push_back(info);
    }

    return TRUE;
}

void MonitorInfoManager::updateInfo() {
    monitorList.clear();
    EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, reinterpret_cast<LPARAM>(&monitorList));
}

std::string MonitorInfoManager::getMonitorName(int index) {
    if (index >= 0 && index < monitorList.size()) {
        return monitorList[index].name;
    }

    return ""; // Return an empty string if the index is out of range
}