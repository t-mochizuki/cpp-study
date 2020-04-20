#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int c = a % b;

    printf("%d\n", c == 0 ? 0 : b - c);

    return 0;
}
