#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    long N, M;
    cin >> N >> M;

    long A[N];
    REP(0, i, N) {
        cin >> A[i];
    }

    long B[N + 1];
    // A_l + ... + A_r = B_r - B_l-1
    // A_1 = B_1 - B_0
    // A_1 + A_2 = B_2 - B_0
    // A_2 + A_3 + A_4 = B_4 - B_1
    // B[0] は mod M で 0 になる累積和 B[i] と組になる。
    B[0] = 0;
    REP(1, i, N + 1) {
        B[i] = (B[i - 1] + A[i - 1]) % M;
    }

    map<long, long> m;
    REP(0, i, N + 1) {
        map<long, long>::iterator it = m.find(B[i]);
        if (it != m.end()) {
            m[B[i]]++;
        } else {
            m.insert(make_pair(B[i], 1));
        }
    }

    long ans = 0;
    for (map<long, long>::iterator it = m.begin(); it != m.end(); ++it) {
        ans += (it->second) * (it->second - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}
