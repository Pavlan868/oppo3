#include <locale>
#include "reader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "CarInfo.h"  

using namespace std;

int main() {
    setlocale(0, "");
    std::vector<CarInfo> carList;

    std::ifstream inputFile("D:\\avtomobili.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        exit(1);
    }

    readCarInfo(inputFile, carList);
    displayCarInfo(carList, std::cout);
    return 0;
}