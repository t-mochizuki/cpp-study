// g++ -std=c++14 -DDEV=1 -Wall main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::make_pair;

#define rep(i, n) for (int i = 0; i < (n); ++i)

class Problem {
private:
    int n;
    vector<int> a, b, c;

public:
    Problem() {
        cin >> n;
        a.resize(n);
        rep(i, n) cin >> a[i];
        b.resize(n);
        rep(i, n) cin >> b[i];
        c.resize(n);
        rep(i, n) {
            cin >> c[i];
            c[i]--;
        }
    }

    void solve() {
        map<int, int> m;
        for (auto j : c) {
            map<int, int>::iterator it = m.find(b[j]);
            if (it != m.end()) {
                m[b[j]]++;
            } else {
                m.insert(make_pair(b[j], 1));
            }
        }

        long ans = 0;
        rep(i, n) {
            ans += m[a[i]];
        }
        cout << ans << endl;
    }
};

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        Problem p;
        p.solve();
    }
#else
    Problem p;
    p.solve();
#endif

    return 0;
}
