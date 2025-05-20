//
//  ClassAdapter.cpp
//  DesignPatternsDemo
//
//  Created by Eswaran, Senthilkumar on 25.5.2022.
//

// Convert the interface of a class into another interface clients expect. Adapter lets classes work together that couldn't otherwise because of incompatible interfaces.

#include <stdio.h>

class Adaptee {
public:
    void specificRequest(){}
};

class Target {
public:
    virtual void request(){}
};

class ClassAdapter : public Target, private Adaptee {
    
public:
    virtual void request()
    {
        // Somehow process the Adaptee object and get the expected result.
        // It may not be a direct call like this.
        specificRequest();
        
        // Note: This has also access to the protected members of Adaptee.
    }
};

Target *getClassAdapterTarget()
{
    return new ClassAdapter;
}

void demoClassAdapter()
{
    Target *target = getClassAdapterTarget();
    target->request();
    delete target;
}

// --------

class ObjectAdapter : public Target {
    
    // we can have a object or a pointer
    Adaptee adaptee;
public:
    virtual void request()
    {
        // Somehow process the Adaptee object and get the expected result.
        // It may not be a direct call like this.
        adaptee.specificRequest();
        
        // Note: This has access to only public methods of Adaptee.
    }
};

Target *getObjectAdapterTarget()
{
    return new ObjectAdapter;
}

void demoObjectAdapter()
{
    Target *target = getObjectAdapterTarget();
    target->request();
    delete target;
}


