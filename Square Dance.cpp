#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#define REP(a, i, n) for (int i = a; i < n; ++i)

long northCompassNeighbor(int *s, int i, int j, int c) {
    for (int k = i - 1; k >= 0; --k) {
        if (s[k * c + j] != 0) {
            return s[k * c + j];
        }
    }
    return 0;
}

long eastCompassNeighbor(int *s, int i, int j, int c) {
    for (int k = j + 1; k < c; ++k) {
        if (s[i * c + k] != 0) {
            return s[i * c + k];
        }
    }
    return 0;
}

long southCompassNeighbor(int *s, int i, int j, int r, int c) {
    for (int k = i + 1; k < r; ++k) {
        if (s[k * c + j] != 0) {
            return s[k * c + j];
        }
    }
    return 0;
}

long westCompassNeighbor(int *s, int i, int j, int c) {
    for (int k = j - 1; k >= 0; --k) {
        if (s[i * c + k] != 0) {
            return s[i * c + k];
        }
    }
    return 0;
}

struct Point {
    int r, c;
};

int main() {
    int t; cin >> t;
    for (int x = 1; x <= t; ++x) {
        int r, c; cin >> r >> c;
        int s[r * c];
        REP(0, i, r) REP(0, j, c) cin >> s[i * c + j];

        long interestLevel = 0;
        while (true) {
            vector<Point> eliminationList;
            REP(0, i, r) REP(0, j, c) {
                if (s[i * c + j] == 0) continue;

                interestLevel += s[i * c + j];

                long compassNeighbors = 0;
                int howManyNeighbors = 0;
                long east = eastCompassNeighbor(s, i, j, c);
                if (east != 0) {
                    compassNeighbors += east;
                    howManyNeighbors++;
                }
                long south = southCompassNeighbor(s, i, j, r, c);
                if (south != 0) {
                    compassNeighbors += south;
                    howManyNeighbors++;
                }
                long west = westCompassNeighbor(s, i, j, c);
                if (west != 0) {
                    compassNeighbors += west;
                    howManyNeighbors++;
                }
                long north = northCompassNeighbor(s, i, j, c);
                if (north != 0) {
                    compassNeighbors += north;
                    howManyNeighbors++;
                }
                if (compassNeighbors > howManyNeighbors * s[i * c + j]) {
                    eliminationList.push_back((Point){i, j});
                }
            }

            if (eliminationList.empty()) {
                break;
            } else {
                for (vector<Point>::iterator it = eliminationList.begin(); it != eliminationList.end(); ++it) {
                    s[it->r * c + it->c] = 0;
                }
            }
        }

        cout << "Case #" << x << ": " << interestLevel << endl;
    }

    return 0;
}
