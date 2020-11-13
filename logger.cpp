#include "logger.h"

Logger::Logger() {
    logPath = "MyLogs\\";
    struct stat info;

    if(stat(logPath.c_str(), &info) != 0)
    {
        std::cout << "Creating directory " + logPath << std::endl;
        _mkdir(logPath.c_str());
    }
    else if(info.st_mode & S_IFDIR)
    {
        std::cout << "Directory " + logPath + " already exists!" << std::endl;
    }
}

Logger::~Logger() {}

/*
template<typename T1>
void Logger::LogToBinaryFile(const std::string &FileName, T1 &values) {
    std::ofstream out(FileName, std::ios::app | std::ios::binary);
    if (out.is_open())
    {
        for (int j = 0; j < values.size(); j++)
        {
            double wr = values[j];
            out.write((char *) &wr, sizeof(double));
        }
    }
    else
    {
        std::cout << "File isn't open" << std::endl;
    }
    out.close();
}

template<typename T1>
void LogToBinaryFile(const std::string &FileName, T1 &values) {
    std::ofstream out(FileName, std::ios::app | std::ios::binary);
    if (out.is_open())
    {
        out.write((char *) &values, sizeof(double));
    }
    else
    {
        std::cout << "File isn't open" << std::endl;
    }
    out.close();
}

template<typename T2>
void Logger::LogToTextFile(const std::string &FileName, T2 &values) {
    std::ofstream out(FileName, std::ios::app);
    if (out.is_open())
    {
        for (int j = 0; j < values.size(); j++)
        {
            out << values[j] << " " << std::endl;
        }
    }
    else
    {
        std::cout << "File isn't open" << std::endl;
    }
    out.close();
}

template<typename T2>
void LogToTextFile(const std::string &FileName, T2 &values) {
    std::ofstream out(FileName, std::ios::app);
    if (out.is_open())
    {
        out << values << " " << std::endl;
    }
    else
    {
        std::cout << "File isn't open" << std::endl;
    }
    out.close();
}

template void Logger::LogToBinaryFile(const std::string &FileName, std::vector<double> &values);
template void Logger::LogToBinaryFile(const std::string &FileName, double &values);

template void Logger::LogToTextFile(const std::string &FileName, std::vector<double> &values);
template void Logger::LogToTextFile(const std::string &FileName, double &values);
 */

void Logger::LogToBinaryFile(const std::string &FileName, std::vector<double> &values, std::clock_t startTime) {
    std::ofstream out(logPath + FileName, std::ios::app | std::ios::binary);
    if (out.is_open())
    {
        for (int j = 0; j < values.size(); j++)
        {
            double wr = values[j];
            out.write((char *) &wr, sizeof(double));
            std::clock_t time = std::clock() - startTime;
            out.write((char *) &time, sizeof(std::clock_t));
        }
    }
    else
    {
        std::cout << "File isn't open" << std::endl;
    }
    out.close();
}

void Logger::LogToBinaryFile(const std::string &FileName, double value, std::clock_t startTime) {
    std::ofstream out(logPath + FileName, std::ios::app | std::ios::binary);
    if (out.is_open())
    {
        out.write((char *) &value, sizeof(double));
        std::clock_t time = std::clock() - startTime;
        out.write((char *) &time, sizeof(std::clock_t));
    }
    else
    {
        std::cout << "File isn't open" << std::endl;
    }
    out.close();
}

void Logger::LogToTextFile(const std::string &FileName, std::vector<double> &values, std::clock_t startTime) {
    std::ofstream out(logPath + FileName, std::ios::app);
    if (out.is_open())
    {
        for (int j = 0; j < values.size(); j++)
        {
            out << values[j] << " " << std::clock() - startTime << std::endl;
        }
    }
    else
    {
        std::cout << "File isn't open" << std::endl;
    }
    out.close();
}

void Logger::LogToTextFile(const std::string &FileName, double value, std::clock_t startTime) {
    std::ofstream out(logPath + FileName, std::ios::app);
    if (out.is_open())
    {
        out << value << " " << std::clock() - startTime << std::endl;
    }
    else
    {
        std::cout << "File isn't open" << std::endl;
    }
    out.close();
}

void Logger::getBinaryLog(const std::string &FileName)
{
    std::fstream input(logPath + FileName, std::ios::in | std::ios::binary);

    if (input.is_open())
    {
        std::cout << "Binary log:" << std::endl;
        while (!input.eof())
        {
            double value;
            std::clock_t time;
            input.read((char *) &value, sizeof(double));
            input.read((char *) &time, sizeof(std::clock_t));
            if (input.eof()){
                break;
            }
            std::cout << "Value: " << value << "; Time: " << time << std::endl;
        }
    }
    else
    {
        std::cout << "File isn't open" << std::endl;
    }
    input.close();
}

void Logger::getTextLog(const std::string &FileName){
    std::fstream input(logPath + FileName, std::ios::in);

    double value;
    std::clock_t time;

    if (input.is_open())
    {
        std::cout << "Text log:" << std::endl;
        while (input >> value >> time)
        {
            std::cout << "Value: " << value << "; Time: " << time << std::endl;
        }
    }
    else
    {
        std::cout << "File isn't open" << std::endl;
    }
    input.close();
}