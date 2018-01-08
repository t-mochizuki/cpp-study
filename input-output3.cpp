#include <iostream>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int a[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < N; ++i) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    return 0;
}
