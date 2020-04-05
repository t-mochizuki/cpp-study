#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

struct data_s {
    int i;
    int s;
    int e;
    bool operator>(const data_s& rhs) const {
        return s > rhs.s;
    }
};

struct data_e {
    int i;
    int s;
    int e;
    char c;
    bool operator>(const data_e& rhs) const {
        return e > rhs.e;
    }
};

int main() {
    int t; cin >> t;
    for(int x = 1; x <= t; ++x) {
        int n; cin >> n;
        priority_queue<data_s, vector<data_s>, greater<data_s> > que;
        REP(0, i, n) {
            int s, e; cin >> s >> e;
            que.push((data_s){i, s, e});
        }

        priority_queue<data_e, vector<data_e>, greater<data_e> > par;
        char y[n + 1];
        REP(0, i, n + 1) y[i] = '\0';
        bool imp = false;
        while (!que.empty()) {
            data_s s = que.top(); que.pop();
            if (par.empty()) {
                par.push((data_e){s.i, s.s, s.e, 'C'});
                y[s.i] = 'C';
            } else if (par.size() == 1) {
                data_e e = par.top();
                if (e.c == 'J') {
                    par.push((data_e){s.i, s.s, s.e, 'C'});
                    y[s.i] = 'C';
                } else {
                    par.push((data_e){s.i, s.s, s.e, 'J'});
                    y[s.i] = 'J';
                }
            } else if (par.size() == 2) {
                data_e e = par.top(); par.pop();
                if (e.e <= s.s) {
                    par.push((data_e){s.i, s.s, s.e, e.c});
                    y[s.i] = e.c;
                } else {
                    imp = true;
                    break;
                }
            } else {
                imp = true;
                break;
            }
        }

        if (imp) {
            cout << "Case #" << x << ": IMPOSSIBLE" << endl;
        } else {
            cout << "Case #" << x << ": " << y << endl;
        }
    }
    return 0;
}
