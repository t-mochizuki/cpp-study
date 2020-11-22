#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;
using std::sort;
using std::map;
using std::make_pair;

void solve() {
    string T; cin >> T;

    // Tのすべての接尾辞を求めよ
    vector<string> v;
    int n = T.length();
    for (int i = 0; i < n; ++i) {
        v.push_back(T.substr(i));
    }

    // それら接尾辞を辞書式順序で並び替えよ
    sort(v.begin(), v.end());

    // Tに対する接尾辞配列を求めよ
    vector<int> sa;
    for (auto& s : v) {
        sa.push_back(n-s.length());
    }

    // TのBurrows Wheeler変換の結果の文字列を求めよ
    string TB;
    for (int i = 0; i < n; ++i) {
        if (sa[i] == 0) {
            TB.push_back(T[n-1]);
        } else {
            TB.push_back(T[sa[i]-1]);
        }
    }

    cout << "TB:" << TB << endl;

    // ある文字より小さい文字のT中の出現回数を求めよ
    const int  ascii = 128;
    int C[ascii] = {0};
    for (auto& c : TB) {
        C[c]++;
    }
    int sum = 0;
    for (int i = 0; i < ascii; ++i) {
        int cur = C[i];
        C[i] = sum;
        sum += cur;
    }

    // TBからTFを求めよ
    string TF;
    // for (int i = 0; i < n; ++i) {
    //     TF.push_back(T[sa[i]]);
    // }
    for (int i = 1; i < ascii; ++i) {
        if (C[i-1] != C[i]) {
            for (int j = C[i-1]; j < C[i]; ++j) {
                TF.push_back((char)(i-1));
            }
        }
    }

    cout << "TF:" << TF << endl;

    // TBとTFからTを求めよ
    char TBC[ascii];
    char TFC[ascii];
    for (int i = 0; i < ascii; ++i) {
        TBC[i] = '1';
        TFC[i] = '1';
    }
    map<string, string> m;
    for (int i = 0; i < n; ++i) {
        char tbi = TBC[TB[i]]; TBC[TB[i]]++;
        char tbs[3] = {TB[i], tbi, '\0'};

        char tfi = TFC[TF[i]]; TFC[TF[i]]++;
        char tfs[3] = {TF[i], tfi, '\0'};

        m.insert(make_pair(tbs, tfs));
    }

    // for (auto& p : m) {
    //     cout << p.first << ":" << p.second << endl;
    // }

    string tmp = "$1";
    string S;
    while (m[tmp] != "$1") {
        S.push_back(m[tmp][0]);
        tmp = m[tmp];
    }
    S.push_back('$');

    cout << "T':" << S << endl;
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
