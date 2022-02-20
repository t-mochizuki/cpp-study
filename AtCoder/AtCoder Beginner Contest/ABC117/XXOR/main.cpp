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

long f(long x, long n, long* a) {
    long ret=0;
    for(long i=0;i<n;++i){ret+=x^a[i];}
    return ret;
}

void solve() {
    long n,k;
    cin>>n>>k;
    long a[n];
    for(long i=0;i<n;++i){cin>>a[i];};

    long x=0;
    for (long i=40;i>=0;--i) {
        long tmp=x+(1L<<i);
        if (tmp<=k) {
            long f1=f(x,n,a);
            long f2=f(tmp,n,a);
            if (f2>f1) x=tmp;
        }
    }

    cout<<f(x,n,a)<<endl;
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
