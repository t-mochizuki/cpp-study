#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 100;
const int INFTY = (1<<21);
int d[MAX]; // distance
int m[MAX][MAX]; // adjacency matrices

int n;

void bfs(int s) {
    queue<int> q;
    q.push(s);

    for (int i = 0; i < n; ++i) d[i] = INFTY;
    d[s] = 0;

    int u;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int v = 0; v < n; ++v) {
            if (m[u][v] == 0) continue;
            if (d[v] != INFTY) continue;
            d[v] = d[u] + 1;
            q.push(v);
        }
    }
}

int main() {
    int u, v; // vertex
    int k; // degree

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            m[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &u, &k);
        u--;

        for (int j = 0; j < k; ++j) {
            scanf("%d", &v);
            v--;
            m[u][v] = 1;
        }
    }

    bfs(0);

    for (int i = 0; i < n; ++i) {
        printf("%d %d\n", i + 1, d[i] == INFTY ? -1 : d[i]);
    }

    return 0;
}

/*
Input:
4
1 2 2 4
3 0
2 1 4
4 1 3

Output:
1 0
2 1
3 2
4 1
*/
