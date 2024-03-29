// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::tuple;
using std::make_tuple;
using std::tie;
using std::sort;

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

    vector<T> fac/*torial*/, inv/*erse element*/;

public:

    Combination(int N) {
        fac.resize(N+1, T(1));
        rep(i, 1, N+1) {
            if (i == 1) {
                fac[i] = T(1);
            } else {
                fac[i] = T(i) * fac[i-1];
            }
        }

        inv.resize(N+1, T(1));
        for (int i = N; i >= 1; --i) {
            if (i == N) {
                inv[i] = T(1) / fac[i];
            } else {
                inv[i] = T(i+1) * inv[i+1];
            }
        }
    }

    T get(int n, int k) {
        assert(n >= k);
        assert(k >= 0);
        return fac[n] * inv[k] * inv[n-k];
    }
};

typedef Combination<Mod1000000007> Combination1000000007;

class Problem {
private:

    int H, W, N;
    vector<tuple<int, int>> grid;
    // dp[i]: 1からi-1番目の壁のマスを避けてi番目の壁のマスまで辿り着く場合の数を求める。
    vector<Mod1000000007> dp;

public:
    Problem() {
        cin >> H >> W >> N;

        grid.resize(N+2);
        grid[0] = make_tuple(0, 0);
        rep(i, 1, N+1) {
            int r, c;
            cin >> r >> c;
            r--; c--;
            grid[i] = make_tuple(r, c);
        }
        grid[N+1] = make_tuple(H-1, W-1);

        sort(grid.begin(), grid.end());

        dp.assign(N+2, Mod1000000007(0));
        dp[0] = 1;
    }

    void debug() {
        int r, c;
        for (auto t : grid) {
            tie(r, c) = t;
            cout << "(" << r << " " << c << ")";
        }
        cout << endl;
    }

    void solve() {
        Combination1000000007 f(200000);

        rep(i, 1, N+2) {
            int ri, ci;
            tie(ri, ci) = grid[i];

            Mod1000000007 tmp(0);
            rep(j, 1, i) {
                int rj, cj;
                tie(rj, cj) = grid[j];

                if (ci-cj >= 0 && ri-rj >= 0) {
                    tmp = tmp + dp[j] * f.get(ri-rj+(ci-cj), ci-cj);
                }
            }

            dp[i] = f.get(ri+ci, ri > ci ? ri : ci) - tmp;
        }

        cout << dp[N+1].get() << endl;
    }
};

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        Problem p;
        p.solve();
    }
#else
    Problem p;
    p.solve();
#endif

    return 0;
}
