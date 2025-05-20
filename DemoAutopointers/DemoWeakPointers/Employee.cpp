//
//  Employee.cpp
//  DemoWeakPointers
//
//  Created by Tester on 20.5.2022.
//

#include "Employee.hpp"
#include <iostream>

Employee::Employee(std::string_view inName) :
mName(inName)
{
    std::cout << "Employee constructed" << std::endl;
}

Employee::~Employee()
{
    std::cout << "Employee destructed" << std::endl;
}
