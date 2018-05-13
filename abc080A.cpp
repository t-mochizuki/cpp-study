#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;

#define rep(a, i, n) for (int i = a; i <= n; ++i)

int main() {
    int N, A, B; // 20, 100, 2000
    scanf("%d %d %d", &N, &A, &B);

    printf("%d\n", min(B, N * A));

    return 0;
}
