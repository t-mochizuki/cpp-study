// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;

#define rep(i, n) for (int i = 0; i < (n); ++i)

const long MOD = 1e9 + 7;

class Matrix {
private:

public:

    vector<vector<long>> value;

    Matrix(int dimension) {
        value.assign(dimension, vector<long>(dimension, 0));
    }

    Matrix(vector<vector<long>> a): value(a) {
    }

    // dimension
    int D() {
        return value.size();
    }

    // unit matrix
    Matrix I() {
        Matrix tmp(D());
        rep(i, D()) tmp.value[i][i] = 1;
        return tmp;
    }

    Matrix operator*(const Matrix & mat) {
        Matrix tmp(D());
        rep(i, D()) rep(j, D()) rep(k, D()) {
            tmp.value[i][j] += value[i][k] * mat.value[k][j];
            tmp.value[i][j] %= MOD;
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
        rep(i, D()) {
            bool first = true;
            rep(j, D()) {
                if (j == 0) {
                    cout << value[i][j];
                    first = false;
                } else {
                    cout << " " << value[i][j];
                }
            }
            cout << endl;
        }
        cout << endl;
    }

};

class Problem {
private:

    int N;
    long K;
    vector<vector<long>> a;

public:

    Problem() {
        cin >> N >> K;

        a.assign(N, vector<long>(N, 0));
        rep(i, N) rep(j, N) cin >> a[i][j];
    }

    void solve() {
        Matrix mat(a);
        Matrix tmp = mat.fastpow(K);

        long ans = 0;
        rep(i, tmp.D()) rep(j, tmp.D()) {
            ans += tmp.value[i][j];
            ans %= MOD;
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
        Problem p;
        p.solve();
    }
#else
    Problem p;
    p.solve();
#endif

    return 0;
}
