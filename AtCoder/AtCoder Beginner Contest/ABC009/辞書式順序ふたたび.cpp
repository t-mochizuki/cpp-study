#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::sort;
using std::map;
using std::make_pair;

template<class T> inline T min(T X, T Y) {
    return X < Y ? X : Y;
}

int count(string S, string T) {
    map<char, int> sm;
    for (decltype(S)::iterator it = S.begin(); it != S.end(); ++it) {
        decltype(sm)::iterator it2 = sm.find(*it);
        if (it2 != sm.end()) {
            it2->second++;
        } else {
            sm.insert(make_pair(*it, 1));
        }
    }

    map<char, int> tm;
    for (decltype(T)::iterator it = T.begin(); it != T.end(); ++it) {
        decltype(tm)::iterator it2 = tm.find(*it);
        if (it2 != tm.end()) {
            it2->second++;
        } else {
            tm.insert(make_pair(*it, 1));
        }
    }

    int tmp = 0;
    for (decltype(tm)::iterator it  = tm.begin(); it != tm.end(); ++it) {
        tmp += min(sm[it->first], tm[it->first]);
    }
    return tmp;
}

void solve() {
    int N, K; cin >> N >> K;
    string S; cin >> S;

    string T = S;
    sort(T.begin(), T.end());

    // for (decltype(tm)::iterator it  = tm.begin(); it != tm.end(); ++it) {
    //     cout << it->first << " " << it->second << endl;
    // }
    // cout << endl;

    map<char, int> sm;
    for (decltype(S)::iterator it = S.begin(); it != S.end(); ++it) {
        decltype(sm)::iterator it2 = sm.find(*it);
        if (it2 != sm.end()) {
            it2->second++;
        } else {
            sm.insert(make_pair(*it, 1));
        }
    }

    map<char, int> tm;
    for (decltype(T)::iterator it = T.begin(); it != T.end(); ++it) {
        decltype(tm)::iterator it2 = tm.find(*it);
        if (it2 != tm.end()) {
            it2->second++;
        } else {
            tm.insert(make_pair(*it, 1));
        }
    }

    char ans[N + 1]; ans[N] = '\0';
    for (int i = 0; i <= N - 1; ++i) {
        ans[i] = '0';
        if (N - count(S, T.substr(i)) >= K) {
            if (sm[S[i]] > 0) {
                ans[i] = S[i];
                sm[S[i]]--;
            }
        } else {
            ans[i] = T[i];
            tm[T[i]]--;
            sm[T[i]]--;
        }
    }

    for (int i = 0; i <= N - 1; ++i) {
        if (ans[i] == '0') {
            for (decltype(sm)::iterator it = sm.begin(); it != sm.end(); ++it) {
                if (it->second > 0) {
                    ans[i] = it->first;
                    it->second--;
                }
            }
        }
    }

    cout << ans << endl;
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
