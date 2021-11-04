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
using std::max;

const long VALUE = (1L<<31)-1;

class RangeUpdateQuery {
private:

    int M = 1;
    int N;
    vector<long> value, lazy;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void eval(int i) {
        if (lazy[i] == VALUE) return ;

        if (i < M - 1) {
            lazy[left(i)] = lazy[i];
            lazy[right(i)] = lazy[i];
        }

        value[i] = lazy[i];
        lazy[i] = VALUE;
    }

    long find(int lhs, int rhs, int i, int L, int R) {
        // assert(i < M);
        assert(i >= 0);

        eval(i);

        int ret = VALUE;

        if (rhs <= L || R <= lhs) {
            ret = VALUE;
        } else if (lhs <= L && R <= rhs) {
            ret = value[i];
        } else {
            int lv = find(lhs, rhs, left(i), L, (L + R) / 2);
            int rv = find(lhs, rhs, right(i), (L + R) / 2, R);
            ret = max(lv, rv);
        }

        return ret;
    }

    void update(long x, int lhs, int rhs, int i, int L, int R) {
        assert(i < N);
        assert(i >= 0);

        eval(i);

        if (rhs <= L || R <= lhs) {
        } else if (lhs <= L && R <= rhs) {
            lazy[i] = x;
            eval(i);
        } else {
            update(x, lhs, rhs, left(i), L, (L + R) / 2);
            update(x, lhs, rhs, right(i), (L + R) / 2, R);
            // value[i] = max(value[left(i)], value[right(i)]);
            value[i] = x;
        }
    }

public:

    RangeUpdateQuery(int len) {
        // int len = (int)v.size();

        while (M < len) {
            M *= 2;
        }

        N = 2 * M - 1;

        value.assign(N, VALUE);
        lazy.assign(N, VALUE);

        // rep(i, 0, M) value[M-1+i] = v[i];
        //
        // for(int i = M - 2; i >= 0; --i) {
        //     value[i] = max(value[left(i)], value[right(i)]]);
        // }
    }

    long find(int i) {
        i += M - 1;

        eval(i);

        return value[i];
    }

    long find(int lhs, int rhs) {
        int root = 0; // 葉の数はM、区間は[0, M)
        return find(lhs, rhs, root, 0, M);
    }

    void update(long x, int lhs, int rhs) {
        int root = 0; // 葉の数はM、区間は[0, M)
        return update(x, lhs, rhs, root, 0, M);
    }
};

void solve() {
    int n, q; cin >> n >> q;
    assert(n <= 100000);
    assert(n >= 1);
    assert(q <= 100000);
    assert(q >= 1);

    RangeUpdateQuery tree(n);

    for (int p = 0; p < q; ++p) {
        int command; cin >> command;

        if (command == 0) {
            int lhs, rhs; cin >> lhs >> rhs;
            assert(lhs >= 0);
            assert(lhs <= rhs);
            assert(rhs < n);

            long x; cin >> x;
            assert(x >= 0);
            assert(x < VALUE);

            tree.update(x, lhs, rhs+1);
        } else {
            int i; cin >> i;
            assert(i >= 0);
            assert(i < n);

            cout << tree.find(i) << endl;
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
