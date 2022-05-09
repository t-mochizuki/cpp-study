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
using std::make_pair;
using std::deque;
using std::queue;
using std::priority_queue;
using std::tuple;
using std::make_tuple;
using std::tie;
using std::abs;
using std::sort;
using std::lower_bound;
using std::upper_bound;
using std::distance;
using std::to_string;
using std::greater;
using std::multiset;
using std::set;
using std::function;

using namespace std::chrono;

#define rep(i, a, n) for (long i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)
#define yes { cout << "Yes" << endl; return ; }
#define no { cout << "No" << endl; return ; }

template <class T>
bool min(T &a, const T b) {
    if (a > b) {
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

template<class T>
ostream& operator<<(ostream& o, vector<T>& v) {
    rep(j, 0, v.size()) {
        if (j == 0) o << v[j];
        else o << " " << v[j];
    }
    return o;
}

class Solver {
private:

    vector<int> a, b, d;

public:

    void input(vector<int>& v) {
        string s;
        cin >> s;
        int n = s.size();
        v.resize(n);
        rep(i, 0, n) {
            v[n-1-i] = s[i]-'0';
        }
    }

    Solver() {
        input(a);
        input(b);
    }

    void solve() {
        int c = 0, n = a.size();
        d.resize(n+1);
        rep(i, 0, n) {
            int x = a[i]*b[0]+c;
            c = x / 10;
            d[i] = x % 10;
        }
        d[n] = c;
        for (int i = n; i >= 0; --i) {
            if (i == n and d[i] == 0) continue;
            cout << d[i];
        }
        cout << endl;
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
