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

class Stack {
public:
    int top = -1;
    int* _a = NULL;

    Stack(int* a): _a(a) {};
    Stack(const Stack&) = default;
    Stack& operator=(const Stack&) = delete;

    void push(int x) {
        _a[++top] = x;
    }

    int pop() {
        return _a[top--];
    }

    int peak() {
        return _a[top];
    }

    bool empty() {
        return top == -1;
    }

    int size() {
        return top + 1;
    }
};

void solve() {
    int n; cin >> n;

    int a[100];
    Stack s = Stack(a);

    string q;
    for (int i = 0; i < n; ++i) {
        cin >> q;

        if (q == "push") {
            int x; cin >> x;
            s.push(x);
        } else if (q == "pop") {
            cout << s.pop() << endl;
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
