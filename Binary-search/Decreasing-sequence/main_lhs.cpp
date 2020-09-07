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
using std::sort;
using std::greater;

const long INF = 1L << 61;

void solve() {
    int N, K; cin >> N >> K;
    vector<long> v(3 * N);
    for (int i = 0; i < N; ++i) {
        v[i] = i;
    }
    for (int i = 0; i < N; ++i) {
        v[i + N] = i;
    }
    for (int i = 0; i < N; ++i) {
        v[i + 2 * N] = i;
    }
    sort(v.begin(), v.end(), greater<long>());

    for (auto x : v) {
        cout << x << endl;
    }

    int left = -1;
    int right = v.size();
    while (right - left > 1) {
        int pivot = (left + right) / 2;
        if (v[pivot] > K) {
            cout << "left " << pivot << endl;
            left = pivot;
        } else {
            cout << "right " << pivot << endl;
            right = pivot;
        }
    }

    cout << "K=" << K << endl;
    cout << "v[" << left << "]=" << v[left] << endl;
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
