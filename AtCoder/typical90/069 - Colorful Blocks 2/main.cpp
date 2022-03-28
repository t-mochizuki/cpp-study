// g++ -std=c++17 -D DEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <tuple>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::string;
using std::pair;
using std::tuple;
using std::make_tuple;
using std::tie;
using std::abs;
using std::sort;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

const long MOD = 1000000007L;

long pow(long base, long exponent) {
    if (exponent == 0L) return 1L;

    if (exponent % 2L == 1) {
        return (base * pow(base, exponent - 1L)) % MOD;
    } else {
        long tmp = pow(base, exponent / 2L) % MOD;
        return (tmp * tmp) % MOD;
    }
}

// ブロックの塗り方は何通りあるか
class Program {
private:

    long n, k;

public:

    Program() {
        cin >> n >> k;
    }

    long product(long n, long k) {
        if (n == 1L) return k;
        if (n == 2L) return (k * (k-1L)) % MOD;

        return ((k * (k-1L) % MOD) * pow(k-2L, n-2L)) % MOD;
    }

    void solve() {
        cout << product(n, k) << endl;
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
