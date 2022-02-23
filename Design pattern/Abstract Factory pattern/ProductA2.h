#ifndef PRODUCT_A_2
#define PRODUCT_A_2 1

#include "AbstractProductA.h"

namespace design {

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class ProductA2 : public AbstractProductA {
private:

public:

    ProductA2() {}
    virtual ~ProductA2() {
        cout << "Delete ProductA2" << endl;
    }
};

} // namespace design

#endif // PRODUCT_A_2
