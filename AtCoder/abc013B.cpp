#include <stdio.h>

using namespace std;

int min(int X, int Y) {
    return X < Y ? X : Y;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int clockwise = 0;
    while ((a + clockwise) % 10 != b) {
        clockwise++;
    }

    int counterclockwise = 0;
    while (a != (b + counterclockwise) % 10) {
        counterclockwise++;
    }

    printf("%d\n", min(clockwise, counterclockwise));

    return 0;
}
