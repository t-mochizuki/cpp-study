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

void print(vector<long> arr, int pos) {
    for (int i = 0; i < arr.size(); ++i) {
        if (i == arr.size() - 1) {
            if (i == pos) {
                cout << "(" << arr[i] << ")" << endl;
            } else {
                cout << arr[i] << endl;
            }
        } else {
            if (i == pos) {
                cout << "(" << arr[i] << ")" << " ";
            } else {
                cout << arr[i] << " ";
            }
        }
    }
}

void solve() {
    int N, K; cin >> N >> K;
    int D = 5;
    vector<long> v(D * N);
    for (int i = 0; i < N; ++i) for (int j = 0; j < D; ++j) {
        v[i+N*j] = i;
    }
    sort(v.begin(), v.end());

    printf("Find %d in an array\n", K);

    int left = -1;
    int right = v.size();
    while (right - left > 1) {
        int pivot = (left + right) / 2;
        if (v[pivot] > K) {
            right = pivot;
        } else {
            left = pivot;
        }
    }

    printf("It was found %d in the array\n", left);
    print(v, left);
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
