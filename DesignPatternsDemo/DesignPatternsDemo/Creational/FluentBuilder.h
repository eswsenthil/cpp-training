//
//  FluentBuilder.h
//  DesignPatternsDemo
//
//  Created by Eswaran, Senthilkumar on 24.5.2022.
//

#ifndef FluentBuilder_h
#define FluentBuilder_h

struct FluentHeadBuilder {
    
    FluentHeadBuilder& createHead();
    FluentHeadBuilder& addHairs();
    FluentHeadBuilder& addEyes();
    FluentHeadBuilder& addNose();
    FluentHeadBuilder& addEars();
    FluentHeadBuilder& addLips();
    
    Head& getHead();
};

void demoFluentBuilder()
{
    FluentHeadBuilder fluentHeaderBuilder;
    fluentHeaderBuilder.createHead()
    .addHairs()
    .addEyes()
    .addNose()
    .addEars()
    .addLips();
    
    Head head = fluentHeaderBuilder.getHead();
    
}


#endif /* FluentBuilder_h */
