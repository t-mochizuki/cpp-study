// g++ -std=c++14 -DDEV=1 -Wall main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <map>

using namespace std;

const int module = 1e9 + 7;

// 約数
void divisor(map<int, int> &m, int n) {
    long a = 2;
    while (n >= a * a) {
        if (n % a == 0) {
            n /= a;
            map<int, int>::iterator it = m.find(a);
            if (it != m.end()) {
                m[a]++;
            } else {
                m.insert(make_pair(a, 1));
            }
        } else {
            a++;
        }
    }

    map<int, int>::iterator it = m.find(n);
    if (it != m.end()) {
        m[n]++;
    } else {
        m.insert(make_pair(n, 1));
    }
}

// 剰余演算の分配則
void solve() {
    int N; // 1 <= N <= 1000
    cin >> N;

    map<int, int> m;
    for (int i = 1; i <= N; ++i) {
        divisor(m, i);
    }

    // for (int i = 1; i <= N; ++i) {
    //     if (m[i] > 0) printf("%d %d\n", i, m[i]);
    // }

    long ans = 1;
    for (decltype(m)::iterator it = m.begin(); it != m.end(); ++it) {
        if (it->first == 1) continue;
        if (it->second > 0) ans *= (it->second + 1);
        if (ans > module) ans = ans % module;
    }

    cout << ans << endl;
}

// N!の正の約数の個数を1e9+7で割った余りを求めよ
int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve();
    }
#else
    solve();
#endif

    return 0;
}
