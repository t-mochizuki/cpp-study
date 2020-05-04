/*
g++ -std=c++11 CodeJam/Round\ 1C\ 2020/Oversized\ Pancake\ Choppers.cpp
*/
#include <stdio.h>
#include <iostream>
#include <map>
// #include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::map;

void solve(int x) {
    int N, D; cin >> N >> D;
    long A;
    map<long, int> m;
    for (int i = 1; i <= N; ++i) {
        cin >> A;
        decltype(m)::iterator it = m.find(A);
        if (it != m.end()) {
            it->second++;
        } else {
            m.emplace(A, 1);
        }
    }

    int cut = D - 1;
    if (D == 2) {
        for (decltype(m)::iterator it = m.begin(); it != m.end(); ++it) {
            if (it->second >= D) {
                cut = 0;
                break;
            }
        }
    } else if (D == 3) {
        for (decltype(m)::iterator it = m.begin(); it != m.end(); ++it) {
            if (it->second >= D) {
                cut = 0;
                break;
            }

            if (it->second == D - 1) {
                for (decltype(m)::iterator it2 = m.begin(); it2 != m.end(); ++it2) {
                    if (it2->first > it->first) {
                        cut = 1;
                        continue;
                    }
                }
            } else {
                for (decltype(m)::iterator it2 = m.begin(); it2 != m.end(); ++it2) {
                    if (it2->first == 2 * it->first) {
                        cut = 1;
                        continue;
                    }
                }
            }
        }
    } else {
        terminate();
    }

    printf("Case #%d: %d\n", x, cut);
}

int main() {
    // std::ifstream in("CodeJam/Round 1C 2020/Oversized Pancake Choppers.input");
    // cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve(x);
    }

    return 0;
}
