//
//  Connection.cpp
//  ObserverDemo
//
//  Created by Eswaran, Senthilkumar on 26.5.2022.
//

#include "Connection.hpp"

Connection::Connection()
: mState("off")
{
}
void
Connection::toggleState()
{
    if (mState == "off")
    {
        mState = "on";
    }
    else
    {
        mState = "off";
    }
    
    Notify();
}


