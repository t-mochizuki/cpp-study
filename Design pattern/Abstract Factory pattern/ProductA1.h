#ifndef PRODUCT_A_1
#define PRODUCT_A_1 1

#include "AbstractProductA.h"

namespace design {

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class ProductA1 : public AbstractProductA {
private:

public:

    ProductA1() {}
    virtual ~ProductA1() {
        cout << "Delete ProductA1" << endl;
    }
};

} // namespace design

#endif // PRODUCT_A_1
