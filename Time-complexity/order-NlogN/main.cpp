#include <stdio.h>
#include <iostream>
#include <fstream>
#include <chrono>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::chrono::system_clock;

void solve() {
    long N; cin >> N;
    auto start_time = system_clock::now().time_since_epoch().count();
    for (long a = 1; a < N; ++a) {
        for (long b = a; b < N; b += a) {
        }
    }
    auto end_time = system_clock::now().time_since_epoch().count();
    cout << end_time - start_time << " milliseconds" << endl;

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
