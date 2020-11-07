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

void solve() {
    int n; cin >> n;
    long a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long acc[n];
    for (int i = 0; i < n; ++i) {
        if (i==0) {
            acc[i]=a[i];
        } else {
            acc[i]=acc[i-1]+a[i];
        }
    }
    long ans = 0;
    int j = -1;
    for (int i = 0; i < n;) {
        long v = (j==-1) ? acc[i] : acc[i]-acc[j];
        if (v==n) {
            ans++;
            i++;
        } else if (v>n) {
            j++;
        } else {
            i++;
        }
    }
    cout << ans << endl;
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
