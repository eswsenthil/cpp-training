//
//  Singleton.cpp
//  DesignPatternsDemo
//
//  Created by Eswaran, Senthilkumar on 25.5.2022.
//

#include <stdio.h>

// Singleton

struct Database {

protected:
    // Constructor should not be public.
    Database() {}
    
public:
    // Need to provide a static getter for the instance of this class.
    // Pointer or Reference should be the return type.
    static Database& get()
    {
        // thread-safe since C++11
        static Database database;
        return database;
    }
    
    // Should not allow copy or assignment
    Database(Database const&) = delete;
    Database(Database&&) = delete;
    Database& operator=(Database const&) = delete;
    Database& operator=(Database &&) = delete;
};

void demoSingleton()
{
    // Use Reference to get the instance.
    Database& db = Database::get();
    
    // Not recommended as UT cannot be done.
}
