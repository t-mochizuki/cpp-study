#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

        string q;
        REP(0, i, n) {
            if (i == 0) {
                q = p[i];
            } else {
                if (p[i].length() > q.length()) {
                    q = p[i];
                }
            }
        }

        REP(0, i, n) {
            if (q.length() > p[i].length()) {
                int pos = p[i].find('*');
                p[i] = p[i].substr(0, pos) + string(q.length() - p[i].length() + 1, '*') + p[i].substr(pos + 1, p[i].length());
            }
        }

        bool flag = false;
        REP(0, i, n) {
            REP(0, j, q.length()) {
                if (p[i][j] != '*' && q[j] != '*' && q[j] != p[i][j]) {
                    flag = true;
                    break;
                }
            }
        }

        if (flag) {
            cout << "Case #" << x << ": *" << endl;
        } else {
            int pos = q.find('*');
            char c = 'Z';
            REP(0, i, n) {
                if (p[i][pos] != '*') {
                    c = p[i][pos];
                }
            }
            q = q.substr(0, pos) + string(1, c) + q.substr(pos + 1, q.length() - (pos + 1));
            cout << "Case #" << x << ": " << q << endl;
        }
    }
    return 0;
}
