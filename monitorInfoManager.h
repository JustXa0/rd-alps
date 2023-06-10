#pragma once
#include <Windows.h>
#include <vector>
#include <string>
#include <setupapi.h>
#include <devguid.h>
#include <locale>
#include <codecvt>

#pragma comment(lib, "Setupapi.lib")

struct monitorInfo {
    std::string name;
    RECT displayArea;
    RECT workArea;
};

class MonitorInfoManager {
private:
    static BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData);
    static std::string GetMonitorModelName(HMONITOR hMonitor);

public:
    std::vector<monitorInfo> monitorList;
    void updateInfo();
    std::string getMonitorName(int index);
};
