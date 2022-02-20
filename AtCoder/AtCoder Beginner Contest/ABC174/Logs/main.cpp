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

long calc(int x, int n, int* a) {
    long ret=0;
    for (int i=0;i<n;++i) {
        ret+=((a[i]+x-1)/x)-1;
    }
    return ret;
}

void solve() {
    int n,k;cin>>n>>k;
    int a[n];
    for (int i=0;i<n;++i) { cin>>a[i]; }
    sort(a,a+n);

    if (a[n-1]>10000) {
        terminate();
    }

    // 丸太の長さを決めると、丸太を切る回数が決まる
    long ans=0;
    for (int x=a[n-1];x>=1;--x) {
        if (calc(x,n,a)<=k) {
            ans=x;
        } else {
            break;
        }
    }

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
