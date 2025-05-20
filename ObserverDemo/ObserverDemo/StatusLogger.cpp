//
//  StatusLogger.cpp
//  ObserverDemo
//
//  Created by Eswaran, Senthilkumar on 26.5.2022.
//

#include "StatusLogger.hpp"

#include <iostream>

StatusLogger::StatusLogger(Connection *connection) :
mConnection(connection)
{
    mConnection->Attach(this);
}

void
StatusLogger::Update(Subject* theChangedSubject)
{
    if (mConnection == theChangedSubject)
    {
        logStatus();
    }
}

void
StatusLogger::logStatus()
{
    //
    std::string newState;
    mConnection->getState(newState);
    
    std::cout << "Logging... Connection Status changed! Nww state:" << newState << std::endl;
    
    // Log
}
