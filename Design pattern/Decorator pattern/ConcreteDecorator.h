#ifndef CONCRETEDECORATOR
#define CONCRETEDECORATOR 1

#include "Decorator.h"

namespace design {

#include <iostream>

using std::cout;
using std::endl;

class ConcreteDecorator : public Decorator {
private:

    Component* component;

public:

    ConcreteDecorator(Component& component): Decorator(component), component(&component) {}
    virtual ~ConcreteDecorator() {
        cout << "~ConcreteDecorator" << endl;
    }

    void operate() override {
        cout << "ConcreteDecorator::operate" << endl;
        this->component->operate();
    };
};

} // namespace design

#endif // CONCRETEDECORATOR
