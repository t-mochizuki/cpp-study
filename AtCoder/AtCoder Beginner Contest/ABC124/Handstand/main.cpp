#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;

template<class T> inline T max(T X, T Y) {
    return X > Y ? X : Y;
}

void solve() {
    int N, K; cin >> N >> K;
    string S; cin >> S;
    vector<int> I;

    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            I.push_back(0);
        } else {
            if (S[i - 1] != S[i]) {
                I.push_back(i);
            }
        }
    }
    I.push_back(N);

    int ans = 0;
    for (int k = 0; k < I.size() - 1; ++k) {
        int tmp = 0;

        if (S[I[k]] == '0') {
            if (k + 2 * K > I.size() - 1) {
                tmp = I[I.size() - 1] - I[k];
            } else {
                tmp = I[k + 2 * K] - I[k];
            }
        } else {
            if (k + 2 * K  + 1 > I.size() - 1) {
                tmp = I[I.size() - 1] - I[k];
            } else {
                tmp = I[k + 2 * K + 1] - I[k];
            }
        }

        ans = max(tmp, ans);
    }

    cout << ans << endl;
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
