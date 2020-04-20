#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)
#define REP1(i, n) for (int i = 1; i <= n; ++i)
#define REP2(i, n) for (int i = 2; i <= n; ++i)

vector<int> v;

void solve(int n) {
    REP2(base, n) REP2(exp, n) {
        int temp = pow(base, exp);
        // printf("base = %d, exp = %d, pow = %d\n", base, exp, temp);
        if (n >= temp) {
            v.push_back(temp);
        } else {
            break;
        }
    }
}

int main() {
    int X; // 1000
    scanf("%d", &X);

    if (X == 1) {
        printf("1\n");
        return 0;
    }

    solve(X);

    sort(v.begin(), v.end());

    printf("%d\n", v.back());

    return 0;
}
