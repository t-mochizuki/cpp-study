#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// TODO: RETRY

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string S, T; cin >> S >> T;

    map<char, vector<int> > m;
    REP(0, i, S.length()) {
        map<char, vector<int> >::iterator it = m.find(S[i]);
        if (it != m.end()) {
            it->second.push_back(i);
        } else {
            vector<int> v; v.push_back(i);
            m.insert(make_pair(S[i], v));
        }
    }

    // for (map<char, vector<int> >::iterator it = m.begin(); it != m.end(); ++it) {
    //     cout << it->second.size() << endl;
    // }

    REP(0, i, S.length()) {
        if (S[i] != T[i]) {
            char tmp = S[i];
            vector<int> sIds = m[S[i]]; vector<int> tIds = m[T[i]];
            REP(0, j, sIds.size()) S[sIds[j]] = T[i]; REP(0, j, tIds.size()) S[tIds[j]] = tmp;
            m[T[i]] = sIds; m[tmp] = tIds;
        }
    }

    if (S == T) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
