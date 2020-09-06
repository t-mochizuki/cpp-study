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

const long INF = 1L << 61;

// TODO: RETRY

void solve() {
    long N, K; cin >> N >> K;
    vector<long> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    long min_v = -INF;
    long max_v = INF;
    while (max_v - min_v > 1) {
        long x = (max_v + min_v) / 2;
        long S = 0;
        long T = 0;
        for (int i = 0; i < N; ++i) {
            if (v[i] > 0) {
                int left_i = -1;
                int right_i = N;
                while (right_i - left_i > 1) {
                    int pivot = (right_i + left_i) / 2;
                    if (v[i] * v[pivot] <= x) {
                        left_i = pivot;
                    } else {
                        right_i = pivot;
                    }
                }
                S += right_i;
            } else if (v[i] < 0) {
                int left_i = -1;
                int right_i = N;
                while (right_i - left_i > 1) {
                    int pivot = (right_i + left_i) / 2;
                    if (v[i] * v[pivot] <= x) {
                        right_i = pivot;
                    } else {
                        left_i = pivot;
                    }
                }
                S += N - right_i;
            } else if (x >= 0) {
                S += N;
            }

            if (v[i] * v[i] <= x) {
                T++;
            }
        }

        long cnt = (S - T) / 2;
        if (cnt >= K) {
            max_v = x;
        } else {
            min_v = x;
        }
    }

    cout << max_v << endl;
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
