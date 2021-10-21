// g++ -std=c++14 main.cpp
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
using std::make_tuple;
using std::tie;
using std::tuple;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)

template<int MOD>
class Modulo {
private:

    int value;

    tuple<int, int> extendedEuclidean(int a, int b, int x = 1, int y = 0, int u = 0, int v = 1) const {
        if (b == 0) {
            return make_tuple(x, y);
        } else {
            int q = a / b;
            int r = a % b;
            x = x - (q * u);
            y = y - (q * v);
            return extendedEuclidean(b, r, u, v, x, y);
        }
    }

    int inverse() const {
        int x, y;
        tie(x, y) = extendedEuclidean(value, MOD);
        int gcd = value * x + MOD * y;
        assert(gcd == 1);
        return x % MOD;
    }

public:

    Modulo(int x) {
        if (x < 0) {
            x %= MOD;
            x += MOD;
        }

        value = x;
    }


    Modulo operator+(Modulo that) const { return Modulo((value + that.value) % MOD); }
    Modulo operator-(Modulo that) const { return Modulo((value - that.value + MOD) % MOD); }
    Modulo operator*(Modulo that) const {
        long a = value;
        long b = that.value;
        return Modulo((a * b) % MOD);
    }
    Modulo operator/(Modulo that) const { return Modulo(value) * Modulo(that.inverse()); }

    int get() {
        return value;
    }

};

typedef Modulo<1000000007> Mod1000000007;

template<class T>
class Combination {
private:

    int N;
    vector<T> fac/*torial*/, inv/*erse element*/;

public:

    Combination(int N): N(N) {
        fac.assign(N+1, T(1));
        rep(i, 1, N+1) {
            if (i == 1) {
                fac[i] = T(1);
            } else {
                fac[i] = T(i) * fac[i-1];
            }
        }

        inv.assign(N+1, T(1));
        for (int i = N; i >= 0; --i) {
            if (i == N) {
                inv[i] = T(1) / fac[i];
            } else {
                inv[i] = T(i+1) * inv[i+1];
            }
        }
    }

    T get(int n, int k) {
        assert(N >= n);
        assert(n >= k);
        assert(k >= 0);
        return fac[n] * inv[k] * inv[n-k];
    }
};

typedef Combination<Mod1000000007> Combination1000000007;

class Problem {
private:

public:
    Problem() {
    }

    void solve() {
        Combination1000000007 comb(200000);

        assert(10 == (comb.get(5, 3)).get());
        assert(20 == (comb.get(6, 3)).get());
        assert(35 == (comb.get(7, 3)).get());
        assert(56 == (comb.get(8, 3)).get());
        assert(1 == (comb.get(200000, 200000)).get());
        assert(1 == (comb.get(200000, 0)).get());
        assert(1 == (comb.get(8, 0)).get());
        assert(1 == (comb.get(0, 0)).get());
    }
};

int main() {

    Problem p;
    p.solve();

    return 0;
}
