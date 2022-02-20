#include "observer.h"

using namespace design;

void Subject::addObserver(Observer* o) {
    observers.push_back(o);
}

void Subject::removeObserver(Observer* o) {
    // todo
}

void Subject::notifyObserver() {
    for (auto o : observers) {
        o->update(this);
    }
}
