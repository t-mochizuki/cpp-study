#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;

const long INF = 1L << 61;

void solve() {
    int N, K; cin >> N >> K;
    vector<long> v(2 * N);
    for (int i = 0; i < 2 * N; ++i) {
        v[i] = i - N;
    }

    int left = -1;
    int right = v.size();
    while (right - left > 1) {
        int pivot = (left + right) / 2;
        if (v[pivot] >= K) {
            cout << "right " << pivot << endl;
            right = pivot;
        } else {
            cout << "left " << pivot << endl;
            left = pivot;
        }
    }

    cout << "K=" << K << endl;
    cout << "v[" << right << "]=" << v[right] << endl;
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
