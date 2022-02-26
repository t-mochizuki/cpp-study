#ifndef CREATOR
#define CREATOR 1

#include "Product.h"

namespace design {

#include <iostream>

using std::cout;
using std::endl;

class Creator {
private:

public:

    Creator() {}
    virtual ~Creator() {}

    void operation() {
        auto product = factoryMethod();
        product->something();
    }

    virtual Product* factoryMethod() {
        return NULL;
    }
};

} // namespace design

#endif // CREATOR
