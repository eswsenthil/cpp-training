//
//  main.cpp
//  CompositeDemo
//
//  Created by Eswaran, Senthilkumar on 25.5.2022.
//

#include <iostream>


// Intent: Compose objects into tree structures to represent part-whole hierarchies. Com- posite lets clients treat individual objects and compositions of objects uniformly.
//

#include <string>
#include <vector>

#include <iostream>

using namespace std;

class Employee {
    vector<Employee*> mSubOrdinates;

public:
    string mName;
    
    Employee(string_view inName) :
    mName(inName)
    {
        
    }
    
    virtual void shareNews(string_view inNews) const
    {
        for(const auto& subOrd : mSubOrdinates)
        {
            cout << mName << " sharing to " << subOrd->mName << endl;
            subOrd->shareNews(inNews);
        }
    }
    
    virtual void add(Employee *emp)
    {
        mSubOrdinates.push_back(emp);
    }
};

class FullTimeEmployee : public Employee
{
public:
    FullTimeEmployee(string_view inName):
    Employee(inName)
    {
    }
};

class PartTimeEmployee : public Employee
{
public:
    PartTimeEmployee(string_view inName):
    Employee(inName)
    {
    }
};

class CEO : public Employee
{
    // Personal Assistant
    Employee *mPA;
public:
    CEO(string_view inName, Employee *inPA):
    Employee(inName),
    mPA(inPA)
    {
    }
    
    virtual void shareNews(string_view inNews) const
    {
        cout << mName << " sharing to " << mPA->mName << endl;
        mPA->shareNews(inNews);
        
        Employee::shareNews(inNews);
    }
};

void demoComposite()
{
    Employee pa("Sheela");
    
    CEO ceo("Ratan Tata", &pa);
    
    FullTimeEmployee director1("Venkat");
    PartTimeEmployee director2("Ramprasad");
    
    PartTimeEmployee vp("Sampath");
    
    director2.add(&vp);
    
    ceo.add(&director1);
    ceo.add(&director2);
    
    ceo.shareNews("We are declared best partner of the year!");
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    demoComposite();
    
    return 0;
}
