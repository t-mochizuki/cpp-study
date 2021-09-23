// g++ -std=c++14 main.cpp
#include <stdio.h>
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

#define rep(i, n) for (int i = 0; i < (n); ++i)

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
        if (gcd == 1) {
            return x % MOD;
        } else {
            terminate();
            return 0;
        }
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

typedef Modulo<7> Mod7;
typedef Modulo<3016> Mod3016;
typedef Modulo<1000000007> Mod1000000007;

class Problem {
private:

public:
    Problem() {
    }

    void solve() {
        Mod7 a(1);
        Mod7 b(5);
        Mod7 c = a / b;

        cout << c.get() << endl; // 3

        Mod3016 aa(1);
        Mod3016 bb(3);
        Mod3016 cc = aa / bb;

        cout << cc.get() << endl; // 2011

        Mod1000000007 x(1e9);
        Mod1000000007 y = x * x;

        cout << y.get() << endl;
    }
};

int main() {

    Problem p;
    p.solve();

    return 0;
}
