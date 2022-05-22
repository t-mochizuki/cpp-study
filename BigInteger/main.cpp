// g++ -std=c++17 -D DEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include "BigInteger.h"

using namespace std;

#define rep(i, a, n) for (long i = (a); i < (n); ++i)

template<class T> istream& operator>>(istream& i, vector<T>& v) { rep(j, 0, v.size()) i >> v[j]; return i; }
template<class T> ostream& operator<<(ostream& o, vector<T>& v) { rep(j, 0, v.size()) { if (j == 0) o << v[j]; else o << " " << v[j]; } return o; }

ostream& operator<<(ostream& o, const BigInteger& v) { o << v.toString(); return o; }

unsigned int X = 542351;

int randDigit() {
    X = 443143 * X + 6412431;
    return X % 10;
}

void randInteger(vector<int>& v) {
    for (auto& x : v) x = randDigit();
}

class Solver {
private:

public:

    Solver() {
        vector<int> v;
        v.resize(1000000);
        randInteger(v);
        cout << v << endl;
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
