#ifndef CONCRETE_STRATEGY
#define CONCRETE_STRATEGY 1

#include "Strategy.h"

namespace design {

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class ConcreteStrategy : public Strategy {
private:

    string name;

public:

    ConcreteStrategy(): name("") {}
    ConcreteStrategy(string name): name(name) {}
    virtual ~ConcreteStrategy() {}

    void interface() override {
        cout << name << endl;
    }
};

} // namespace design

#endif // CONCRETE_STRATEGY
