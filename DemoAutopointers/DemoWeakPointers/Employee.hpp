//
//  Employee.hpp
//  DemoWeakPointers
//
//  Created by Tester on 20.5.2022.
//

#ifndef Employee_hpp
#define Employee_hpp

#include <stdio.h>


#include <string>
#include <string_view>

// Forward class Declaration
class Manager;

class Employee {
    
public:
    Employee(std::string_view inName);
    ~Employee();
    
    void printInfo();
    
    std::string mName;
    
    std::weak_ptr<Manager> mManager;
    
};

#endif /* Employee_hpp */
