#include <stdio.h>
#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::priority_queue;
using std::sort;
using std::greater;
using std::vector;

void solve() {
    long X, Y, A, B, C; cin >> X >> Y >> A >> B >> C;
    long p[A];
    for (int i = 0; i < A; ++i) {
        cin >> p[i];
    }
    sort(p, p + A, greater<long>());

    long q[B];
    for (int i = 0; i < B; ++i) {
        cin >> q[i];
    }
    sort(q, q + B, greater<long>());

    long r[C];
    for (int i = 0; i < C; ++i) {
        cin >> r[i];
    }
    sort(r, r + C, greater<long>());

    priority_queue<
        long,
        vector<long>,
        greater<long> > quex;
    for (int i = 0; i < X; ++i) {
        quex.push(p[i]);
    }

    priority_queue<
        long,
        vector<long>,
        greater<long> > quey;
    for (int i = 0; i < Y; ++i) {
        quey.push(q[i]);
    }

    for (int i = 0; i < C; ++i) {
        int x = quex.top();
        int y = quey.top();
        if (x > y) {
            if (r[i] > y) {
                quey.pop();
                quey.push(r[i]);
            } else {
                break;
            }
        } else {
            if (r[i] > x) {
                quex.pop();
                quex.push(r[i]);
            }
        }
    }

    long ans = 0;
    for (int i = 0; i < X; ++i) {
        ans += quex.top(); quex.pop();
    }
    for (int i = 0; i < Y; ++i) {
        ans += quey.top(); quey.pop();
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
