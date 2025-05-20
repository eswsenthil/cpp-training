#include <iostream>

#include <string>

class Light
{
    // ON / OFF
    bool mState;
    
    std::string mName;
    
    char *mpColorName;
    
    int watts;
    
public:
    
    // Constructor
    Light() :
        mState(false),
        mName("Hall/Light"),
        mpColorName(nullptr) // NULL
    {
        
        //mState = false;
        std::cout << __func__ << std::endl;
        
        mpColorName = new char[20];
    }
    
    Light(bool inState, std::string inName = "None") :
    mState(inState),
    mName(inName)
    {
        
    }
    
    
    // Destructor
    ~Light() {
        std::cout << __func__ << std::endl;
        
        delete[] mpColorName;
    }
    
    void printState() {
        
        std::cout << this->mName << " is " << (this->mState ? "ON" : "OFF") << std::endl;
        
        std::cout << mName << " is " << (mState ? "ON" : "OFF") << std::endl;
        
    }
    
    void set(int watts)
    {
        this->watts = watts;
    }
};

void demoDefaultConstruction()
{
    class Xyz {
    public:
        
    };
    class Abc {
        int x;
        Xyz xyz;
    public:
        void display() {
            
        }
    };

    Abc abc;
}


void demoConstructors() {

    Light light;
    
    light.printState();
    
    Light kitchenLight(false, "Kitchen Light");
    
    Light corridorLight(false);
}

void demoConstructorsWithPointers() {

    Light *pLight;
    
    pLight = new Light;
    
    pLight->printState();
    
    delete pLight;
    
}


int main(int argc, const char * argv[]) {
    
    //demoConstructors();
    
    demoConstructorsWithPointers();
    
    return 0;
}
