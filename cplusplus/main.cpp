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

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::terminate;
using std::vector;
using std::string;
using std::map;
using std::pair;
using std::deque;
using std::queue;
using std::priority_queue;
using std::tuple;
using std::make_tuple;
using std::tie;
using std::abs;
using std::sort;
using std::cbrt;
using std::lower_bound;
using std::upper_bound;
using std::distance;
using std::to_string;

using namespace std::chrono;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

template <class T>
bool max(T &a, const T b) {
    if (a < b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

template<class T>
istream& operator>>(istream& i, vector<T>& v) {
    rep(j, 0, v.size()) i >> v[j];
    return i;
}

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
        auto start = system_clock::now();
        Solver s;
        s.solve();
        auto end = system_clock::now();
        cout << "time:" << duration_cast<microseconds>(end - start).count() << endl;
    }
#else
    Solver s;
    s.solve();
#endif

    return 0;
}
