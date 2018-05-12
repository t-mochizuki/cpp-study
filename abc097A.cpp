#include <stdio.h>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int abs(int n) {
    return (n > 0) ? n : -n;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (abs(c - a) <= d || (abs(c - b) <= d && abs(b - a) <= d)) printf("Yes\n");
    else printf("No\n");

    return 0;
}
