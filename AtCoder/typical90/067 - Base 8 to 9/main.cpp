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

// キーワード: N進数展開を理解しよう

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

long pow(long base, long exponent) {
    if (exponent == 0) return 1;

    if (exponent % 2 == 1) {
        return base * pow(base, exponent - 1);
    } else {
        long tmp = pow(base, exponent / 2);
        return tmp * tmp;
    }
}

class Program {
private:

    string s;
    vector<int> n8, n9;
    int k;

public:

    Program() {
        cin >> s >> k;

        n8.resize(s.size());
        rep(i, 0, s.size()) {
            n8[s.size()-1-i] = (int)(s[i] - '0');
        }

        // rep(i, 0, n8.size()) {
        //     cout << i << ":" << n8[i] << endl;
        // }
    }

    void solve() {
        rep(j, 0, k) {
            long tmp = 0;
            for (long i = 0; i < n8.size(); ++i) {
                tmp += n8[i] * pow(8L, i);
            }

            // cout << "tmp:" << tmp << endl;

            if (tmp == 0) {
                cout << 0 << endl;
                return ;
            } else {
                while (tmp > 0) {
                    int r = tmp % 9;
                    n9.push_back(r);
                    tmp /= 9;
                }
            }


            // rep(i, 0, n9.size()) {
            //     cout << i << ":" << n9[i] << endl;
            // }

            // 8の部分を5に書き直す
            for (int i = n9.size()-1; i >= 0; --i) {
                if (n9[i] == 8) {
                    n9[i] = 5;
                }
            }

            n8 = n9;
            n9.clear();
        }

        for (int i = n8.size()-1; i >= 0; --i) {
            if (i == n8.size()-1) {
                if (n8[i] != 0) {
                    cout << n8[i];
                }
            } else {
                cout << n8[i];
            }
        }
        cout << endl;
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
