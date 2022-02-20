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

void solve() {
    int N; cin >> N;
    map<string, int> m;
    for (int i = 0; i < N; ++i) {
        string S; cin >> S;
        auto it = m.find(S);
        if (it == m.end()) {
            m.insert(make_pair(S, 1));
        }
    }

    cout << m.size() << endl;
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
