#ifndef LOGGER1_LOGGER_H
#define LOGGER1_LOGGER_H

#include "iostream"
#include <vector>
#include <fstream>
#include <string>
#include <ctime>
#include <windows.h>
#include <sys/stat.h>
#include <direct.h>

class Logger {
public:
    Logger();
    ~Logger();

    /*template<typename T1>
    void LogToBinaryFile(const std::string &FileName, T1 &values);

    template<typename T2>
    void LogToTextFile(const std::string &FileName, T2 &values);*/

    void LogToBinaryFile(const std::string &FileName, std::vector<double> &values, std::clock_t startTime);
    void LogToBinaryFile(const std::string &FileName, double value, std::clock_t startTime);

    void LogToTextFile(const std::string &FileName, std::vector<double> &values, std::clock_t startTime);
    void LogToTextFile(const std::string &FileName, double value, std::clock_t startTime);

    void getBinaryLog(const std::string &FileName);
    void getTextLog(const std::string &FileName);

private:
    std::string logPath;
};

#endif //LOGGER1_LOGGER_H
