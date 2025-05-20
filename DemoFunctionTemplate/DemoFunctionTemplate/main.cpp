//
//  main.cpp
//  DemoFunctionTemplate
//
//  Created by Tester on 5.5.2022.
//

#include <iostream>


template<class T>
class auto_ptr
{
public:
    T *mp;
    auto_ptr()
    {
        mp = nullptr;
    }
    
    ~auto_ptr()
    {
        delete mp;
        mp = nullptr;
    }
    
    auto_ptr(T *p)
    {
        mp = p;
    }
    
    void release()
    {
        delete mp;
        mp = nullptr;
    }
    
    T* get()
    {
        return mp;
    }
    
};



template<class T>
class Calculator
{
public:
    T mt;
    Calculator(T t):
    mt(t)
    {
    }
};

void demoClassTemplates()
{
    Calculator<int> cal(5);
    
    
    
}

void demoConstructorsWithPointers() {

    int *pInt = new int;
    
    auto_ptr<int> ap(pInt);
}

template<class T>
void print(T t)
{
    std::cout << t << std::endl;
}

void demoFunctionTemplate()
{
    print(5);
    
    print(5.0);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    demoFunctionTemplate();
    
    return 0;
}
