//
//  Subject.cpp
//  ObserverDemo
//
//  Created by Eswaran, Senthilkumar on 26.5.2022.
//

#include "Subject.hpp"


void Subject::Attach (Observer* o) {
    _observers.push_back(o);
}

void Subject::Detach (Observer* o) {
    _observers.remove(o);
}

void Subject::Notify () {
    //std::list<Observer*>::iterator i(_observers);
    for (Observer *observer : _observers)
    {
        observer->Update(this);
    }
}
