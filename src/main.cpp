// main.cpp
#include <iostream>
#include "file_monitor.h"

int main() {
    std::string directory;
    std::cout << "Enter directory to monitor: ";
    std::cin >> directory;

    FileMonitor monitor(directory);
    monitor.startMonitoring();

    return 0;
}
