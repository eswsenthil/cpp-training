//
//  Builder.h
//  DesignPatternsDemo
//
//  Created by Eswaran, Senthilkumar on 24.5.2022.
//

#ifndef Builder_h
#define Builder_h

struct Hairs {
    
};

struct Eyes {
    
};

struct Nose {
    
};

struct Ears {
    
};

struct Lips {
    
};

struct Head {
  
};

struct HeadBuilder {
    
    void createHead();
    void addHairs();
    void addEyes();
    void addNose();
    void addEars();
    void addLips();
    
    Head getHead();
};

// Simple Builder
void demoBuilder()
{
    HeadBuilder headBuilder;
    headBuilder.createHead();
    headBuilder.addHairs();
    headBuilder.addEyes();
    headBuilder.addNose();
    headBuilder.addEars();
    headBuilder.addLips();
    
    Head head = headBuilder.getHead();
}


    


#endif /* Builder_h */
