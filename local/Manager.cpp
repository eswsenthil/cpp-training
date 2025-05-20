//
//  Manager.cpp
//  DemoWeakPointers
//
//  Created by Eswaran, Senthilkumar on 19.5.2022.
//

#include "Manager.hpp"
#include "Employee.hpp"

#include <iostream>

Manager::Manager(std::string_view inName) :
mName(inName)
{
    std::cout << "Manager constructed" << std::endl;
}

Manager::~Manager()
{
    std::cout << "Manager destructed" << std::endl;
}

void
Manager::printInfo()
{
    std::shared_ptr<Employee> spEmployee(mEmployee.lock());
    if (spEmployee)
    {
        std::cout << "Employee of " << mName << " is " << spEmployee->mName << std::endl;
    }
}
