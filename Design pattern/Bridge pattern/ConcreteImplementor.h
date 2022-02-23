#ifndef CONCRETE_IMPLEMENTOR
#define CONCRETE_IMPLEMENTOR 1

#include "Implementor.h"

namespace design {

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class ConcreteImplementor : public Implementor {
private:

public:

    ConcreteImplementor() {}
    virtual ~ConcreteImplementor() {}

    void operation() override {
        cout << "ConcreteImplementor" << endl;
    }
};

} // namespace design

#endif // CONCRETE_IMPLEMENTOR
