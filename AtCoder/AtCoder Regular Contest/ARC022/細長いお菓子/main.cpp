#include <stdio.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <set>

#define DEV 1
#define TEST 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::queue;
using std::set;

template<class T> inline T max(T X, T Y) {
    return X > Y ? X : Y;
}

void solve() {
#ifdef TEST
    int N; N = 100000;
    int A[N];
    for (int i = 1; i <= N; ++i) {
        A[i] = i;
    }
#else
    int N; cin >> N;
    int A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
#endif

    queue<int> que; que.push(A[0]);
    set<int> s; s.insert(A[0]);
    unsigned long ans = 1;
    for (int r = 1; r < N;) {
        decltype(s)::iterator it = s.find(A[r]);

        if (it != s.end()) {
            int v = que.front(); que.pop();
            s.erase(v);
        } else {
            que.push(A[r]);
            s.insert(A[r]);
            ans = max(ans, s.size());
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
