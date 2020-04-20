#include <stdio.h>

using namespace std;

const int limit = 50;
int N, M;
int a[limit], b[limit];

bool graph[limit][limit];
bool visited[limit];

void dfs(int v) {
    visited[v] = true;
    for (int v2 = 0; v2 < N; ++v2) {
        if (graph[v][v2] == false) continue;
        if (visited[v2] == true) continue;
        dfs(v2);
    }
}

int main() {

    scanf("%d %d", &N, &M);

    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &a[i], &b[i]);
        a[i]--, b[i]--;
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
    }

    int ans = 0;

    for (int i = 0; i < M; ++i) {
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = false;

        for (int j = 0; j < N; ++j) visited[j] = false;

        dfs(0);

        bool bridge = false;
        for (int j = 0; j < N; ++j) if (visited[j] == false) bridge = true;
        if (bridge == true) ans++;

        graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
    }

    printf("%d\n", ans);

    return 0;
}
