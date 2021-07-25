#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

// TODO: RETRY

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int n; cin >> n;

    const int range = 100001;
    int v0[range] = {0}, v1[range] = {0};
    int tmp = 0; bool same = true;
    REP(0, i, n) {
        int v; cin >> v;
        if (i == 0) {
            tmp = v;
        }
        if (tmp != v) {
            same = false;
        }
        if (i % 2 == 0) v0[v]++;
        else v1[v]++;
    }

    sort(v0, v0 + range, greater<int>()); sort(v1, v1 + range, greater<int>());

    n /= 2;

    if (same) {
        cout << n << endl;
    } else {
        cout << (n - v0[0]) + (n - v1[0]) << endl;
    }

    return 0;
}
