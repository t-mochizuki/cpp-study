// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <tuple>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::string;
using std::tuple;
using std::make_tuple;
using std::tie;

// キーワード: 状態DPによる高速化

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

    int N;
    string S;
    string atcoder = "atcoder";
    vector<vector<Mod>> dp;

public:
    Problem() {
        cin >> N >> S;

        dp.assign(N+1, vector<Mod>(atcoder.length()+1, 0));
        rep(i, 0, N+1) dp[i][0] = 1;
    }

    void debug() {
        rep(j, 0, atcoder.length()+1) rep(i, 0, N+1) {
            if (i == 0) cout << dp[i][j].get();
            else cout << "," << dp[i][j].get();

            if (i == N) cout << endl;
        }

    }

    void solve() {
        rep(j, 1, atcoder.length()+1) rep(i, 1, N+1) {
            if (S[i-1] == atcoder[j-1]) {
                dp[i][j] = dp[i][j] + dp[i-1][j];
                dp[i][j] = dp[i][j] + dp[i-1][j-1];
            } else {
                dp[i][j] = dp[i][j] + dp[i-1][j];
            }
        }

        cout << dp[N][7].get() << endl;
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
