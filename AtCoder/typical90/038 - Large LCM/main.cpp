// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;

// キーワード: オーバーフローに注意

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

const long LARGE = 1000000000000000000L;

template<class T> inline T gcd(T a, T b) {
  while (b > 0) {
    T r = a % b;
    a = b;
    b = r;
  }

  return a;
}

class Problem {
private:

    long A, B;

public:

    Problem() {
        cin >> A >> B;
    }

    void solve() {
        long r = B / gcd(A, B);
        if (r > LARGE / A) cout << "Large" << endl;
        else cout << r * A << endl;
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
