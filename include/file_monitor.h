// file_monitor.h
#ifndef FILE_MONITOR_H
#define FILE_MONITOR_H

#include <string>
#include <unordered_map>
#include <filesystem>

class FileMonitor {
private:
    std::string monitoredDir;
    std::unordered_map<std::string, std::filesystem::file_time_type> fileTimestamps;
    void logAccess(const std::string& file, const std::string& event);
    void detectChanges();

public:
    FileMonitor(const std::string& directory);
    void startMonitoring();
};

#endif
