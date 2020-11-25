#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;

class Queue {
public:
    int head = 0;
    int tail = 0;
    int* _a = NULL;

    Queue(int* a): _a(a) {}
    Queue(const Queue&) = default;
    Queue& operator=(const Queue&) = delete;

    void enqueue(int x) {
        _a[tail++] = x;
    }

    int dequeue() {
        return _a[head++];
    }

    bool empty() {
        return head == tail;
    }
};

void solve() {
    int n; cin >> n;

    int a[100];
    Queue que = Queue(a);

    string q;
    for (int i = 0; i < n; ++i) {
        cin >> q;

        if (q == "enqueue") {
            int x; cin >> x;
            que.enqueue(x);
        } else if (q == "dequeue") {
            cout << que.dequeue() << endl;
        } else {
            terminate();
        }
    }
}

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve();
    }
#else
    solve();
#endif

    return 0;
}
