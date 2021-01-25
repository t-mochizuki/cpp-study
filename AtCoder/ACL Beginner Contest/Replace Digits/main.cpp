#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::stol;

const long MOD = 998244353;

void solve() {
    int N, Q; cin >> N >> Q;

    string s;
    for (int i = 0; i < N; ++i) {
        s.push_back('1');
    }

    for (int i = 0; i < Q; ++i) {
        int L, R; cin >> L >> R;
        L--;
        char D; cin >> D;
        s.replace(L, R-L, R-L, D);

        // 除算
        long v = 0L;
        string t;
        for (int i = 0; i < N; ++i) {
            t = s.substr(i, 1);
            v *= 10L;
            v += stol(t);
            v %= MOD;
        }

        cout << v << endl;
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
