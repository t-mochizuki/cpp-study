#include <stdio.h>
#include <iostream>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int n, k, q; cin >> n >> k >> q;
    k -= q;

    int a[q];
    REP(0, i, q) {
        cin >> a[i];
        a[i]--;
    }

    int v[n];
    REP(0, i, n) v[i] = k;

    REP(0, i, q) {
        v[a[i]]++;
    }

    REP(0, i, n) {
        cout << (v[i] > 0 ? "Yes" : "No") << endl;
    }

    return 0;
}
