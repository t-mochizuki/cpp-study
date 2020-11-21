#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;
using std::map;
using std::make_pair;
using std::sort;
using std::to_string;
using std::lower_bound;
using std::distance;

const int KEY_NOT_FOUND = -1;

int binary_search_leftmost(vector<long> arr, int value, int left, int right) {
    if (left < right) {
        // the floor of (L + R) / 2
        int pivot = left + (right - left) / 2;
        if (arr[pivot] < value) {
            return binary_search_leftmost(arr, value, pivot + 1, right);
        } else {
            return binary_search_leftmost(arr, value, left, pivot);
        }
    } else {
        return left;
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
    int D = 5;
    vector<long> v(D * N);
    for (int i = 0; i < N; ++i) for (int j = 0; j < D; ++j) {
        v[i+N*j] = i;
    }
    sort(v.begin(), v.end());

    printf("Find %d in an array\n", K);

    int pos = binary_search_leftmost(v, K, 0, v.size());

    printf("It was found %d in the array\n", pos);
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
