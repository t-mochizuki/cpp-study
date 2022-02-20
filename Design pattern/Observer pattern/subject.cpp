#ifndef SUBJECT
#define SUBJECT 1

namespace design {

#include <vector>
#include "observer"

using std::vector;

class Subject {
private:

    vector<Observer*> observers;

public:

    Subject() {
    }

    virtual ~Subject() {}

    void addObserver(Observer* o) {
        observers.push_back(o);
    }

    void removeObserver(Observer* o) {
        // todo
    }

    void notifyObserver() {
        for (auto o : observers) {
            o->update();
        }
    }
};

} // namespace design

#endif // SUBJECT
