#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::sort;

template<class T> inline void swap(T &A, T &B) {
    T tmp = A;
    A = B;
    B = tmp;
}

void solve() {
    int N, K; cin >> N >> K;
    string S; cin >> S;

    string T = S;
    sort(T.begin(), T.end());

    if (N == K) {
        cout << T << endl;
    } else {
    }
}

int main() {

#ifdef DEV
    std::ifstream in("AtCoder/ABC009/辞書式順序ふたたび.input");
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
