#include <stdio.h>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int h = N / 3600;
    if (h != 0) {
        N -= h * 3600;
    }

    int m = N / 60;
    if (m != 0) {
        N -= m * 60;
    }

    printf("%02d:%02d:%02d\n", h, m, N);

    return 0;
}
