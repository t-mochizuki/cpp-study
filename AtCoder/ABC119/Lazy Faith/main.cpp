#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::vector;
using std::map;
using std::make_pair;
using std::sort;
using std::to_string;
using std::lower_bound;
using std::distance;

template<class T> inline T abs(T X) {
    return X > 0 ? X : -X;
}

template<class T> inline T min(T X, T Y) {
    return X < Y ? X : Y;
}

class Range {
public:
    long _lhs;
    long _rhs;
    Range(long lhs, long rhs) : _lhs(lhs), _rhs(rhs) {}
};

const long INF = 100000000000;

Range search(long* s, int a, long x) {
    long lhs=INF, rhs=INF;
    auto it=lower_bound(s,s+a,x);
    if (it!=s+a) {
        int r=distance(s,it);
        rhs=s[r];
        if (r!=0) {
            lhs=s[r-1];
        }
    } else {
        lhs=s[a-1];
    }

    return Range(lhs,rhs);
}

void solve() {
    int a, b, q; cin >> a >> b >> q;
    long s[a];
    for (int i = 0; i < a; ++i) cin >> s[i];
    long t[b];
    for (int i = 0; i < b; ++i) cin >> t[i];
    long x[q];
    for (int i = 0; i < q; ++i) cin >> x[i];


    for (int i = 0; i < q; ++i) {
        Range sr=search(s,a,x[i]);
        // cout << sr._lhs << " " << sr._rhs << endl;
        Range tr=search(t,b,x[i]);
        // cout << tr._lhs << " " << tr._rhs << endl;

        long r2r=min(abs(sr._rhs-x[i])+abs(tr._rhs-sr._rhs),abs(tr._rhs-x[i])+abs(sr._rhs-tr._rhs));
        long r2l=min(abs(sr._rhs-x[i])+abs(tr._lhs-sr._rhs),abs(tr._rhs-x[i])+abs(sr._lhs-tr._rhs));
        long l2l=min(abs(sr._lhs-x[i])+abs(tr._lhs-sr._lhs),abs(tr._lhs-x[i])+abs(sr._lhs-tr._lhs));
        long l2r=min(abs(sr._lhs-x[i])+abs(tr._rhs-sr._lhs),abs(tr._lhs-x[i])+abs(sr._rhs-tr._lhs));

        cout << min(r2r,min(r2l,min(l2l,l2r))) << endl;
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
