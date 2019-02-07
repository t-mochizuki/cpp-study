#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {

    int N;
    scanf("%d", &N);

    string s;
    cin >> s;

    int ans = 0;
    REP(0, i, N) {
        string lhs = s.substr(0, i);
        sort(lhs.begin(), lhs.end());
        string::iterator lit = unique(lhs.begin(), lhs.end());
        lhs.erase(lit, lhs.end());

        string rhs = s.substr(i, N - i);
        sort(rhs.begin(), rhs.end());
        string::iterator rit = unique(rhs.begin(), rhs.end());
        rhs.erase(rit, rhs.end());

        int cnt = 0;
        for (lit = lhs.begin(); lit != lhs.end(); ++lit) {
            for (rit = rhs.begin(); rit != rhs.end(); ++rit) {
                if (*lit == *rit) {
                    cnt++;
                    break;
                }
            }
        }
        if (ans < cnt) ans = cnt;
    }

    printf("%d\n", ans);

    return 0;
}
