//
//  MyWindow.cpp
//  SampleBridge
//
//  Created by Eswaran, Senthilkumar on 25.5.2022.
//

#include "MyWindow.hpp"

class MyWindowImp {
    //instance variables
    
public:
    virtual ~MyWindowImp(){}
    virtual void writeText() = 0;
};


class ArialWindowImp : public MyWindowImp {
    //instance variables
    
public:
    void writeText()
    {
        // write text in Arial font.
    }
};

class HelveticaWindowImp : public MyWindowImp {
    //instance variables
    
public:
    void writeText()
    {
        // write text in Helvetica font.
    }
};

// // //


MyWindow::MyWindow() :
    mImp(new ArialWindowImp)
{
    
}

MyWindow::~MyWindow()
{
    delete mImp;
}

void MyWindow::writeText()
{
    mImp->writeText();
}
