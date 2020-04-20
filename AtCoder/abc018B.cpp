#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

#define RREP(a, i, n) for (int i = n - 1; i >= 0; --i)

string op(string s, int l, int r) {
    string t = "";

    REP(0, i, l) {
        t += s[i];
    }

    REP(l, i, r + 1) {
        t += s[r - i + l];
    }

    REP(r + 1, i, s.length()) {
        t += s[i];
    }

    return t;
}

int main() {
    string S;
    cin >> S;

    int N;
    cin >> N;

    int l, r;
    REP(0, i, N) {
        cin >> l >> r;

        S = op(S, l - 1, r - 1);
    }

    cout << S << endl;

    return 0;
}
