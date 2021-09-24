// g++ -std=c++14 -DDEV=1 main.cpp
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

// キーワード: 余りを持って桁DP

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

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

typedef Modulo<1000000007> Mod;

class Problem {
private:

    long N;
    int B, K;
    vector<int> c;
    // dp[i][j]: 上からi桁目をBで割った余りがjである場合の数を求めよ。
    vector<vector<Mod>> dp;

public:
    Problem() {
        cin >> N >> B >> K;

        c.resize(K);
        rep(i, 0, K) cin >> c[i];

        if (N > 10000) {
            terminate();
        }

        dp.assign(N, vector<Mod>(B, Mod(0)));
    }

    void solve() {
        rep(k, 0, K) {
            int next = c[k] % B;
            dp[0][next] = dp[0][next] + Mod(1);
        }

        rep(i, 0, N-1) rep(j, 0, B) rep(k, 0, K) {
            int next = (10 * j + c[k]) % B;
            dp[i+1][next] = dp[i+1][next] + dp[i][j];
        }

        cout << dp[N-1][0].get() << endl;
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
