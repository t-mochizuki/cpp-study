#include <cstdio>

const int MAX = 20;
int n, k;
int a[MAX];

bool dfs(int i, int sum) {
    // if (sum == k) return true;
    if (i == n) return sum == k;

    if (dfs(i + 1, sum)) return true;
    if (dfs(i + 1, sum + a[i])) return true;

    return false;
}

int main() {

    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &k);

    if (dfs(0, 0)) printf("Yes\n");
    else printf("No\n");

    return 0;
}

/*
Input:
4
1 2 3 7
13

Output:
Yes

Input:
4
1 2 3 4
13

Output:
No
*/
