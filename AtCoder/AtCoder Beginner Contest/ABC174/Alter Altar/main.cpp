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

template<class T> inline void swap(T &A, T &B) {
    T tmp = A;
    A = B;
    B = tmp;
}

void solve() {
    int n; cin >> n; // 2 <= n <= 200000
    string c; cin >> c;

    // すべて同じか？
    bool all = true;
    for (int i = 1; i < n; ++i) {
        if (c[i]!=c[i-1]) {
            all=false;
            break;
        }
    }
    if (all) {
        cout << 0 << endl;
        return ;
    }

    int l = 0, r = n-1;
    int ans = 0;
    while (l<n&&r>=0&&l<r) {
        // 一番左の白を探す
        while (l<n&&c[l]=='R') l++;

        if (l==n-1||c[l]=='R') break;

        // 一番右の赤を探す
        while (r>=0&&c[r]=='W') r--;

        if (r==0||c[r]=='W') break;

        if (l>=r) break;

        swap(c[l], c[r]);
        ans++;
        l++; r--;
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
