//
//  Decorator.cpp
//  DesignPatternsDemo
//
//  Created by Eswaran, Senthilkumar on 25.5.2022.
//

// Intent: Attach additional responsibilities to an object dynamically. Decorators provide a flexible alternative to subclassing for extending functionality.

// Taken from 
#include <stdio.h>

class VisualComponent {
public:
    VisualComponent();
    virtual void Draw();
    virtual void Resize();
    // . . .
};

class Decorator : public VisualComponent {
public:
    Decorator(VisualComponent*);
    virtual void Draw();
    virtual void Resize();
    // ..-
private:
    VisualComponent* _component;
};

void Decorator::Draw () {
    _component->Draw();
}
void Decorator::Resize () {
    _component->Resize();
}

class BorderDecorator : public Decorator {
public:
    BorderDecorator(VisualComponent*, int borderWidth);
    virtual void Draw(); private:
    void DrawBorder(int);
private:
    int _width;
};

void BorderDecorator::Draw()
{
    Decorator::Draw();
    DrawBorder(_width);
}

class Window
{
    //
    
public:
    void SetContents(VisualComponent *inComponent);
};

void demoDecorator()
{
    Window* window = new Window;
    TextView* textView = new TextView;

    // Without Decorator
    window->SetContents(textView);
    
    // With Decorator
    window->SetContents( new BorderDecorator(new ScrollDecorator(textView)) );

}
