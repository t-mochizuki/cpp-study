#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::upper_bound;

void solve() {
    int N, K; cin >> N >> K;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    auto it = upper_bound(v.begin(), v.end(), K);
    auto pos = distance(v.begin(), it);

    cout << "pos=" << pos << endl;
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
