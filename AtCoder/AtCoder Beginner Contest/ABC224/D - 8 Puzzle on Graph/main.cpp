// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::map;
using std::string;
using std::queue;

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

class Program {
private:

    int m;
    vector<vector<int>> G;
    map<string, int> dist;
    queue<string> que;

    void swap(char &a, char &b) {
        char tmp = a;
        a = b;
        b = tmp;
    }

public:

    Program() {
        cin >> m;
        assert(m >= 0);
        assert(m <= 36);

        G.assign(10, vector<int>(0));

        rep(i, 0, m) {
            int u, v;
            cin >> u >> v;
            assert(u >= 1);
            assert(u <= 9);
            assert(v >= 1);
            assert(v <= 9);

            G[u].push_back(v);
            G[v].push_back(u);
        }

        // コマ9の9
        string s = "999999999";
        rep(j, 1, 9) {
            int p;
            cin >> p;
            s[p-1] = j + '0';
        }
        // cout << s << endl;

        que.push(s);

        dist[s] = 0;
    }

    int solve() {
        while (que.size()) {
            string s = que.front(); que.pop();

            int v;
            rep(i, 0, 9) {
                if (s[i] == '9') {
                    v = i+1;
                    break;
                }
            }

            for (auto u : G[v]) {
                string t = s;

                swap(t[u-1], t[v-1]);

                if (dist.count(t) == 1) {
                    continue;
                } else {
                    dist[t] = dist[s] + 1;
                    que.push(t);
                }

                // printf("t[%s]=%d\n", t.c_str(), dist[t]);
            }
        }

        if (dist.count("123456789") == 1) {
            cout << dist["123456789"] << endl;
        } else {
            cout << -1 << endl;
        }

        return 0;
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
