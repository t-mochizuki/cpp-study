#include <stdio.h>
#include <iostream>
#include <fstream>
#include <queue>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::queue;

void solve() {
    long k; cin >> k;
    queue<long> que;
    for (int i = 1; i <= 9; ++i) {
        que.push(i);
    }

    for (int i = 1; i <= k; ++i) {
        long x = que.front(); que.pop();

        if (i == k) {
            cout << x << endl;
        }

        if (x % 10 != 0) {
            que.push(10 * x + x % 10 - 1);
        }

        que.push(10 * x + x % 10);

        if (x % 10 != 9) {
            que.push(10 * x + x % 10 + 1);
        }
    }

}

int main() {

#ifdef DEV
    std::ifstream in("AtCoder/ABC161/Lunlun Number.input");
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
