//
//  AbstractFactory.h
//  DesignPatternsDemo
//
//  Created by Eswaran, Senthilkumar on 24.5.2022.
//

#ifndef AbstractFactory_h
#define AbstractFactory_h

struct ITable {
    
};

struct WoodenTable : public ITable {
    
};

struct SteelTable : public ITable {
    
};


struct ITableFactory {
  
    virtual ITable* getTable() = 0;

};

struct SteelTableFactory : public ITableFactory
{
    ITable *getTable() {
        return new SteelTable;
    }
};

struct WoodenTableFactory : public ITableFactory
{
    ITable *getTable() {
        return new WoodenTable;
    }
};


ITable *getTable(string_view type)
{
    ITableFactory *tableFactory;
    if (type == "steel") {
        tableFactory = new SteelTableFactory;
    }
    else if (type == "wooden") {
        tableFactory = new WoodenTableFactory;
    }
    else {
        return nullptr;
    }
    
    return tableFactory->getTable();
}

#endif /* AbstractFactory_h */
