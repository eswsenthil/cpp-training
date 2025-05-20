//
//  Employee.cpp
//  DemoWeakPointers
//
//  Created by Eswaran, Senthilkumar on 19.5.2022.
//

#include "Employee.hpp"

#include "Manager.hpp"

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

void
Employee::printInfo()
{
    std::shared_ptr<Manager> manager(mManager.lock());
    if (manager)
    {
        std::cout << "Manager of " << mName << " is " << manager->mName << std::endl;
    }
}

