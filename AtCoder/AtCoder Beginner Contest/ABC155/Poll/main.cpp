#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::map;
using std::make_pair;
using std::pair;

template<class T> inline T max(T X, T Y) {
    return X > Y ? X : Y;
}

void solve() {
    int N; cin >> N;
    map<string, int> m;
    int x = 1;
    for (int i = 0; i < N; ++i) {
        string S; cin >> S;
        decltype(m)::iterator it = m.find(S);
        if (it != m.end()) {
            m[S]++;
            x = max(x, m[S]);
        } else {
            m.insert(make_pair(S, 1));
        }
    }

    for (pair<string, int> p : m) {
        if (p.second == x) {
            cout << p.first << endl;
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
