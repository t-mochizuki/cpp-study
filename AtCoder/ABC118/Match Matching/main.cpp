// TODO: WA
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

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
using std::greater;

const int INF = 1000000000;

const int num[10] = {0,2,5,5,4,5,6,3,7,6};

template<class T> inline T max(T X, T Y) {
    return X > Y ? X : Y;
}

void solve() {
    int n,m; cin>>n>>m;
    int a[m];
    for (int i=0;i<m;++i) {
        cin>>a[i];
    }
    int dp[n+1];
    for (int i=0;i<=n;++i) {
        dp[i]=-INF;
    }
    dp[0]=0;
    for (int i=1;i<=n;++i) {
        for (int j=0;j<m;++j) {
            if (i-num[a[j]]>=0) {
                dp[i]=max(dp[i-num[a[j]]]+1,dp[i]);
            }
        }
    }
    // for (int i=1;i<=n;++i) {
    //     cout<<i<<":"<<dp[i]<<endl;
    // }
    sort(a,a+m,greater<int>());
    int i=0;
    while (n!=0&&i<m) {
        if (dp[n-num[a[i]]]==dp[n]-1) {
            cout << a[i];
            n-=num[a[i]];
        } else {
            i++;
        }
    }
    cout << endl;
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
