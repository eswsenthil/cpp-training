//
//  Connection.hpp
//  ObserverDemo
//
//  Created by Eswaran, Senthilkumar on 26.5.2022.
//

#ifndef Connection_hpp
#define Connection_hpp

#include "Subject.hpp"

#include <string>

class Connection : public Subject {
    std::string mState;
    
public:
    Connection();
    void getState(std::string &outState) {
        outState = mState;
    }
    
    void toggleState();
    
    // Other private functions
};


#endif /* Connection_hpp */
