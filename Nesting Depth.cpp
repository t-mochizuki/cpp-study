#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int abs(int x) {
    return (x > 0 ? x : -x);
}

int atoi(char c) {
    return c - 48;
}

string solve(string s, string y) {
    if (s.empty()) {
        int before = atoi(y[y.length() - 1]);
        y.append(before, ')');
        return y;
    } else {
        int d = atoi(s[0]);
        if (y.empty()) {
            y.append(d, '(');
            y.append(1u, s[0]);
            return solve(s.substr(1), y);
        } else {
            int before = atoi(y[y.length() - 1]);
            int diff = d - before;
            if (diff == 0) {
                y.append(1u, s[0]);
                return solve(s.substr(1), y);
            } else if (diff > 0) {
                y.append(diff, '(');
                y.append(1u, s[0]);
                return solve(s.substr(1), y);
            } else {
                y.append(abs(diff), ')');
                y.append(1u, s[0]);
                return solve(s.substr(1), y);
            }
        }
    }
}

int main() {
    int t; cin >> t;
    for(int x = 1; x <= t; ++x) {
        string s; cin >> s;
        string y = solve(s, "");
        cout << "Case #" << x << ": " << y << endl;
    }
    return 0;
}
