// g++ -std=c++17 -D DEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <deque>
#include <queue>
#include <tuple>
#include <algorithm>
#include <chrono>
#include <cmath>
#include <functional>
#include <set>
#include <atcoder/modint>

using namespace std;
using namespace atcoder;

using mint = modint998244353;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)
#define yes { cout << "Yes" << endl; return ; }
#define no { cout << "No" << endl; return ; }

template<class T> bool min(T &a, const T b) { if (a > b) { a = b; return true; } else { return false; } }
template<class T> bool max(T &a, const T b) { if (a < b) { a = b; return true; } else { return false; } }
template<class K, class V> istream& operator>>(istream& i, pair<K, V>& p) { i >> p.first >> p.second; return i; }
template<class T> istream& operator>>(istream& i, vector<T>& v) { rep(j, 0, v.size()) i >> v[j]; return i; }
template<class T> ostream& operator<<(ostream& o, vector<T>& v) { rep(j, 0, v.size()) { if (j == 0) o << v[j]; else o << " " << v[j]; } return o; }

class Solver {
private:

public:

    Solver() {
    }

    void solve() {
    }
};

int main(int argc, char **argv) {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());


    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        auto start = std::chrono::system_clock::now();
        Solver s;
        s.solve();
        auto end = std::chrono::system_clock::now();
        cout << "time:" << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << endl;
    }
#else
    Solver s;
    s.solve();
#endif

    return 0;
}
