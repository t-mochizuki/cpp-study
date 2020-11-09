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
    int k; cin >> k;
    int ans = 0;
    int tmp = 7;
    for (int i = 0; i < k; ++i) {
        tmp%=k;
        if (tmp==0) {
            ans=i+1;
            break;
        }
        tmp*=10;
        tmp+=7;
    }
    cout << (ans==0?-1:ans) << endl;
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
