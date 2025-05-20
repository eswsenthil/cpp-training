//
//  MyWindow.hpp
//  SampleBridge
//
//  Created by Eswaran, Senthilkumar on 25.5.2022.
//

// Intent: Decouple an abstraction from its implementation so that the two can vary independently.


#ifndef MyWindow_hpp
#define MyWindow_hpp

#include <stdio.h>

// Forward Declaration
class MyWindowImp;

class MyWindow {
    
    // This "Has-A" relationship is the Bridge.
    MyWindowImp *mImp;
    
    // MyWindow can have sub-classes independently.
    // MyWindowImp can have sub-classes independently.
    
    
public:
    MyWindow();
    virtual ~MyWindow();
    
    virtual void writeText();
};


#endif /* MyWindow_hpp */
