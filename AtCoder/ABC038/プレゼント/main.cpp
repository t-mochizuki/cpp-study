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
using std::max_element;

template<class T> inline T max(T X, T Y) {
    return X > Y ? X : Y;
}

// Binary Indexed Tree, BIT, Fenwick Tree
// cf. https://ikatakos.com/pot/programming_algorithm/data_structure/binary_indexed_tree
class Fenwick {
    public:

    int _n;
    int bit[100005];

    Fenwick(int n): _n(n) {
        for (int i = 0; i < 100005; ++i) {
            bit[i] = 0;
        }
    }

    void update(int i, int a) {
        for (int x = i; x <= _n; x += x & -x) bit[x] = max(a, bit[x]);
    }

    int query(int i) {
        int ret = 0;
        for (int x = i; x > 0; x -= x & -x) ret = max(ret, bit[x]);
        return ret;
    }

    void print() {
        for (int i = 0; i < 10; ++i) {
            if (i == 9) {
                cout << bit[i] << endl;
            } else {
                cout << bit[i] << " ";
            }
        }
    }

};

const int INF = 1 << 30;

class Box {
    public:

    int _w{INF};
    int _h{INF};

    Box() {}
    Box(int w, int h)
        : _w(w), _h(h) {}
    bool operator<(const Box& r) const {
        if (_h<r._h) {
            return true;
        } else if (_h==r._h) {
            if (_w>r._w) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
};

void solve() {
    int n;cin>>n;
    Box boxes[n];
    int w,h;
    for (int i=0;i<n;++i) {
        cin>>w>>h;
        Box b(w,h);
        boxes[i]=b;
    }

    sort(boxes,boxes+n);
    // sort(boxes,boxes+n,[](const Box& l,const Box& r) { return l._w>r._w; });

    // for (int i = 0; i < n; ++i) {
    //     cout<<boxes[i]._w<<" "<<boxes[i]._h<<endl;
    // }

    int dp[n+1];
    for (int i=0;i<=n;++i) {
        dp[i]=0;
    }

    Fenwick bit(100005);
    for (int i=1;i<=n;++i) {
        // wが降順なので、hが同じ箱は入れ子にならない
        dp[i]=bit.query(boxes[i-1]._w-1)+1;
        bit.update(boxes[i-1]._w,dp[i]);
    }

    // bit.print();

    int ans=0;
    ans=*(max_element(dp,dp+n+1));
    cout<<ans<<endl;
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
