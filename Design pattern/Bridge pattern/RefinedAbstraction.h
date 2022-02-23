#ifndef REFINED_ABSTRACTION
#define REFINED_ABSTRACTION 1

#include "Abstraction.h"

namespace design {

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class RefinedAbstraction : public Abstraction {
private:

    Implementor* imp;

public:

    RefinedAbstraction(Implementor& imp): Abstraction(imp), imp(&imp) {}
    virtual ~RefinedAbstraction() {}
};

} // namespace design

#endif // REFINEDABSTRACTION
