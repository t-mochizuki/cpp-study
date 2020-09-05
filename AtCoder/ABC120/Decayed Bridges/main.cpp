#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)
#define RREP(a, i, n) for (int i = n - 1; i >= a; --i)

void swap(int &A, int &B) {
    int T = A;
    A = B;
    B = T;
}

struct UnionFind {
    vector<int> parentOf;
    vector<long> sz;

    UnionFind(int N) {
        parentOf.resize(N);
        sz.resize(N, 1);
        REP(0, i, N) {
            parentOf[i] = i;
        }
    }

    int rootOf(int x) {
        int p = parentOf[x];
        if (p == x) {
            return p;
        } else {
            int r = rootOf(p);
            parentOf[x] = r;
            return r;
        }
    }

    bool isSame(int x, int y) {
        return rootOf(x) == rootOf(y);
    }

    bool merge(int x, int y) {
        int rx = rootOf(x);
        int ry = rootOf(y);
        if (rx == ry) {
            return false;
        } else {
            if (sz[rx] < sz[ry]) {
                swap(rx, ry);
            }

            sz[rx] += sz[ry];

            parentOf[ry] = rx;

            return true;
        }
    }

    long size(int x) {
        return sz[rootOf(x)];
    }
};

int main() {
    long N, M;
    cin >> N >> M;

    int A[M], B[M];
    REP(0, i, M) {
        cin >> A[i] >> B[i];
        --A[i]; --B[i];
    }

    UnionFind uf = UnionFind(N);
    long ans = N * (N - 1) / 2;
    vector<long> v;
    v.push_back(ans);
    RREP(0, i, M) {
        if (uf.isSame(A[i], B[i])) {
            v.push_back(ans);
        } else {
            ans -= uf.size(A[i]) * uf.size(B[i]);
            v.push_back(ans);
            uf.merge(A[i], B[i]);
        }
    }

    RREP(0, i, M) {
        printf("%ld\n", v[i]);
    }

    return 0;
}
