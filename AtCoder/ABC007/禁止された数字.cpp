#include <stdio.h>
#include <iostream>
// #include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

void solve() {
    long A, B; cin >> A >> B;
    long cnt = 0;
    for (long i = A; i <= B; ++i) {
        long quotient = i;
        while (quotient > 0) {
            int remainder = quotient % 10;
            if (remainder == 4 || remainder == 9) {
                cnt++;
                break;
            }
            quotient /= 10;
        }
    }
    cout << cnt << endl;
}

int main() {
    // std::ifstream in("AtCoder/ABC007/禁止された数字.input");
    // cin.rdbuf(in.rdbuf());

    // int t; cin >> t;
    // for (int x = 1; x <= t; ++x) {
    //     solve();
    // }

    solve();

    return 0;
}
