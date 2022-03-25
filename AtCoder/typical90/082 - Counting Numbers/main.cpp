// g++ -std=c++17 -D DEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::tie;
using std::make_tuple;
using std::tuple;

template<long MOD>
class Modulo {
private:

    long value;

    tuple<long, long> extendedEuclidean(long a, long b, long x = 1, long y = 0, long u = 0, long v = 1) const {
        if (b == 0) {
            return make_tuple(x, y);
        } else {
            long q = a / b;
            long r = a % b;
            x = x - (q * u);
            y = y - (q * v);
            return extendedEuclidean(b, r, u, v, x, y);
        }
    }

    long inverse() const {
        long x, y;
        tie(x, y) = extendedEuclidean(value, MOD);
        long gcd = value * x + MOD * y;
        assert(gcd == 1);
        return x % MOD;
    }

public:

    Modulo(long x) {
        if (x < 0) {
            x %= MOD;
            x += MOD;
        }

        value = x;
    }


    Modulo operator+(Modulo that) const { return Modulo((value + that.value) % MOD); }
    Modulo operator-(Modulo that) const { return Modulo((value - that.value + MOD) % MOD); }
    Modulo operator*(Modulo that) const {
        long a = value % MOD;
        long b = that.value % MOD;
        return Modulo((a * b) % MOD);
    }
    Modulo operator/(Modulo that) const { return Modulo(value) * Modulo(that.inverse()); }

    long get() {
        return value;
    }

};

const long MOD = 1000000007L;

using Mod1000000007 = Modulo<MOD>;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

template<class T> inline T pow(T base, T exponent) {
    if (exponent == 0) return 1;

    if (exponent % 2 == 1) {
        return base * pow(base, exponent - 1);
    } else {
        T tmp = pow(base, exponent / 2);
        return tmp * tmp;
    }
}

class Program {
private:

    long L, R;

public:

    Program() {
        cin >> L >> R;
    }

    void solve() {
        Mod1000000007 ans = 0;
        for (long i = L; i <= R; ++i) {
            // 何桁か
            Mod1000000007 cnt = 0L;
            long x = i;
            while (x > 0) {
                x /= 10;
                cnt = cnt + 1;
            }

            // その桁の最大値を求める
            long y = 0;
            if (i != 1000000000000000000) {
                for (long j = 0; j < cnt.get(); ++j) {
                    y += 9L * pow(10L, j);
                }

                if (y > R) {
                    y = R;
                }
            } else {
                y = i;
            }

            // 等差数列の和: (y-i+1)*(i+y)/2
            Mod1000000007 a = 0L, n = 0L;
            if ((i+y) % 2 == 0) {
                a = (i+y) / 2L;
                n = y-i+1L;
            } else {
                a = i+y;
                n = (y-i+1L) / 2L;
            }

            ans = ans + a * n * cnt;

            i = y;
        }
        cout << ans.get() << endl;
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
