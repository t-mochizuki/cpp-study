#include <stdio.h>
#include <iostream>
#include <fstream>
#include <map>

#define DEV 1

using std::cin;
using std::cout;
using std::endl;
using std::terminate;
using std::pair;
using std::make_pair;

template<class T> inline T min(T X, T Y) {
    return X < Y ? X : Y;
}

typedef pair<int, int> P;

long dp(int N, long H, long A, P p1, P p2, P p3) {
    if (N == 0) {
        return A;
    }

    if (H > p3.second) {
        return dp(N - 1, H - p3.second, A, p1, p2, p3);
    } else {
        long ret1 = dp(N - 1, H + p1.second, A + p1.first, p1, p2, p3);
        long ret2 = dp(N - 1, H + p2.second, A + p2.first, p1, p2, p3);
        return min(ret1, ret2);
    }
}

void solve() {
    int N; cin >> N; // 節約生活の日数
    long H; cin >> H; // 節約生活を始める前の高橋君の満腹度
    int A, B, C, D, E; cin >> A >> B >> C >> D >> E;
    pair<int, int> p1 = make_pair(A, B);
    pair<int, int> p2 = make_pair(C, D);
    pair<int, int> p3 = make_pair(0, E);

    if (N > 50) {
        terminate();
    }

    cout << dp(N, H, 0, p1, p2, p3) << endl;
}

int main() {

#ifdef DEV
    std::ifstream in("AtCoder/ABC012/節制.input");
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
