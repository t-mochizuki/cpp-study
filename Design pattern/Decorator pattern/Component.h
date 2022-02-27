#ifndef COMPONENT
#define COMPONENT 1

namespace design {

#include <iostream>

using std::cout;
using std::endl;

class Component {
private:

public:

    Component() {}
    virtual ~Component() {
        cout << "~Component" << endl;
    }

    virtual void operate() {}
};

} // namespace design

#endif // COMPONENT
