#include <stdio.h>
#include <functional>
#include <algorithm>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    int n; // 2 or 3
    scanf("%d", &n);

    int a[n];
    REP(0, i, n) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n, greater<int>());

    REP(1, i, a[0] / 2) {
        bool f = true;
        REP(0, j, n) {
            if (a[j] % i != 0) {
                f = false;
                break;
            }
        }
        if (f) printf("%d\n", i);
    }



    return 0;
}
