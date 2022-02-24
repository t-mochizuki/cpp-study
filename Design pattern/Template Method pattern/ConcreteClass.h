#ifndef CONCRETE_CLASS
#define CONCRETE_CLASS 1

#include "AbstractClass.h"

namespace design {

#include <iostream>

using std::cout;
using std::endl;

class ConcreteClass : public AbstractClass {
private:

public:

    ConcreteClass() {}
    virtual ~ConcreteClass() {}

    bool preproc() override {
        cout << "ConcreteClass::preproc" << endl;
        return true;
    }
    bool mainproc() override {
        cout << "ConcreteClass::mainproc" << endl;
        return true;
    }
    bool postproc() override {
        cout << "ConcreteClass::postproc" << endl;
        return true;
    }
};

} // namespace design

#endif // CONCRETE_CLASS
