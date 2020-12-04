#include <stdio.h>
#include <iostream>
#include <fstream>
#include <nutshell/maxheap>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using nutshell::MaxHeap;

void solve() {
    int n; cin >> n;

    int a[100];
    MaxHeap<int> h(0, a);

    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        h.insert(x);
    }

    h.print();
    cout << h.extract() << endl;
    h.print();
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
