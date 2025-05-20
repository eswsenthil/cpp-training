//
//  main.cpp
//  DemoAutopointers
//
//  Created by Tester on 11.5.2022.
//

#include <iostream>

#include <vector>

class Box {
    
public:
    Box()
    {
        std::cout << "Box constructed" << std::endl;
    }
    
    ~Box()
    {
        std::cout << "Box destructed" << std::endl;
    }
    
};

void demoAutoPointers()
{
    
    //std::auto_ptr<int> apInt;
    int *pInt = new int;
    
    std::auto_ptr<int> apInt(new int);
    
    *pInt = 5;
    
    *apInt = 5;
    
    std::cout << "Value :" << *pInt << std::endl;
    
    std::cout << "Value :" << *apInt << std::endl;
    
    std::cout << "Address pointed to :" << pInt << std::endl;
    
    std::cout << "Address pointed to :" << apInt.get() << std::endl;
    
    std::auto_ptr<int> apInt2;
    apInt2 = apInt;
    
    std::cout << "Address pointed by apInt :" << apInt.get() << std::endl;
    
    std::cout << "Address pointed to apInt2 :" << apInt2.get() << std::endl;
    
    //std::cout << "Value :" << *apInt << std::endl;
    
    std::cout << "Value :" << *apInt2 << std::endl;
    
    *apInt2 = 10;
    
    std::auto_ptr<int> apInt3(apInt2);
    
    std::cout << "Address pointed to apInt2 :" << apInt2.get() << std::endl;
    std::cout << "Address pointed to apInt3 :" << apInt3.get() << std::endl;
    
    std::cout << "Value :" << *apInt3 << std::endl;
    
//    int *rp3 = apInt3.release();
//
//    std::cout << "Address pointed to apInt3 :" << apInt3.get() << std::endl;
//
//    std::cout << "Address pointed to rp3 :" << rp3 << std::endl;
//
//    delete rp3;
    
    
    std::auto_ptr<int> apInt4(new int);
    *apInt4 = 8;
    
    std::cout << "Address pointed to apInt4 :" << apInt4.get() << std::endl;
    std::cout << "Value at ap4 :" << *apInt4 << std::endl;
    
    
    std::auto_ptr<int> apInt5(new int);
    *apInt5 = 12;
    
    std::cout << "Address pointed to apInt5 :" << apInt5.get() << std::endl;
    std::cout << "Value at ap5 :" << *apInt5 << std::endl;
    
    apInt5.reset(apInt4.release());
    
    std::cout << "Address pointed to apInt4 :" << apInt4.get() << std::endl;
    
    std::cout << "Address pointed to apInt5 :" << apInt5.get() << std::endl;
    std::cout << "Value at ap5 :" << *apInt5 << std::endl;
    
}

void demoAutoPointersWithClass()
{
//    Box *box = new Box;
//    
//    if (true)
//    {
//        ///
//        ///
//        return;
//    }
//    
//    delete box;
//
    
    try {
        Box *box = new Box;
        
        
        // ... throws exceptions
        
    } catch () {
        
    }
    
    std::auto_ptr<Box> apBox(new Box);
    
    if (true) {
        return;
    }
}


void demoAutoPtrMistake()
{
    int x = 5;
    int y = x;
    
    std::auto_ptr<int> apX(new int(5));
    
    std::cout << "*apX: " << *apX << std::endl;
    
    std::auto_ptr<int> apY(apX);
    
    std::cout << "*apX: " << *apX << std::endl;
}




void demoWithVector()
{
    std::auto_ptr<int> apX(new int(5));
    
    std::vector<std::auto_ptr<int>> vapi;
    vapi.push_back(apX);
    
    std::vector<std::unique_ptr<int>> vupi;
    std::unique_ptr<int> upX = std::make_unique<int>(5);

    vupi.push_back(upX);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    
    //demoAutoPointers();
    
    //demoAutoPointersWithClass();
    
    demoAutoPtrMistake();
    
    return 0;
}
