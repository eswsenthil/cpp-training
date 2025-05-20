//
//  main.cpp
//  DemoSharedPointers
//
//  Created by Tester on 19.5.2022.
//

#include <iostream>

#include <vector>

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

void demoRaii()
{
    std::unique_ptr<Box> upBox = std::make_unique<Box>();
    
    upBox.reset();
    
    std::cout << "Moving on to shared ptr" << std::endl;
    
    std::shared_ptr<Box> spBox = std::make_shared<Box>();
    
    std::shared_ptr<Box> spBoxB = spBox;
    
    spBox.reset();
    std::cout << "Moving on.." << std::endl;
    
}

void demoSharedPointers()
{
    std::shared_ptr<int> spCount1 = std::make_shared<int>(5);
    
    std::cout << "Address pointed by spCount1: " << spCount1.get() << std::endl;
    
    std::cout << "Value at spCount1: " << *spCount1 << std::endl;
    
    std::cout << "use count of spCount1: " << spCount1.use_count() << std::endl;
    
    std::shared_ptr<int> spCount2 = spCount1;
    
    std::cout << "use count of spCount1: " << spCount1.use_count() << std::endl;
    
    std::cout << "use count of spCount2: " << spCount2.use_count() << std::endl;
    
    spCount1.reset();
    
    std::cout << "use count of spCount1: " << spCount1.use_count() << std::endl;
    
    std::cout << "use count of spCount2: " << spCount2.use_count() << std::endl;
    
}

void demoSharedPointersWithVector()
{
    std::vector<int> vi;
    vi.push_back(5);
    
    std::vector<int*> vip;
    vip.push_back(new int(5));
    
//    std::unique_ptr<Box> upBox = std::make_unique<Box>();
//    std::vector<std::unique_ptr<Box>> vupb;
//    vupb.push_back(upBox);
    
    std::shared_ptr<Box> spBox = std::make_shared<Box>();
    std::vector<std::shared_ptr<Box>> vspb;
    vspb.push_back(spBox);
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //demoSharedPointers();
    //demoRaii();
    demoSharedPointersWithVector();
    return 0;
}
