#include <stdio.h>
#include <iostream>

using namespace std;

const int INDEFINITE = -1;

template<class T> inline T pow(T base, T exponent) {
    if (exponent == 0) return 1;

    if (exponent % 2 == 1) {
        return base * pow(base, exponent - 1);
    } else {
        T tmp = pow(base, exponent / 2);
        return tmp * tmp;
    }
}

int dp(int N, int m[]) {
    if (m[N] != INDEFINITE) {
        return m[N];
    }

    if (6 > N) {
        m[N] = N;
    } else {
        for (int i = 6; i <= N; i *= 6) {
            if (m[N] != INDEFINITE) {
                m[N] = min(m[N], dp(N - i, m) + 1);
            } else {
                m[N] = min(N, dp(N - i, m) + 1);
            }
        }
        for (int i = 9; i <= N; i *= 9) {
            if (m[N] != INDEFINITE) {
                m[N] = min(m[N], dp(N - i, m) + 1);
            } else {
                m[N] = min(N, dp(N - i, m) + 1);
            }
        }
    }

    return m[N];
}

int main() {
    int N; cin >> N;
    int m[N + 1];
    for (int i = 0; i <= N; ++i) {
        m[i] = INDEFINITE;
    }

    cout << dp(N, m) << endl;

    return 0;
}
