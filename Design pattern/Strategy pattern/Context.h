#ifndef CONTEXT
#define CONTEXT 1

#include "Strategy.h"

namespace design {

#include <iostream>

using std::cout;
using std::endl;

class Context {
private:

public:

    Context() {}
    virtual ~Context() {}

    void interface(Strategy& strategy) {
        (&strategy)->interface();
    }
};

} // namespace design

#endif // CONTEXT
