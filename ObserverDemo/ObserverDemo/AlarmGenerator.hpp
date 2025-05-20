//
//  AlarmGenerator.hpp
//  ObserverDemo
//
//  Created by Eswaran, Senthilkumar on 26.5.2022.
//

#ifndef AlarmGenerator_hpp
#define AlarmGenerator_hpp

#include "Connection.hpp"

class AlarmGenerator : public Observer {
    Connection *mConnection;
    void generateAlarm();
public:
    AlarmGenerator(Connection *connection);
    
    virtual void Update(Subject* theChangedSubject);
};

#endif /* AlarmGenerator_hpp */
