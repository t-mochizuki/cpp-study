#include <cstdio>
#include <algorithm>

using namespace std;

const int V[6] = {1, 5, 10, 50, 100, 500};
int c[6];
int a;

void solve() {
    int ans;
    for (int i = 5; i >= 1; --i) {
        int t = min(c[i], a / V[i]);
        a -= t * V[i];
        ans += t;
    }
    printf("%d\n", ans);
}

int main() {
    for (int i = 0; i < 6; ++i) {
        scanf("%d", &c[i]);
    }

    scanf("%d", &a);

    solve();

    return 0;
}

/*
Input:
3 2 1 3 0 2 620

Output:
5
*/
