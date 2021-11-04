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
using std::min;

const long INF = (1L<<31)-1;

class RangeMinimumQuery {
private:

    int M = 1;
    int N;
    vector<long> value;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    int query(int lhs, int rhs, int i, int L, int R) {
        int ret = INF;

        if (rhs <= L || R <= lhs) {
            ret = INF;
        } else if (lhs <= L && R <= rhs) {
            ret = value[i];
        } else {
            int lv = query(lhs, rhs, left(i), L, (L + R) / 2);
            int rv = query(lhs, rhs, right(i), (L + R) / 2, R);
            ret = min(lv, rv);
        }

        return ret;
    }

public:

    RangeMinimumQuery(int len) {
        while (M < len) {
            M *= 2;
        }

        N = 2 * M - 1;

        value.assign(N, INF);
    }

    void update(int i, long x) {
        assert(i < M);
        assert(i >= 0);

        i += M - 1;
        value[i] = x;

        while (i > 0) {
            i = parent(i);
            value[i] = min(value[left(i)], value[right(i)]);
        }
    }

    int find(int lhs, int rhs) {
        int root = 0; // 葉の数はM、区間は[0, M)
        return query(lhs, rhs, root, 0, M);
    }
};

void solve() {
    int n, q; cin >> n >> q;

    RangeMinimumQuery tree(n);

    for (int i = 0; i < q; ++i) {
        int command; cin >> command;
        long x, y; cin >> x >> y;
        if (command == 0) {
            tree.update(x, y);
        } else {
            cout << tree.find(x, y+1) << endl;
        }
    }
}

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        solve();
    }
#else
    solve();
#endif

    return 0;
}
