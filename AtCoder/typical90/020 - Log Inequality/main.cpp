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

class Problem {
private:

    long a, b, c;

public:

    Problem() {
        cin >> a >> b >> c;
    }

    void debug() {
        printf("%ld\n", a);
        printf("%ld\n", pow(c, b));
        printf("%ld\n", pow(c, b) - a);
    }

    void solve() {
        // debug();

        if (a < pow(c, b)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
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
