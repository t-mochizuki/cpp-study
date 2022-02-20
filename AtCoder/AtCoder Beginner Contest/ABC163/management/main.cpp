#include <stdio.h>
#include <iostream>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

void solve() {
    int N; cin >> N;
    int A[N];
    for (int i = 0; i < N; ++i) {
        A[i] = 0;
    }

    for (int i = 0; i < N - 1; ++i) {
        int tmp; cin >> tmp; tmp--;
        A[tmp]++;
    }

    for (int i = 0; i < N; ++i) {
        cout << A[i] << endl;
    }
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
