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

// キーワード: 同じ遷移のDPは行列累乗

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


template<class T>
class Matrix {
private:

public:

    vector<vector<T>> value;

    Matrix(int dimension) {
        value.assign(dimension, vector<T>(dimension, T(0)));
    }

    Matrix(vector<vector<T>> a): value(a) {
    }

    // dimension
    int D() {
        return value.size();
    }

    // unit matrix
    Matrix I() {
        Matrix tmp(D());
        rep(i, 0, D()) tmp.value[i][i] = T(1);
        return tmp;
    }

    Matrix operator*(const Matrix & mat) {
        Matrix tmp(D());
        rep(i, 0, D()) rep(j, 0, D()) rep(k, 0, D()) {
            tmp.value[i][j] = tmp.value[i][j] + value[i][k] * mat.value[k][j];
        }
        return tmp;
    }

    Matrix fastpow(long exponent) {
        if (exponent == 0) return Matrix(D()).I();

        if (exponent % 2 == 1) {
            return Matrix(value) * fastpow(exponent - 1);
        } else {
            Matrix tmp = fastpow(exponent / 2);
            return tmp * tmp;
        }
    }

    void print() {
        rep(i, 0, D()) {
            bool first = true;
            rep(j, 0, D()) {
                if (j == 0) {
                    cout << value[i][j].get();
                    first = false;
                } else {
                    cout << " " << value[i][j].get();
                }
            }
            cout << endl;
        }
        cout << endl;
    }

};

class Problem {
private:

    long N;
    int B, K;
    vector<int> c;

public:
    Problem() {
        cin >> N >> B >> K;

        c.resize(K);
        rep(i, 0, K) cin >> c[i];

        if (B > 30) {
            terminate();
        }
    }

    void solve() {
        vector<vector<Mod>> value;
        value.assign(B, vector<Mod>(B, Mod(0)));
        // dp[i][j]からdp[i+1][k]に遷移する場合はj行k列の値が1となる。
        rep(j, 0, B) for (auto v : c) {
            int k = (10 * j + v) % B;
            value[j][k] = value[j][k] + Mod(1);
        }

        Matrix<Mod> mat(value);
        Matrix<Mod> tmp = mat.fastpow(N);

        cout << tmp.value[0][0].get() << endl;
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
