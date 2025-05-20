//
//  main.cpp
//  BridgeClient
//
//  Created by Eswaran, Senthilkumar on 25.5.2022.
//

#include <iostream>

#include "MyWindow.hpp"

class OvalWindow : public MyWindow
{
public:
    
};

void demoBridge()
{
    MyWindow *myWindow = new OvalWindow;
    myWindow->writeText();
    delete myWindow;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
