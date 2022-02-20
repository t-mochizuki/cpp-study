#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int min(int X, int Y) {
    return X < Y ? X : Y;
}

int main() {
    int X, Y, Z, K; cin >> X >> Y >> Z >> K;
    long A[X], B[Y], C[Z];
    REP(0, i, X) cin >> A[i];
    REP(0, i, Y) cin >> B[i];
    REP(0, i, Z) cin >> C[i];

    vector<long> v;
    REP(0, i, X) REP(0, j, Y) {
        v.push_back(A[i] + B[j]);
    }

    sort(v.begin(), v.end(), greater<long>());

    vector<long> w;
    REP(0, i, min(3000, v.size())) {
        REP(0, j, Z) {
            w.push_back(v[i] + C[j]);
        }
    }

    sort(w.begin(), w.end(), greater<long>());

    REP(0, i, K) cout << w[i] << endl;

    return 0;
}
