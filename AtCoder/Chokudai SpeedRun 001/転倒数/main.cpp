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

// Binary Indexed Tree
// cf. http://hos.ac/slides/20140319_bit.pdf
int n;
int bit[100005];

void add(int a, int w) {
    for (int x = a; x <= n; x += x & -x) bit[x] += w;
}

int sum(int a) {
    int ret = 0;
    for (int x = a; x > 0; x -= x & -x) ret += bit[x];
    return ret;
}

void solve() {
    cin >> n;
    long a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < 100005; ++i) {
        bit[i]=0;
    }
    long ans = 0;
    for (int i = 0; i < n; ++i) {
        add(a[i],1);
        ans+=i-sum(a[i]-1);
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
