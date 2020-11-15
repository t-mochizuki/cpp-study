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
    long n,k;
    cin>>n>>k;
    long a[n];
    for(long i=0;i<n;++i){cin>>a[i];};

    int b[40]={0};
    for(long i=0;i<40;++i)
    for(long x=0;x<n;++x){b[i]+=a[x]>>i&1L;}

    // for(long i=0;i<40;++i){i==39?(cout<<b[i]<<endl):(cout<<b[i]);}

    long x=0;
    for (long i=0;i<40;++i) {
        if (b[i]<(n+1)/2&&k>1L<<i) x+=1L<<i;
    }
    // cout<<"x="<<x<<endl;

    long ans=0;
    for(long i=0;i<n;++i){ans+=x^a[i];}
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
