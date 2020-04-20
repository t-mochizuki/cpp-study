#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

int main() {
    string a, b;
    cin >> a >> b;

    string c = a + b;
    int temp = atoi(c.c_str());
    REP(1, i, 317) {
        if (temp == pow(i, 2)) {
            printf("Yes\n");
            return 0;
        }
    }

    printf("No\n");

    return 0;
}
