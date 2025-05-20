

#include <iostream>

struct ABC
{
    int dataNum;
};

void print(int n)
{
    std::cout << "Value of n is:" << n << std::endl;
}

void print(ABC *inAbc)
{
    if (inAbc)
    {
        std::cout << "Value of ABC is:" << inAbc->dataNum << std::endl;
    }
}



int main(int argc, const char * argv[]) {
    
    print(3);
    
    ABC x = { 5 };
    
    print(&x);
    
    ABC *pAbc = NULL;
    print(pAbc);
    
    ABC *pXyz = nullptr;
    print(pXyz);
    
    print(nullptr);
    
    //print(NULL);
    
    return 0;
}
