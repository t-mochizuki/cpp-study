#include "observer.h"
#include "subject.h"

using namespace design;

Observer::Observer() {}
Observer::~Observer() {
    cout << "Delete an observer" << endl;
}

void Observer::update(Subject* s) {
  cout << "Observer" << endl;
}
