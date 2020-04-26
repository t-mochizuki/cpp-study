#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INDEFINITE = -1;

int pow(int base, int exponent) {
    if (exponent == 0) return 1;

    if (exponent % 2 == 1) {
        return base * pow(base, exponent - 1);
    } else {
        int tmp = pow(base, exponent / 2);
        return tmp * tmp;
    }
}

int dp(int N, vector<int> a, int m[]) {
    if (m[N] != INDEFINITE) {
        return m[N];
    }

    return m[N];
}

int main() {
    int N; cin >> N;
    vector<int> a;
    a.push_back(1);
    for (int i = 1; i <= 6; ++i) {
        int tmp = pow(6, i);
        if (tmp > N) break;
        a.push_back(tmp);
    }
    for (int i = 1; i <= 5; ++i) {
        int tmp = pow(9, i);
        if (tmp > N) break;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());

    int m[N + 1];
    for (int i = 1; i <= N; ++i) {
        m[i] = INDEFINITE;
    }

    cout << dp(N, a, m) << endl;

    return 0;
}
