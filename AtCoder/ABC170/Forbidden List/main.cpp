#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::sort;
using std::find;
using std::vector;

template<class T> inline T min(T X, T Y) {
    return X < Y ? X : Y;
}

template<class T> inline T abs(T X) {
    return X > 0 ? X : -X;
}

void solve() {
    int x, n; cin >> x >> n;
    if (n == 0) {
        cout << x << endl;
        return ;
    }

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());

    int y = 102; int ans = 0;
    for (int i = 0; i <= 101; ++i) {
        auto it = find(p.begin(), p.end(), i);
        if (it == p.end()) {
            if (y > abs(x - i)) {
                y = abs(x - i);
                ans = i;
            }
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
