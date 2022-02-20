#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int N; cin >> N;
    int A[N]; REP(0, i, N) cin >> A[i];
    int B[N]; REP(0, i, N) B[i] = A[i];
    sort(B, B + N, greater<int>());
    REP(0, i, N) {
        if (A[i] == B[0]) cout << B[1] << endl;
        else cout << B[0] << endl;
    }
    return 0;
}
