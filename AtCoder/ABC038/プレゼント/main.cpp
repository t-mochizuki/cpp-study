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

const int INF = 1 << 30;

template<class T> inline T max(T X, T Y) {
    return X > Y ? X : Y;
}

class Box {
public:
    int _w{INF};
    int _h{INF};

    Box() {}
    Box(int w, int h)
        : _w(w), _h(h) {}
    bool operator<(const Box& rhs) const {
        if (_w < rhs._w) {
            return true;
        } else if (_w == rhs._w) {
            if (_h < rhs._h) {
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

    if (n>1000) {
        terminate();
    }

    sort(boxes,boxes+n);

    // for (int i = 0; i < n; ++i) {
    //     cout<<boxes[i]._w<<" "<<boxes[i]._h<<endl;
    // }

    int dp[n];dp[0]=0;
    for (int i=1;i<n;++i) {
        dp[i]=0;
        for (int j=0;j<i;++j) {
            if (boxes[i]._w>boxes[j]._w&&boxes[i]._h>boxes[j]._h) {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }

    int ans=0;
    ans=*(max_element(dp,dp+n));
    cout<<ans+1<<endl;
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
