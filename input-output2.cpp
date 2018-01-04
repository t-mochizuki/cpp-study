#include <iostream>

using namespace std;

int n, m;
const int MAX_N = 100;
const int MAX_M = 100;
char field[MAX_N][MAX_M + 1];

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {
        scanf("%s", field[i]);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%c\n", field[i][j]);
        }
    }

    return 0;
}
