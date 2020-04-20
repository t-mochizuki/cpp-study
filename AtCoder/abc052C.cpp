// C++14 (GCC 5.4.1)
#include <stdio.h>
#include <cmath>
#include <map>

using namespace std;

#define REP(a, i, n) for (int i = a; i <= n; ++i)

const int module = 1e9 + 7;

map<int, int> m;

// 約数
void divisor(int n) {
    int a = 2;
    while (n >= a * a) {
        if (n % a == 0) {
            // printf("%ld * ", a);
            n /= a;
            decltype(m)::iterator it = m.find(a);
            if (it != m.end()) {
                m[a]++;
            } else {
                m.insert(make_pair(a, 1));
            }
        } else {
            a++;
        }
    }
    // printf("%ld\n", n);
    decltype(m)::iterator it = m.find(n);
    if (it != m.end()) {
        m[n]++;
    } else {
        m.insert(make_pair(n, 1));
    }
}

// 剰余演算の分配則
int main() {
    int N; // 1000
    scanf("%d", &N);

    REP(1, n, N) {
        divisor(n);
    }

    // REP(1, i, N) {
    //     if (m[i] > 0) printf("%d %d\n", i, m[i]);
    // }

    long ans = 1;
    for (decltype(m)::iterator it = m.begin(); it != m.end(); ++it) {
        if (it->first == 1) continue;
        if (it->second > 0) ans *= (it->second + 1);
        if (ans > module) ans = ans % module;
    }

    printf("%ld\n", ans);

    return 0;
}
