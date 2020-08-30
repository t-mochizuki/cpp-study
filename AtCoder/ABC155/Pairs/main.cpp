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
using std::vector;

void solve() {
    int N, K; cin >> N >> K; K--;
    int A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<long> v;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            v.push_back(A[i] * A[j]);
        }
    }
    sort(v.begin(), v.end());

    // for (long k : v) {
    //     cout << k << endl;
    // }

    cout << v[K] << endl;

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
