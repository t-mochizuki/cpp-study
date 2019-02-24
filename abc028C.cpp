#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int X[5];
    REP(0, i, 5) {
        cin >> X[i];
    }

    vector<int> v;
    REP(0, i, 5) {
        REP(i + 1, j, 5) {
            REP(j + 1, k, 5) {
                v.push_back(X[i] + X[j] + X[k]);
            }
        }
    }

    sort(v.begin(), v.end(), greater<int>());

    v.erase(unique(v.begin(), v.end()), v.end());

    cout << v[2] << endl;

    return 0;
}
