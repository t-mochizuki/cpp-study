#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;
using std::map;
using std::make_pair;

// TODO: WA

template<class T> inline T pow(T base, T exponent) {
    if (exponent == 0) return 1;

    if (exponent % 2 == 1) {
        return base * pow(base, exponent - 1);
    } else {
        T tmp = pow(base, exponent / 2);
        return tmp * tmp;
    }
}

template<class T> inline T abs(T X) {
    return X > 0 ? X : -X;
}

long popcount(int n, long r) {
    long tmp  = 0;
    for (int i = 0; i < n; ++i) {
        if (r >> i & 0x1) {
            tmp++;
        }
    }
    return tmp;
}

long f(int n, long x) {
    long p = popcount(n, x);
    long r = x % p;
    if (r == 0) {
        return 1;
    } else {
        return 1 + f(n, r);
    }
}

void solve() {
    int n; cin >> n;
    string x; cin >> x;
    long tmp = 0;
    for (long i = n - 1; i >= 0; --i) {
        if (x[i] == '1') {
            tmp += pow(2L, abs(i - (n - 1)));
        }
    }

    vector<int> v;
    for (long i = 0; i < n; ++i) {
        if (x[i] == '1') {
            v.push_back(tmp - pow(2L, abs(i - (n - 1))));
        } else {
            v.push_back(tmp + pow(2L, abs(i - (n - 1))));
        }
    }

    for (long a : v) {
        cout << f(n, a) << endl;
    }
}

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve();
    }
#else
    solve();
#endif

    return 0;
}
