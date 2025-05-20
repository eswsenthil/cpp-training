//
//  main.cpp
//  DemoWeakPointers
//
//  Created by Tester on 20.5.2022.
//

#include <iostream>

#include "Manager.hpp"
#include "Employee.hpp"

void demoSharedPointers()
{
    std::shared_ptr<Manager> manager = std::make_shared<Manager>("Akilan");
 
    std::shared_ptr<Employee> employee = std::make_shared<Employee>("Vetri");
    
    std::cout << "Use count of Manager: " << manager.use_count() << std::endl;
    std::cout << "Use count of Employee: " << employee.use_count() << std::endl;
    
    manager->mEmployee = employee;
    employee->mManager = manager;
    
    std::cout << "Use count of Manager: " << manager.use_count() << std::endl;
    std::cout << "Use count of Employee: " << employee.use_count() << std::endl;
    
    manager->printInfo();
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    demoSharedPointers();
    
    return 0;
}
