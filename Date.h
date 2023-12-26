
#pragma once
#include "main.h"
#include <iostream>

struct Date {
    Date(); // Объявление конструктора
    Date(int day, int month, int year);
    bool isValid() const;

    void print(std::ostream& out) const;
    static Date create_from_stream(std::istream& stream);

    // Add the declaration for isDateValid
    // 
    //    static inline bool isDateValid(const Date& date);
    static bool isDateValid(const Date& date);

    int day;
    int month;
    int year;
};
