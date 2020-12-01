#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <nutshell/queue>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using nutshell::Queue;

void solve() {
    int n; cin >> n;

    int a[100];
    Queue<int> que(a);

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
