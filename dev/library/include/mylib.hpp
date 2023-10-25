// MyClass.h
#pragma once

#include <string>
#include <memory>
#include <iostream>

struct Date {
    int year;
    int month;
    int day;

    Date(int year, int month, int day) :
        year{year}, month{month}, day{day}
    { }
};

std::ostream& operator<<(std::ostream& os, const Date& date) {
    return os << date.year << '/' << date.month << '/' << date.day;
}

class MyClass {
public:
    MyClass();
    int add(int a, int b);
    std::string printDate(const Date& date);
    std::string printDate(std::shared_ptr<Date> ptr);   
};


