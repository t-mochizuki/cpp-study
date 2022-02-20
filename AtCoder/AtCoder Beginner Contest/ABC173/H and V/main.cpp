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

void solve() {
    int h,w,k;cin>>h>>w>>k;
    char c[h][w+1];
    for (int i=0;i<h;++i) for (int j=0;j<w;++j) { cin>>c[i][j]; }
    for (int i=0;i<h;++i) { c[i][w]='\0'; }
    // for (int i=0;i<h;++i) { cout<<c[i]<<endl; }

    int ans=0;
    for (int markR=0;markR<(1<<h);++markR) for (int markC=0;markC<(1<<w);++markC) {
        int black=0;
        for (int i=0;i<h;++i) for (int j=0;j<w;++j) {
            if (((markR>>i)&1)==0&&((markC>>j)&1)==0&&c[i][j]=='#') {
                black++;
            }
        }
        if (black==k) {
            ans++;
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
