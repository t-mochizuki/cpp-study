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

template<class T> inline T max(T X, T Y) {
    return X > Y ? X : Y;
}

void solve() {
    int N; cin >> N;
    int A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    map<int, int> m; long l = 0; m.insert(make_pair(l, A[l]));
    unsigned long ans = 1;
    for (int r = 1; r < N;) {
        bool found = false;
        for (auto p : m) {
            if (p.second == A[r]) {
                found = true;
                continue;
            }
        }

        if (found) {
            m.erase(l);
            l++;
        } else {
            m.insert(make_pair(r, A[r]));
            ans = max(ans, m.size());
            r++;
        }
    }

    cout << ans << endl;
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
