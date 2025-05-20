//
//  StatusLogger.hpp
//  ObserverDemo
//
//  Created by Eswaran, Senthilkumar on 26.5.2022.
//

#ifndef StatusLogger_hpp
#define StatusLogger_hpp

#include "Connection.hpp"

class StatusLogger : public Observer {
    Connection *mConnection;
    void logStatus();
public:
    StatusLogger(Connection *connection);
    
    virtual void Update(Subject* theChangedSubject);
};

#endif /* StatusLogger_hpp */
