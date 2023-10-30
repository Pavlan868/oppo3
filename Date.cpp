#include "pch.h"
#include "Date.h"
#include <iostream>

Date::Date()
    : day(0)
    , month(0)
    , year(0)
{}

Date::Date(int day, int month, int year)
    : day(day)
    , month(month)
    , year(year)
{}

bool Date::isValid() const
{
    return isDateValid(*this);
}

void Date::print(std::ostream& out) const {
    out << day << "." << month << "." << year;
}

Date Date::create_from_stream(std::istream& stream) {
    Date result;
    char separator;

    if (!(stream >> result.day)) {
        std::cerr << "������: �� ������� ������� ����." << std::endl;
        return Date(); // ���������� ��������� �������� Date (0.0.0)
    }

    if (!(stream >> separator) || separator != '.') {
        std::cerr << "������: ����������� ���� ������ ���� ������." << std::endl;
        // ��������� ������������ ����������� � ��������� ��������� ����
        stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return create_from_stream(stream); // ����������� ����� ��� ���������� ����
    }

    if (!(stream >> result.month)) {
        std::cerr << "������: �� ������� ������� �����." << std::endl;
        return Date(); // ���������� ��������� �������� Date (0.0.0)
    }

    if (!(stream >> separator) || separator != '.') {
        std::cerr << "������: ����������� ���� ������ ���� ������." << std::endl;
        stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return create_from_stream(stream);
    }

    if (!(stream >> result.year)) {
        std::cerr << "������: �� ������� ������� ���." << std::endl;
        return Date(); // ���������� ��������� �������� Date (0.0.0)
    }

    if (!isDateValid(result)) {
        std::cerr << "������: ������������ ����." << std::endl;
        return Date(); // ���������� ��������� �������� Date (0.0.0)
    }

    // ���� ��������� ����� �� ���� �����, ������, ���� �����
    return result;
}

bool Date::isDateValid(const Date& date) {
    if (date.month < 1 || date.month > 12)
        return false;

    if (date.day < 1)
        return false;

    if (date.month == 2) {
        if (date.year % 4 == 0) {
            if (date.day > 29)
                return false;
        }
        else {
            if (date.day > 28)
                return false;
        }
    }
    else if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) {
        if (date.day > 30)
            return false;
    }
    else {
        if (date.day > 31)
            return false;
    }

    return true;
}