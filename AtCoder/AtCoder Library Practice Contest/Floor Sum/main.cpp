#include <stdio.h>
#include <iostream>
#include <fstream>
#include <atcoder/math>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using atcoder::floor_sum;

void solve() {
    long long N, M, A, B; cin >> N >> M >> A >> B;
    cout << floor_sum(N, M, A, B) << endl;
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
    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve();
    }
#endif

    return 0;
}
