#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <chrono>
#include <ctime>

#include "logger.h"

void GenerateRandomInfo(std::vector<double> & info, int size)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::normal_distribution<double> distribution(0.0,1.0);

    for (int j = 0; j < size; j++)
    {
        double randNum = distribution(generator);
        info.push_back(randNum);
    }
}

int main() {
    std::clock_t start;
    start = std::clock();

    Logger log = Logger();

    int counter = 0;
    int numberOfFile = 1;
    while (1)
    {
        if (counter >= 100){
            log.getTextLog("Log" + std::to_string(numberOfFile) + ".txt");

            log.getBinaryLog("Log" + std::to_string(numberOfFile) + ".bin");

            numberOfFile++;
            counter = 0;
        }
        else {
            counter++;

            log.LogToTextFile("Log" + std::to_string(numberOfFile) + ".txt", counter, start);

            log.LogToBinaryFile("Log" + std::to_string(numberOfFile) + ".bin", counter, start);
            _sleep(100);
        }
    }

    /*
    std::vector<double> inputVector;
    GenerateRandomInfo(inputVector, 5);

    double inputOneNumber = 16.9323;

    log.LogToTextFile("writeVector.txt", inputVector, start);
    log.LogToTextFile("writeOneNumber.txt", inputOneNumber, start);

    log.LogToBinaryFile("writeVector.bin", inputVector, start);
    log.LogToBinaryFile("writeOneNumber.bin", inputOneNumber, start);

    log.getTextLog("writeVector.txt");
    log.getTextLog("writeOneNumber.txt");

    log.getBinaryLog("writeVector.bin");
    log.getBinaryLog("writeOneNumber.bin");
     */
    return 0;
}
