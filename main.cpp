// This is a personal academic project. Dear PVS-Studio, please check it.

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#ifdef _DEBUG
#define DEBUG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else /////из-за этого не работал     int* x = new int[1000];
#define new DBG_NEW
#endif

#include <locale>
#include "reader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "CarInfo.h"  

using namespace std;

int main() {
    {
        _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

        setlocale(0, "");
        std::vector<CarInfo> carList;

        std::ifstream inputFile("D:\\avtomobili.txt");
        if (!inputFile.is_open()) {
            std::cerr << "Error opening the file." << std::endl;
            exit(1);
        }

        try {
            readCarInfo(inputFile, carList);
        }
        catch (const std::exception& e) {
            std::cerr << "Ошибка при чтении CarInfo из файла: " << e.what() << std::endl;
            // Перехват исключения или обработка по необходимости
        }

        displayCarInfo(carList, std::cout);
    }

    int* x = new int[1000];

    _CrtDumpMemoryLeaks();

    return 0;
}