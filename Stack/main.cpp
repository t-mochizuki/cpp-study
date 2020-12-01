#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <nutshell/stack>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using nutshell::Stack;

void solve() {
    int n; cin >> n;

    int a[100];
    Stack<int> s(a);

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
