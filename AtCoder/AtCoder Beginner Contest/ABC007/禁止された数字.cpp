#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
// #include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::string;
using std::to_string;
using std::vector;

long digitDP(string num) {
    long dp[100][2][2];
    for (int digit = 0; digit < 100; ++digit) {
        for (int smaller = 0; smaller < 2; ++smaller) {
            for (int appeared = 0; appeared < 2; ++appeared) {
                dp[digit][smaller][appeared] = 0;
            }
        }
    }
    dp[0][0][0] = 1;

    vector<int> vec;
    for (auto n : num) {
        vec.push_back(n - '0');
    }

    int l = num.size();
    for(int digit = 0; digit < l; ++digit){
        for(int smaller = 0; smaller < 2; ++smaller){
            for(int appeared = 0; appeared < 2; ++appeared){
                for(int x = 0; x <= (smaller ? 9 : vec[digit]); ++x){
                    dp[digit + 1][smaller || x < vec[digit]][appeared || x == 4 || x == 9] += dp[digit][smaller][appeared];
                }
            }
        }
    }

    return dp[l][0][1] + dp[l][1][1];
}

void solve() {
    long A; cin >> A; A--;
    string B; cin >> B;

    cout << digitDP(B) - digitDP(to_string(A)) << endl;
}

int main() {
    // std::ifstream in("AtCoder/ABC007/禁止された数字.input");
    // cin.rdbuf(in.rdbuf());
    //
    // int t; cin >> t;
    // for (int x = 1; x <= t; ++x) {
    //     solve();
    // }

    solve();

    return 0;
}
