//
//  main.cpp
//  DemoUniqPointer
//
//  Created by Tester on 12.5.2022.
//

#include <iostream>

class Box {
    
public:
    Box()
    {
        std::cout << "Box constructed" << std::endl;
    }
    
    Box(int x)
    {
        std::cout << "Box param constructed" << std::endl;
    }
    
    ~Box()
    {
        std::cout << "Box destructed" << std::endl;
    }
    
};

void demoUniqPointer()
{
    std::unique_ptr<int> upInt(new int);
    *upInt = 5;
    
    std::cout << "Value at upInt is:" << *upInt << std::endl;
    
    std::unique_ptr<int> upInt1(new int{10});
    std::cout << "Value at upInt1 is:" << *upInt1 << std::endl;
    
    std::unique_ptr<int> upInt2 = std::make_unique<int>(20);
    std::cout << "Value at upInt2 is:" << *upInt2 << std::endl;
    
    std::unique_ptr<int[]> upIntArr = std::make_unique<int[]>(3);
    std::cout << "Value at upIntArr[0] is:" << upIntArr[0] << std::endl;
    
    upIntArr[1] = 15;
    
    std::cout << "Value at upIntArr[1] is:" << upIntArr[1] << std::endl;
    
    std::unique_ptr<Box> upBox = std::make_unique<Box>(5);
}


void demoUpClone()
{
    std::unique_ptr<int> upInt1(new int{10});
    std::cout << "Value at upInt1 is:" << *upInt1 << std::endl;
    
    std::unique_ptr<int> upInt2;
    
    upInt2.swap(upInt1);
    
    std::unique_ptr<int> upInt3 = std::move(upInt2);
    
    upInt3.reset();
    
    int *rp = upInt3.release();
    delete rp;
    
    int *rp1 = upInt1.get();
}

int main(int argc, const char * argv[]) {
    // insert code here...

    demoUniqPointer();
    
    return 0;
}
