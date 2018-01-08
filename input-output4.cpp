#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int a[N][M];
    memset(a, 0, sizeof(a));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (j == 0) printf("a[%d][%d] = %d", i, j, a[i][j]);
            else printf(", a[%d][%d] = %d", i, j, a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

