//
//  main.cpp
//  DemoLambda
//
//  Created by Eswaran, Senthilkumar on 26.5.2022.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

void demoLambda()
{
    std::vector<int> c = {11, 25, 36, 58, 97};
    
    std::cout << "All Numbers in the list: ";
    
    std::for_each(c.begin(), c.end(), [](int i){
        std::cout << i << ' ';
    });
    std::cout << '\n';
    
    std::cout << "Numbers less than 30: ";
    
    int x = 30;
    std::for_each(c.begin(), c.end(), [x](int i){
        if (i < x)
        {
            std::cout << i << ' ';
        }
    });
    std::cout << '\n';
    
    int count = 0;
    std::for_each(c.begin(), c.end(), [x,&count](int i){
        if (i < x)
        {
            ++count;
        }
    });
    std::cout << "Count of numbers less than 30:" << count << std::endl;
}

class Dummy {
    int x = 30;
    int count = 0;
    
public:
    
    void someOp() {
        std::vector<int> c = {11, 25, 36, 58, 97};
        
        std::cout << "All Numbers in the list: ";
        
        std::for_each(c.begin(), c.end(), [](int i){
            std::cout << i << ' ';
        });
        std::cout << '\n';
        
        std::cout << "Numbers less than 30: ";
        
        std::for_each(c.begin(), c.end(), [this](int i){
            if (i < x)
            {
                std::cout << i << ' ';
            }
        });
        std::cout << '\n';
        
        std::for_each(c.begin(), c.end(), [this](int i){
            if (i < x)
            {
                ++count;
            }
        });
        std::cout << "Count of numbers less than 30:" << count << std::endl;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    //demoLambda();
    Dummy d;
    d.someOp();
    return 0;
}
