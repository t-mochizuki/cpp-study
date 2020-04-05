#include <stdio.h>
#include <iostream>
#include <set>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int t; cin >> t;
    for(int x = 1; x <= t; ++x) {
        int n; cin >> n;
        int m[n][n];
        REP(0, i, n) REP(0, j, n) cin >> m[i][j];

        int k = 0;
        REP(0, i, n) k += m[i][i];

        int r = 0;
        REP(0, i, n) {
            set<int> s;
            REP(0, j, n) {
                s.insert(m[i][j]);
            }
            if (s.size() != n) {
                r++;
            }
        }

        int c = 0;
        REP(0, j, n) {
            set<int> s;
            REP(0, i, n) {
                s.insert(m[i][j]);
            }
            if (s.size() != n) {
                c++;
            }
        }

        cout << "Case #" << x << ": " << k << " " << r << " " << c << endl;
    }
    return 0;
}
