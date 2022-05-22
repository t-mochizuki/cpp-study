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

template<class T> bool min(T &a, const T b) { if (a > b) { a = b; return true; } else { return false; } }
template<class T> bool max(T &a, const T b) { if (a < b) { a = b; return true; } else { return false; } }
template<class T> istream& operator>>(istream& i, vector<T>& v) { rep(j, 0, v.size()) i >> v[j]; return i; }
template<class T> ostream& operator<<(ostream& o, vector<T>& v) { rep(j, 0, v.size()) { if (j == 0) o << v[j]; else o << " " << v[j]; } return o; }

class BigInteger {
private:

public:

    int n;

    vector<int> v;

    bool minus = false;

    BigInteger(string s) {
        if (s[0] == '-') {
            minus = true;
            s = s.substr(1);
        }

        n = s.size();
        v.resize(n);
        rep(i, 0, n) {
            v[n-1-i] = s[i]-'0';
        }
    }

    BigInteger(vector<int> a, bool sign = false) {
        v = a;
        n = a.size();
        minus = sign;
    }

    bool operator==(const BigInteger& o) const {
        bool ok = true;
        rep(i, 0, n) {
            if (v[i] != o.v[i]) {
                ok = false;
                break;
            }
        }
        return ok;
    }

    bool operator>(const BigInteger& o) const {
        bool ok = false;
        rep(i, 0, n) {
            if (v[n-i-1] == o.v[n-i-1]) {
                continue;
            }
            if (v[n-i-1] > o.v[n-i-1]) {
                ok = true;
            }
            break;
        }
        return ok;
    }

    BigInteger subtract(const BigInteger& o) const;

    BigInteger add(const BigInteger& o) const;

    BigInteger multiply(int j, const BigInteger& o) const;

    BigInteger multiply(const BigInteger& o) const;

    BigInteger divide(const BigInteger& o) const;

    string toString() const {
        string s;
        if (minus) {
            s.append("-");
        }
        for (int i = n-1; i >= 0; --i) {
            s.append(std::to_string(v[i]));
        }
        return s;
    };

    void resize(const BigInteger& o) {
        while (n < o.v.size()) {
            v.push_back(0);
            n++;
        }
    }
};

ostream& operator<<(ostream& o, const BigInteger& v) { o << v.toString(); return o; }

BigInteger BigInteger::subtract(const BigInteger& o) const {
    vector<int> u;
    u.resize(n);

    int c = 0;
    rep(i, 0, n) {
        int x = 0;
        if (i < o.v.size()) {
            x = v[i]-o.v[i]+c;
        } else {
            x = v[i]+c;
        }

        if (x < 0) {
            x += 10;
            c = -1;
        } else {
            c = 0;
        }
        u[i] = x;
    }

    while (u.size() >= 2 and u[u.size()-1] == 0) {
        u.pop_back();
    }

    return BigInteger(u);
}

BigInteger BigInteger::add(const BigInteger& o) const {
    bool sign = false;
    if (minus and o.minus) {
        sign = true;
    } else if (not minus and not o.minus) {
        sign = false;
    } else {
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

    return BigInteger(u, sign);
}

BigInteger BigInteger::multiply(int j, const BigInteger& o) const {
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

BigInteger BigInteger::multiply(const BigInteger& o) const {
    bool sign = false;
    if ((minus and o.minus) or (not minus and not o.minus)) {
        sign = false;
    } else {
        sign = true;
    }

    auto p = BigInteger("0");
    rep(i, 0, o.v.size()) {
        auto q = multiply(i, o);
        p = q.add(p);
    }

    p.minus = sign;

    while (p.n >= 2 and p.v[p.n-1] == 0) {
        p.v.pop_back();
        p.n--;
    }

    return p;
}

BigInteger BigInteger::divide(const BigInteger& divisor) const {
    bool sign = false;
    if ((minus and divisor.minus) or (not minus and not divisor.minus)) {
        sign = false;
    } else {
        sign = true;
    }

    if (divisor > *this) {
        auto obj = BigInteger("0");
        return obj;
    }

    if (*this == divisor) {
        auto obj = BigInteger("1");
        obj.minus = sign;
        return obj;
    }

    auto p = BigInteger("0");
    int i = n-1;
    while (i > 0) {
        auto obj = p.multiply(BigInteger("10"));
        obj = obj.add(BigInteger(to_string(v[i])));
        obj.resize(divisor);
        if (obj > divisor) {
            break;
        }
        p = obj;
        i--;
    }

    string s;
    for (; i >= 0; --i) {
        p = p.multiply(BigInteger("10"));
        p = p.add(BigInteger(to_string(v[i])));
        int c = 9;
        auto obj = BigInteger("0");
        while (c > 0) {
            obj = BigInteger(to_string(c)).multiply(divisor);
            p.resize(obj);
            obj.resize(p);
            if ((p > obj) or (p == obj)) {
                break;
            }
            c--;
        }
        p = p.subtract(BigInteger(to_string(c)).multiply(divisor));
        s.append(to_string(c));
    }

    auto q = BigInteger(s);
    if (not (q == BigInteger("0"))) {
        q.minus = sign;
    }

    return q;
}

class Solver {
private:

public:

    Solver() {
    }

    bool addTest(string s, string t, string ans) {
        auto a = BigInteger(s), b = BigInteger(t);

        a.resize(b);
        b.resize(a);

        auto obj = BigInteger("0");
        if (a.minus != b.minus) {
            if (a == b) {
            } else if (a > b) {
                obj = a.subtract(b);
                obj.minus = a.minus;
            } else {
                obj = b.subtract(a);
                obj.minus = b.minus;
            }
        } else {
            obj = a.add(b);
        }
        auto val = obj.toString();
        // cout << val << endl;
        return val == ans;
    }

    bool subtractTest(string s, string t, string ans) {
        auto a = BigInteger(s), b = BigInteger(t);

        a.resize(b);
        b.resize(a);

        b.minus = not b.minus;

        auto obj = BigInteger("0");
        if (a.minus != b.minus) {
            if (a == b) {
            } else if (a > b) {
                obj = a.subtract(b);
                obj.minus = a.minus;
            } else {
                obj = b.subtract(a);
                obj.minus = b.minus;
            }
        } else {
            obj = a.add(b);
        }
        auto val = obj.toString();
        // cout << val << endl;
        return val == ans;
    }

    bool multiplyTest(string s, string t, string ans) {
        auto a = BigInteger(s), b = BigInteger(t);

        auto obj = BigInteger("0");
        if (a.toString() == "0" or b.toString() == "0") {
        } else {
            obj = a.multiply(b);
        }
        auto val = obj.toString();
        // cout << val << endl;
        return val == ans;
    }

    bool divisionTest(string s, string t, string ans) {
        auto a = BigInteger(s), b = BigInteger(t);

        if (b.toString() == "0") {
            throw std::exception();
        }

        a.resize(b);
        b.resize(a);

        auto obj = BigInteger("0");
        if (a.toString() == "0") {
        } else {
            obj = a.divide(b);
        }
        auto val = obj.toString();
        // cout << "val:" << val << endl;
        return val == ans;
    }

    void solve() {
        vector<tuple<string, string, string>> xs = {
            {"1", "0", "1"},
            {"0", "1", "1"},
            {"-1", "-1", "-2"},
            {"-1", "1", "0"},
            {"1", "-1", "0"},
            {"2", "-3", "-1"},
            {"-3", "2", "-1"},
            {"-3", "12", "9"},
            {"12", "-3", "9"},
            {"1", "1", "2"},
            {"12", "900800700600500400300200100", "900800700600500400300200112"},
            {"900800700600500400300200100", "12", "900800700600500400300200112"},
            {"900800700600500400300200100", "10000000000000000000000000", "910800700600500400300200100"},
            {"900800700600500400300200100", "100000000000000000000000000", "1000800700600500400300200100"},
            {"900800700600500400300200100", "900800700600500400300200100", "1801601401201000800600400200"}
        };
        for (auto [s, t, u] : xs) {
            assert(addTest(s, t, u));
        }

        vector<tuple<string, string, string>> zs = {
            {"1", "0", "1"},
            {"1", "1", "0"},
            {"-1", "-1", "0"},
            {"-1", "1", "-2"},
            {"1", "-1", "2"},
            {"12", "3", "9"},
            {"900800700600500400300200100", "12", "900800700600500400300200088"},
            {"900800700600500400300200100", "10000000000000000000000000", "890800700600500400300200100"},
            {"900800700600500400300200100", "100000000000000000000000000", "800800700600500400300200100"},
            {"900800700600500400300200100", "900800700600500400300200100", "0"}
        };
        for (auto [s, t, u] : zs) {
            assert(subtractTest(s, t, u));
        }

        vector<tuple<string, string, string>> ys = {
            {"1", "0", "0"},
            {"0", "1", "0"},
            {"1", "1", "1"},
            {"-1", "0", "0"},
            {"12", "900800700600500400300200100", "10809608407206004803602401200"},
            {"900800700600500400300200100", "12", "10809608407206004803602401200"},
            {"12", "-900800700600500400300200100", "-10809608407206004803602401200"},
            {"900800700600500400300200100", "-12", "-10809608407206004803602401200"},
            {"-12", "900800700600500400300200100", "-10809608407206004803602401200"},
            {"-900800700600500400300200100", "12", "-10809608407206004803602401200"},
            {"900800700600500400300200100", "11", "9908807706605504403302201100"},
            {"900800700600500400300200100", "20", "18016014012010008006004002000"}
        };
        for (auto [s, t, u] : ys) {
            assert(multiplyTest(s, t, u));
        }

        vector<tuple<string, string, string>> ws = {
            {"1", "2", "0"},
            {"1234", "1234", "1"},
            {"1234", "-1234", "-1"},
            {"-1234", "1234", "-1"},
            {"-1234", "-1234", "1"},
            {"2", "1", "2"},
            {"2", "-1", "-2"},
            {"-2", "-1", "2"},
            {"-2", "1", "-2"},
            {"1234", "2467", "0"},
            {"1234", "-2467", "0"},
            {"2467", "1234", "1"},
            {"2468", "1234", "2"},
            {"2469", "1234", "2"},
            {"24690", "1234", "20"},
            {"24690000", "1234", "20008"},
        };
        for (auto [s, t, u] : ws) {
            assert(divisionTest(s, t, u));
        }
    }
};

int main(int argc, char **argv) {

    auto start = std::chrono::system_clock::now();
    Solver s;
    s.solve();
    auto end = std::chrono::system_clock::now();
    cout << "time:" << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << endl;

    return 0;
}
