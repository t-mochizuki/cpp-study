#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

bool f(char b) {
    if ((b == 'A') || (b == 'T') || (b == 'C') || (b == 'G')) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string S;
    cin >> S;

    int l = 0;
    vector<int> v;
    REP(0, i, S.length()) {
        if (f(S[i])) l++;
        else {
            v.push_back(l);
            l = 0;
        }
    }

    if (l != 0) {
        v.push_back(l);
        l = 0;
    }

    sort(v.begin(), v.end(), greater<int>());

    cout << v[0] << endl;

    return 0;
}
