//
//  main.cpp
//  DemoVirtualTable
//
//  Created by Eswaran, Senthilkumar on 27.5.2022.
//

#include <iostream>

class Employee {
public:
    virtual void disp(){}
};

class Developer : public Employee {
};

class Tester : public Employee {
};

void testPointerCasts(Employee *emp)
{
    std::cout << "Passed type is:" << typeid(*emp).name() << std::endl;
    Developer *dev = dynamic_cast<Developer*>(emp);
    if (dev)
    {
        std::cout << "We could get a Developer" << std::endl;
    }
}


void demoPointerCasts()
{
    Employee emp;
    testPointerCasts(&emp);
    
    Tester tester;
    testPointerCasts(&tester);
    
    Developer dev;
    testPointerCasts(&dev);
}

void testReferenceCasts(Employee &emp)
{
    std::cout << "Passed type is:" << typeid(emp).name() << std::endl;
    
    try {
        Developer &dev = dynamic_cast<Developer&>(emp);
        std::cout << "We could get a Developer" << std::endl;
    } catch (std::exception &e) {
        std::cout << "Got exception:" << e.what() << std::endl;
    }
}


void demoReferenceCasts()
{
    Employee emp;
    testReferenceCasts(emp);
    
    Tester tester;
    testReferenceCasts(tester);
    
    Developer dev;
    testReferenceCasts(dev);
}

void explainDynamicCasts()
{
    Employee emp1;
    Employee &emp2 = dynamic_cast<Employee&>(emp1); // side cast
    
    Developer dev1;
    
    Employee &emp3 = dynamic_cast<Employee&>(dev1); // Upcast
    
    
    Developer &dev2 = dynamic_cast<Developer&>(emp1); // Downcast
}

void demoConstCats()
{
    const int MIN = 10;
    
    // Removed constness - some old C/C++ libraries take non-const types as arguments or return types.
    // Then we will have trouble with compiler to pass const vars. Thenn, use const_caat to remove constness.
    int &lowerLimit = const_cast<int&>(MIN);
}

int main(int argc, const char * argv[]) {
    // insert code here...

    //demoPointerCasts();
    
    demoReferenceCasts();
    
    return 0;
}
