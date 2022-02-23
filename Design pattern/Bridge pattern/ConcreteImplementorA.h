#ifndef CONCRETE_IMPLEMENTOR_A
#define CONCRETE_IMPLEMENTOR_A 1

#include "Implementor.h"

namespace design {

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class ConcreteImplementorA : public Implementor {
private:

public:

    ConcreteImplementorA() {}
    virtual ~ConcreteImplementorA() {}

    void operation() override {
        cout << "ConcreteImplementorA" << endl;
    }
};

} // namespace design

#endif // CONCRETE_IMPLEMENTOR_A
