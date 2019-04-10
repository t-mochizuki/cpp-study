#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int n;
    cin >> n;

    int a[n];
    REP(0, i, n) {
        cin >> a[i];
    }

    vector<int> b;
    REP(0, i, n) {
        if (i % 2 == 0) {
            b.push_back(a[i]);
        } else {
            b.insert(b.begin(), a[i]);
        }
    }

    if (b.size() % 2 != 0) {
        reverse(b.begin(), b.end());
    }

    REP(0, i, n) {
        if (i == 0) {
            cout << b[i];
        } else {
            cout << ' ' << b[i];
        }
    }
    cout << endl;

    return 0;
}
