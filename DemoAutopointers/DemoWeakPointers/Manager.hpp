//
//  Manager.hpp
//  DemoWeakPointers
//
//  Created by Tester on 20.5.2022.
//

#ifndef Manager_hpp
#define Manager_hpp

#include <stdio.h>


#include <string>

// Class Forward Declaration
class Employee;

class Manager {
    
public:
    Manager(std::string_view inName);
    ~Manager();
    
    void printInfo();
    
    std::string mName;
    
    std::weak_ptr<Employee> mEmployee;
    
};


#endif /* Manager_hpp */
