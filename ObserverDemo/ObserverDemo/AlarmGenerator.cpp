//
//  AlarmGenerator.cpp
//  ObserverDemo
//
//  Created by Eswaran, Senthilkumar on 26.5.2022.
//

#include "AlarmGenerator.hpp"

#include <iostream>

AlarmGenerator::AlarmGenerator(Connection *connection) :
mConnection(connection)
{
    mConnection->Attach(this);
}

void
AlarmGenerator::Update(Subject* theChangedSubject)
{
    if (mConnection == theChangedSubject)
    {
        generateAlarm();
    }
}

void
AlarmGenerator::generateAlarm()
{
    //
    std::string newState;
    mConnection->getState(newState);
    
    std::cout << "Generating alarm! Connection Status changed! Nww state:" << newState << std::endl;
    
    // Generate Alarm
}
