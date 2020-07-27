#include <stdio.h>
#include <iostream>
#include <fstream>
#include <map>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::map;
using std::make_pair;

void solve() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<int, long> m;
    for (int i = 0; i < n; ++i) {
        map<int, long>::iterator it = m.find(a[i]);
        if (it != m.end()) {
            m[a[i]]++;
        } else {
            m.insert(make_pair(a[i], 1));
        }
    }

    long s = 0;
    for (map<int, long>::iterator it = m.begin(); it != m.end(); ++it) {
        s += (it->second * (it->second - 1)) / 2;
    }

    for (int i = 0; i < n; ++i) {
        long y = 0;
        y = s - (m[a[i]] - 1);
        cout << y << endl;
    }
}

int main() {

#ifdef DEV
    std::ifstream in("Banned K.input");
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
