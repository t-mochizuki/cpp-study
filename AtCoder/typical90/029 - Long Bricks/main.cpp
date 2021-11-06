// g++ -std=c++14 -DDEV=1 main.cpp
#include <stdio.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::vector;
using std::max;
using std::sort;
using std::map;
using std::make_pair;

// キーワード: 「座標圧縮」で効率化
//
// キーワード: 区間に対する処理は「セグメント木」

#define rep(i, a, n) for (int i = (a); i < (n); ++i)
#define bit(n, k) ((n >> k) & 1)

const long VALUE = 0;

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
        assert(i < N);
        assert(i >= 0);

        eval(i);

        int ret = VALUE;

        if (rhs <= L || R <= lhs) {
            ret = VALUE;
        } else if (lhs <= L && R <= rhs) {
            ret = value[i];
        } else {
            long lv = find(lhs, rhs, left(i), L, (L + R) / 2);
            long rv = find(lhs, rhs, right(i), (L + R) / 2, R);
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
            value[i] = max(value[left(i)], value[right(i)]);
        }
    }

public:

    RangeUpdateQuery(int len) {
        while (M < len) {
            M *= 2;
        }

        N = 2 * M - 1;

        value.assign(N, VALUE);
        lazy.assign(N, VALUE);
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

class Problem {
private:

    int W, N;
    vector<int> L, R;
    map<int, int> zip;

public:

    Problem() {
        cin >> W >> N;
        assert(2 <= W);
        assert(W <= 500000);
        assert(1 <= N);
        assert(N <= 250000);

        L.resize(N);
        R.resize(N);
        rep(i, 0, N) {
            cin >> L[i] >> R[i];

            assert(1 <= L[i]);
            assert(W >= L[i]);
            assert(1 <= R[i]);
            assert(W >= R[i]);
            assert(L[i] <= R[i]);
        }

        rep(i, 0, N) {
            if (zip.find(L[i]) == zip.end()) {
                zip.insert(make_pair(L[i], 1));
            }
            if (zip.find(R[i]) == zip.end()) {
                zip.insert(make_pair(R[i], 1));
            }
        }

        int num = 1;
        for (auto it = zip.begin(); it != zip.end(); ++it) {
            it->second = num;
            num++;
        }
    }

    void fullSearch() {
        vector<int> height;
        height.assign(W+1, 0);

        rep(i, 0, N) {
            int maximum = 0;
            rep(j, zip[L[i]], zip[R[i]]+1) {
                maximum = max(height[j], maximum);
            }
            maximum++;

            cout << maximum << endl;

            rep(j, zip[L[i]], zip[R[i]]+1) height[j] = maximum;
        }
    }

    void solve() {
        vector<int> height;
        height.assign(W+1, 0);

        RangeUpdateQuery tree(zip.size()+5);

        rep(i, 0, N) {
            long x = tree.find(zip[L[i]], zip[R[i]]+1);
            x++;

            cout << x << endl;

            tree.update(x, zip[L[i]], zip[R[i]]+1);
        }
    }
};

int main() {

#ifdef DEV
    std::ifstream in("input");
    cin.rdbuf(in.rdbuf());

    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        Problem p;
        p.solve();
    }
#else
    Problem p;
    p.solve();
#endif

    return 0;
}
