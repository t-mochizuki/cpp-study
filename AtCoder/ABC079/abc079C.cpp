#include <stdio.h>

using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

char sign(int op) { return (op == 0) ? '+' : '-'; }

int main() {
    char ABCD[5];
    scanf("%s", ABCD);

    int A = ABCD[0] - '0';
    int B = ABCD[1] - '0';
    int C = ABCD[2] - '0';
    int D = ABCD[3] - '0';

    char op1;
    char op2;
    char op3;

    REP(o1, 2) {
        int v = 0;
        REP(o2, 2) {
            REP(o3, 2) {
                op1 = sign(o1);
                v = (o1 == 0) ? A + B : A - B;
                op2 = sign(o2);
                v = (o2 == 0) ? v + C : v - C;
                op3 = sign(o3);
                v = (o3 == 0) ? v + D : v - D;
                // printf("%d%c%d%c%d%c%d=%d\n", A, op1, B, op2, C, op3, D, v);
                if (v == 7) break;
            }
            if (v == 7) break;
        }
        if (v == 7) break;
    }

    printf("%d%c%d%c%d%c%d=7\n", A, op1, B, op2, C, op3, D);

    return 0;
}
