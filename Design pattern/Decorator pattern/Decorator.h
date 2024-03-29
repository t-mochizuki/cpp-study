#ifndef DECORATOR
#define DECORATOR 1

#include "Component.h"

namespace design {

#include <iostream>

using std::cout;
using std::endl;

class Decorator : public Component {
private:

    Component* component;

public:

    Decorator(Component& component): component(&component) {}
    virtual ~Decorator() {
        cout << "~Decorator" << endl;
    }

    virtual void operate() {};
};

} // namespace design

#endif // DECORATOR
