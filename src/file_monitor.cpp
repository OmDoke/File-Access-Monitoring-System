// file_monitor.cpp
#include "file_monitor.h"
#include "email_alert.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

namespace fs = std::filesystem;

FileMonitor::FileMonitor(const std::string& directory) : monitoredDir(directory) {
    for (const auto& entry : fs::directory_iterator(monitoredDir)) {
        if (entry.is_regular_file()) {
            fileTimestamps[entry.path().string()] = fs::last_write_time(entry);
        }
    }
}

void FileMonitor::logAccess(const std::string& file, const std::string& event) {
    std::ofstream logFile("logs/access.log", std::ios::app);
    if (logFile) {
        logFile << "File: " << file << " | Event: " << event << " | Time: " << time(nullptr) << "\n";
        logFile.close();
    }
    std::cout << "Logged: " << event << " -> " << file << std::endl;

    // Send email alert if unauthorized access
    if (event == "UNAUTHORIZED_ACCESS") {
        sendEmailAlert(file);
    }
}

void FileMonitor::detectChanges() {
    while (true) {
        for (const auto& entry : fs::directory_iterator(monitoredDir)) {
            if (entry.is_regular_file()) {
                std::string filePath = entry.path().string();
                auto lastModifiedTime = fs::last_write_time(entry);

                if (fileTimestamps.find(filePath) == fileTimestamps.end()) {
                    fileTimestamps[filePath] = lastModifiedTime;
                    logAccess(filePath, "FILE_CREATED");
                } else if (fileTimestamps[filePath] != lastModifiedTime) {
                    fileTimestamps[filePath] = lastModifiedTime;
                    logAccess(filePath, "FILE_MODIFIED");
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::seconds(5)); // Check every 5 seconds
    }
}

void FileMonitor::startMonitoring() {
    std::cout << "Monitoring directory: " << monitoredDir << std::endl;
    detectChanges();
}
