// g++ -std=c++17 -D DEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::map;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

template <class T>
map<T, long> factorization(T n) {
    map<T, long> m;
    for (T i = 2; i * i <= n; ++i) {
        long tmp = 0;
        while (n % i == 0) {
            tmp++;
            n /= i;
        }
        m[i] = tmp;
    }

    if (n != 1) m[n] = 1;

    return m;
}

template<class T>
T pow(T base, T exponent) {
    if (exponent == 0) return 1;

    if (exponent % 2 == 1) {
        return base * pow(base, exponent - 1);
    } else {
        T tmp = pow(base, exponent / 2);
        return tmp * tmp;
    }
}

// ボールの数は2の何乗以下か
class Program {
private:

    long n;

public:

    Program() {
        cin >> n;
    }

    void solve() {
        auto m = factorization(n);

        // ボールの数を求める
        long n = 0;
        for (auto [k, v] : m) {
            n += v;
        }

        long ans = 0;
        while (true) {
            if (n > pow(2L, ans)) {
                ans++;
            } else {
                break;
            }
        }

        cout << ans << endl;
    }
};

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        Program p;
        p.solve();
    }
#else
    Program p;
    p.solve();
#endif

    return 0;
}
