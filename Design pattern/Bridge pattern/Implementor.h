#ifndef IMPLEMENTOR
#define IMPLEMENTOR 1

namespace design {

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Implementor {
private:

    string name;

public:

    Implementor() {}
    virtual ~Implementor() {}

    virtual void operation() {
        cout << "Implementor" << endl;
    }
};

} // namespace design

#endif // IMPLEMENTOR
