#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <binary_search>
#include <print>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::sort;
using nutshell::binary_search;
using nutshell::binary_search_alternative;
using nutshell::print;

const long INF = 1L << 61;

void solve() {
    int N, K; cin >> N >> K;
    int D = 5;
    vector<long> v(D * N);
    for (int i = 0; i < N; ++i) for (int j = 0; j < D; ++j) {
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
