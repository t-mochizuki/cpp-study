#include <stdio.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::terminate;

const int INDEFINITE = 1000000007;

// 最小の移動数
int m[2001][901];

template<class T> inline T abs(T X) {
    return X > 0 ? X : -X;
}

template<class T> inline T min(T X, T Y) {
    return X < Y ? X : Y;
}

int dp(int pos, int r, int g, int b) {
    int rgb = r + g + b;
    if (rgb == 0) {
        return 0;
    }
    int index = pos + 1000;
    if (index == 2001) {
        return INDEFINITE - 1;
    }

    if (m[index][rgb] != INDEFINITE) {
        return m[index][rgb];
    }

    int takeIt, leaveIt;
    if (r != 0) {
        takeIt = dp(pos + 1, r - 1, g, b) + abs(pos - (-100));
        leaveIt = dp(pos + 1, r, g, b);
    } else if (g != 0) {
        takeIt = dp(pos + 1, r, g - 1, b) + abs(pos);
        leaveIt = dp(pos + 1, r, g, b);
    } else if (b != 0) {
        takeIt = dp(pos + 1, r, g, b - 1) + abs(pos - 100);
        leaveIt = dp(pos + 1, r, g, b);
    } else {
        terminate();
    }
    m[index][rgb] = min(takeIt, leaveIt);

    return m[index][rgb];
}

int main() {
    int r, g, b; cin >> r >> g >> b;
    for (int i = 0; i <= 2000; ++i) {
        for (int j = 0; j <= 900; ++j) {
            m[i][j] = INDEFINITE;
        }
    }

    dp(-1000, r, g, b);

    int ans = INDEFINITE;
    for (int i = 0; i <= 2000; ++i) {
        ans = min(ans, m[i][r + g + b]);
    }

    cout << ans << endl;

    return 0;
}
