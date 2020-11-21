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

const int KEY_NOT_FOUND = -1;

int binary_search(vector<long> arr, int value, int left, int right) {
    if (right < left) {
        return KEY_NOT_FOUND;
    } else {
        int pivot = left + (right - left) / 2;
        if (value < arr[pivot]) {
            return binary_search(arr, value, left, pivot - 1);
        } else if (arr[pivot] < value) {
            return binary_search(arr, value, pivot + 1, right);
        } else {
            return pivot;
        }
    }
}

int binary_search_alternative(vector<long> arr, int value, int left, int right) {
    if (right == left) {
        if (arr[right] == value) {
            return right;
        } else {
            return KEY_NOT_FOUND;
        }
    } else {
        // the ceiling of (L + R) / 2
        int pivot = left + (right - left + 1) / 2;
        if (value < arr[pivot]) {
            return binary_search(arr, value, left, pivot - 1);
        } else {
            return binary_search(arr, value, pivot, right);
        }
    }
}

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
    vector<long> v(3 * N);
    for (int i = 0; i < N; ++i) for (int j = 0; j < 3; ++j) {
        v[i+N*j] = i;
    }
    sort(v.begin(), v.end());

    printf("Find %d in an array\n", K);

    int pos = binary_search(v, K, 0, v.size() - 1);

    print(v, pos);

    pos = binary_search_alternative(v, K, 0, v.size() - 1);

    print(v, pos);
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
