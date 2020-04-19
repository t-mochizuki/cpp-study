#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        int n; cin >> n;
        vector<string> p;
        REP(0, i, n) {
            string s; cin >> s;
            p.push_back(s);
        }

        string L;
        REP(0, i, n) {
            if (i == 0) {
                L = p[i];
            } else {
                if (p[i].size() > L.size()) {
                    L = p[i];
                }
            }
        }

        bool ok = true;
        REP(0, j, p.size()) {
            REP(0, i, L.size()) {
                if (p[j].size() - 1 - i >= 1) {
                    if (L[L.size() - 1 - i] != p[j][p[j].size() - 1 - i]) {
                        ok = false;
                    }
                } else {
                    break;
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
