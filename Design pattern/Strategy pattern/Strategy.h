#ifndef STRATEGY
#define STRATEGY 1

namespace design {

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Strategy {
private:

    string name;

public:

    Strategy(): name("") {}
    Strategy(string name): name(name) {}
    virtual ~Strategy() {}

    virtual void interface() {}
};

} // namespace design

#endif // STRATEGY
