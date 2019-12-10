#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

// 累積和と二分探索
int main() {
    int N; long K; cin >> N >> K;
    long a[N];
    vector<long> v;
    REP(0, i, N) {
        cin >> a[i];
        if (i == 0) {
            v.push_back(a[0]);
        } else {
            v.push_back(v[i - 1] + a[i]);
        }
    }

    vector<long>::iterator it;
    long ans = 0;
    int cnt = 0;
    for (it = v.begin(); it != v.end(); ++it) {
        vector<long>::iterator pos = lower_bound(it, v.end(), K);
        int d = distance(v.begin(), pos);
        if (d == N) {
            break;
        } else {
            // cout << d << endl;
        }
        ans += N - d;
        K += a[cnt];
        cnt++;
    }

    cout << ans << endl;

    return 0;
}
