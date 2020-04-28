#include <stdio.h>
#include <string>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)


int main() {
    string Dirs[17] = {
        "N",
        "NNE",
        "NE",
        "ENE",
        "E",
        "ESE",
        "SE",
        "SSE",
        "S",
        "SSW",
        "SW",
        "WSW",
        "W",
        "WNW",
        "NW",
        "NNW",
        "N",
    };

    // 0 <= Deg <= 3600
    int Deg, Dis;
    scanf("%d %d", &Deg, &Dis);

    string Dir = Dirs[(int)(Deg / 225.0 + 0.5)];

    double Win = ((int)(Dis / 60.0 * 10 + 0.5)) / 10.0;
    int W = -1;
    if (Win <= 0.2) {
        W = 0;
    } else if (Win <= 1.5) {
        W = 1;
    } else if (Win <= 3.3) {
        W = 2;
    } else if (Win <= 5.4) {
        W = 3;
    } else if (Win <= 7.9) {
        W = 4;
    } else if (Win <= 10.7) {
        W = 5;
    } else if (Win <= 13.8) {
        W = 6;
    } else if (Win <= 17.1) {
        W = 7;
    } else if (Win <= 20.7) {
        W = 8;
    } else if (Win <= 24.4) {
        W = 9;
    } else if (Win <= 28.4) {
        W = 10;
    } else if (Win <= 32.6) {
        W = 11;
    } else {
        W = 12;
    }

    if (W == 0) {
        printf("C 0\n");
        return 0;
    } else {
        printf("%s %d\n", Dir.c_str(), W);
    }


    return 0;
}
