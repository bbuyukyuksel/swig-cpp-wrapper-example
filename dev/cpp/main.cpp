#include <iostream>
#include <memory>

#include "../library/include/mylib.hpp"

int main(void) {
    Date date{2023, 10, 5};

    MyClass cls;
    std::cout << "MyClass.add(3, 5): ";
    std::cout << cls.add(3, 5) << std::endl;
    std::cout << cls.printDate(date) << std::endl;

    // std::shared_ptr<Date> ptr{ std::make_shared<Date>() };
    auto ptr{ std::make_shared<Date>(1,2,3) };
    std::cout << cls.printDate(ptr) << std::endl;
}