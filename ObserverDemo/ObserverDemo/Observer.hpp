//
//  Observer.hpp
//  ObserverDemo
//
//  Created by Eswaran, Senthilkumar on 26.5.2022.
//

//

#ifndef Observer_hpp
#define Observer_hpp

#include <stdio.h>

// Forward Declaration
class Subject;

class Observer {
public:
    virtual void Update(Subject* theChangedSubject) = 0;
};


#endif /* Observer_hpp */
