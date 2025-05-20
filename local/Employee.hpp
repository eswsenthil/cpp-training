//
//  Employee.hpp
//  DemoWeakPointers
//
//  Created by Eswaran, Senthilkumar on 19.5.2022.
//

#ifndef Employee_hpp
#define Employee_hpp

#include <string>
#include <string_view>

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
