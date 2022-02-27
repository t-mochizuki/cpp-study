#ifndef CONCRETE_SUBJECT
#define CONCRETE_SUBJECT 1

#include "Subject.h"

namespace design {

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class ConcreteSubject : public Subject {
private:

    string name;

public:

    ConcreteSubject(string name): name(name) {}
    virtual ~ConcreteSubject() {}

    string getName() { return name; };
};

} // namespace design

#endif // CONCRETE_SUBJECT
