#include "../include/mylib.hpp"

#include <sstream>


MyClass::MyClass() {
}

int MyClass::add(int a, int b) {
    return a + b;
}

std::string MyClass::printDate(const Date& date) {
    using namespace std;
    stringstream ss;
    ss << "std::string MyClass::printDate(const Date& date)\n";
    ss << date.year << '/' << date.month << '/' << date.day;
    return ss.str();
}

std::string MyClass::printDate(std::shared_ptr<Date> ptr) {
    using namespace std;
    stringstream ss;
    ss << "std::string MyClass::printDate(std::shared_ptr<Date> ptr)\n";
    ss << ptr->year << '/' << ptr->month << '/' << ptr->day;
    return ss.str(); 
}
