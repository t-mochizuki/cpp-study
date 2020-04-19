#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

string stringL(vector<string> v) {
    string L;
    REP(0, i, v.size()) {
        if (i == 0) {
            L = v[i];
        } else {
            if (v[i].size() > L.size()) {
                L = v[i];
            }
        }
    }
    return L;
}

int main() {
    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        int n; cin >> n;
        vector<string> startWith;
        vector<string> endWith;
        vector<string> inTheMiddle;
        REP(0, i, n) {
            string s; cin >> s;
            if (s[0] == '*') {
                startWith.push_back(s);
            } else if (s[s.size() - 1] == '*') {
                endWith.push_back(s);
            } else {
                inTheMiddle.push_back(s);
            }
        }

        bool ok = true;

        string sL = stringL(startWith);
        REP(0, j, startWith.size()) {
            REP(0, i, sL.size()) {
                if (startWith[j].size() - 1 - i >= 1) {
                    if (sL[sL.size() - 1 - i] != startWith[j][startWith[j].size() - 1 - i]) {
                        ok = false;
                    }
                } else {
                    break;
                }
            }
        }

        string eL = stringL(endWith);
        if (ok) {
            REP(0, j, endWith.size()) {
                REP(0, i, eL.size()) {
                    if (i <= endWith[j].size() - 1) {
                        if (eL[i] != endWith[j][i]) {
                            ok = false;
                        }
                    } else {
                        break;
                    }
                }
            }
        }

        if (ok) {
            cout << "Case #" << x << ": " << L.substr(1) << endl;
        } else {
            cout << "Case #" << x << ": *" << endl;
        }
    }
    return 0;
}
