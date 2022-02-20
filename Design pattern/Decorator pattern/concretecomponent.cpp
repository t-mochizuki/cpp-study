#include <iostream>
#include "concretecomponent.h"

using std::cout;
using std::endl;

using namespace design;

void ConcreteComponent::operate() {
    cout << "ConcreteComponent::operate" << endl;
}
