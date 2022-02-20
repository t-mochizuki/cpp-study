#include <iostream>
#include "concretedecorator.h"

using std::cout;
using std::endl;

using namespace design;

void ConcreteDecorator::operate() {
    cout << "ConcreteDecorator::operate" << endl;
    this->component->operate();
}
