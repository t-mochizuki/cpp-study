#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    printf("%d\n", N % 2 == 0 ? N : N * 2);

    return 0;
}
