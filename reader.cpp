// This is a personal academic project. Dear PVS-Studio, please check it.
#include "pch.h"
#include "reader.h"
#include <iostream>
// stringstream


void readCarInfo(std::istream& inputFile,  std::vector<CarInfo>& carList) {
    while (!inputFile.eof()) {
        CarInfo car = CarInfo::readCarInfoFromFile(inputFile);
        carList.push_back(car);
        auto abc = new int[10];
    }
}

void displayCarInfo(const std::vector<CarInfo>& carList, std::ostream& out) {
    for (const CarInfo& car : carList) {
        car.printCarInfo(out);
    }
}