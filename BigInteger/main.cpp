// g++ -std=c++17 -D DEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

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
    for (int i = v.size()-1; i >= 0; --i) {
        o << v[i];
    }
    return o;
}

class BigInteger {
private:

public:

    int n;

    vector<int> v;

    BigInteger(string s) {
        n = s.size();
        v.resize(n);
        rep(i, 0, n) {
            v[n-1-i] = s[i]-'0';
        }
    }

    BigInteger(vector<int> a) {
        v = a;
        n = a.size();
    }

    BigInteger add(const BigInteger& o);

    BigInteger multiply1(const BigInteger& o);

    BigInteger multiply(int j, const BigInteger& o);

    BigInteger multiply(const BigInteger& o);

    string to_string();
};

BigInteger BigInteger::add(const BigInteger& o) {
    while (n < o.v.size()) {
        v.push_back(0);
        n++;
    }

    vector<int> u;
    u.resize(n+1);

    int c = 0;
    rep(i, 0, n) {
        int x = 0;
        if (i < o.v.size()) {
            x = v[i]+o.v[i]+c;
        } else {
            x = v[i]+c;
        }
        c = x / 10;
        u[i] = x % 10;
    }

    if (c != 0) {
        u[n] = c;
    } else {
        u.resize(n);
    }

    return BigInteger(u);
}

BigInteger BigInteger::multiply1(const BigInteger& o) {
    return multiply(0, o);
}

BigInteger BigInteger::multiply(int j, const BigInteger& o) {
    vector<int> u;
    u.resize(n+1+j);

    int c = 0;
    rep(i, 0, n) {
        int x = 0;
        x = v[i]*o.v[j]+c;
        c = x / 10;
        u[i+j] = x % 10;
    }

    if (c != 0) {
        u[n+j] = c;
    } else {
        u.resize(n+j);
    }

    return BigInteger(u);
}

BigInteger BigInteger::multiply(const BigInteger& o) {
    auto p = BigInteger(vector<int>(0, 0));
    rep(i, 0, o.v.size()) {
        auto q = multiply(i, o);
        p = q.add(p);
    }
    return p;
}

string BigInteger::to_string() {
    string s;
    for (int i = n-1; i >= 0; --i) {
        s.append(std::to_string(v[i]));
    }
    return s;
}

class Solver {
private:

public:

    Solver() {
    }

    bool addTest(string s, string t, string ans) {
        auto a = BigInteger(s), b = BigInteger(t);
        return a.add(b).to_string() == ans;
    }

    bool multiplyTest(string s, string t, string ans) {
        auto a = BigInteger(s), b = BigInteger(t);
        auto val = a.multiply(b).to_string();
        // cout << val << endl;
        return val == ans;
    }

    void solve() {
        vector<tuple<string, string, string>> xs = {
            {"1", "0", "1"},
            {"0", "1", "1"},
            {"12", "900800700600500400300200100", "900800700600500400300200112"},
            {"900800700600500400300200100", "12", "900800700600500400300200112"},
            {"900800700600500400300200100", "10000000000000000000000000", "910800700600500400300200100"},
            {"900800700600500400300200100", "100000000000000000000000000", "1000800700600500400300200100"},
            {"900800700600500400300200100", "900800700600500400300200100", "1801601401201000800600400200"}
        };
        for (auto [s, t, u] : xs) {
            assert(addTest(s, t, u));
        }
        vector<tuple<string, string, string>> ys = {
            {"1", "0", "0"},
            {"0", "1", "0"},
            {"1", "1", "1"},
            {"12", "900800700600500400300200100", "10809608407206004803602401200"},
            {"900800700600500400300200100", "12", "10809608407206004803602401200"},
            {"900800700600500400300200100", "11", "9908807706605504403302201100"},
            {"900800700600500400300200100", "20", "18016014012010008006004002000"}
        };
        for (auto [s, t, u] : ys) {
            assert(multiplyTest(s, t, u));
        }
    }
};

int main(int argc, char **argv) {

    // auto start = system_clock::now();
    Solver s;
    s.solve();
    // auto end = system_clock::now();
    // cout << "time:" << duration_cast<microseconds>(end - start).count() << endl;

    return 0;
}
