//
//  Subject.hpp
//  ObserverDemo
//
//  Created by Eswaran, Senthilkumar on 26.5.2022.
//

#ifndef Subject_hpp
#define Subject_hpp

#include "Observer.hpp"

#include <list>

class Subject {
    
public:
    virtual void Attach(Observer*);
    virtual void Detach(Observer*);
    virtual void Notify();

private:
    std::list<Observer*> _observers;
};

#endif /* Subject_hpp */
