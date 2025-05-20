//
//  main.cpp
//  ObserverDemo
//
//  Created by Eswaran, Senthilkumar on 26.5.2022.
//

// Intent: Define a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.


#include <iostream>

#include "Connection.hpp"
#include "AlarmGenerator.hpp"
#include "StatusLogger.hpp"

void demoPubSub()
{
    Connection *connection = new Connection;
    AlarmGenerator alarmGenerator(connection);
    StatusLogger statusLogger(connection);
    
    std::string name;
    std::cout << "Enter to toggle state!";
    while (std::getline (std::cin,name))
    {
        connection->toggleState();
        std::cout << "\nEnter to toggle state!\n";
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    demoPubSub();
    return 0;
}
