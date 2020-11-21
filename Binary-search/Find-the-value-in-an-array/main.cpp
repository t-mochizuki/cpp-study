// g++ -std=c++11 main.cpp -I ../nutshell
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <binary_search>
#include <print>

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
using nutshell::binary_search;
using nutshell::binary_search_rightmost;
using nutshell::binary_search_leftmost;
using nutshell::print;

void solve() {
    int N, K; cin >> N >> K;
    vector<long> v(N);
    for (int i = 0; i < N; ++i) {
        v[i] = i;
    }

    printf("Find %d in an array\n", K);

    int pos = binary_search(v, K, 0, v.size() - 1);

    print(v, pos);

    pos = binary_search_rightmost(v, K, 0, v.size() - 1);

    print(v, pos);

    pos = binary_search_leftmost(v, K, 0, v.size() - 1);

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
