//
//  Factory.h
//  DesignPatternsDemo
//
//  Created by Eswaran, Senthilkumar on 24.5.2022.
//

#ifndef Factory_h
#define Factory_h

#include <string>

using namespace std;

struct ITable {
    //
};

struct WoodenTable : public ITable {
    
};

struct SteelTable : public ITable {
    
};

struct TableFactory {
    ITable *getTable(string_view type) {
        
        if (type == "steel") {
            return new SteelTable;
        }
        else if (type == "wooden") {
            return new WoodenTable;
        }
        else {
            return nullptr;
        }
    }
};

void demoFactory()
{
    TableFactory tableFactory;
    ITable *tablep = tableFactory.getTable("wooden");
}

#endif /* Factory_h */
