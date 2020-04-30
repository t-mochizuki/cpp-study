#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int pow(int x, int n) {
    return n == 0 ? 1 : x * pow(x, n - 1);
}

int main() {
    int n, m; cin >> n >> m;

    // 派閥
    int w = pow(2, n);
    map<int, vector<int> > mv;
    // from 1 to 2^12-1
    for (int j = 1; j < w; ++j) {
        REP(0, i, n) {
            if (((j >> i) & 0x1) == 1) {
                map<int, vector<int> >::iterator it = mv.find(j);
                if (it != mv.end()) {
                    mv.at(j).push_back(i);
                } else {
                    vector<int> v; v.push_back(i);
                    mv.insert(make_pair(j, v));
                }
            }
        }
    }

    // DEGUB
    // for (int j = 1; j < w; ++j) {
    //     cout << "j=" << j << endl;
    //     vector<int> v = mv.at(j);
    //     for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
    //         if (it == v.begin()) cout << (*it);
    //         else cout << " " << (*it);
    //     }
    //     cout << endl;
    // }

    // 隣接行列
    int a[n][n]; REP(0, i, n) REP(0, j, n) a[i][j] = 0;
    REP(0, i, m) {
        int x, y; cin >> x >> y;
        x--; y--; // zero origin
        a[x][y] = 1;
        a[y][x] = 1;
    }

    // DEGUB
    // REP(0, i, n) {
    //     REP(0, j, n) {
    //         if (j == 0) {
    //             cout << a[i][j];
    //         } else {
    //             cout << " " << a[i][j];
    //         }
    //     }
    //     cout << endl;
    // }

    int ans = 0;
    for (int j = 1; j < w; ++j) {
        vector<int> v = mv.at(j);
        bool ok = true;
        REP(0, x, v.size()) {
            REP(0, y, v.size()) {
                if (x == y) continue;

                if (a[v[x]][v[y]] != 1) {
                    ok = false;
                }
            }
        }
        if (ok) {
            ans = ans > v.size() ? ans : v.size();
        }
    }

    cout << ans << endl;

    return 0;
}
