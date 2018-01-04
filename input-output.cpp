#include <iostream>

using namespace std;

const int MAX = 10;
int n, m;
int a[MAX], b[MAX];

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < m; ++i) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < n; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    for (int i = 0; i < m; ++i) {
        printf("b[%d] = %d\n", i, b[i]);
    }

    return 0;
}
