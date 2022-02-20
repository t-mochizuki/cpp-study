#include "observer.h"
#include "subject.h"

using namespace design;

Observer::Observer() {}
Observer::~Observer() {}

void Observer::update(Subject* s) {
  cout << "Observer" << endl;
}
