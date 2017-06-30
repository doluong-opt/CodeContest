// =============================================================================
// Author LUONG VAN DO
// Problem
// Algorithm
// Time Limit
// =============================================================================
#include <iostream>
#include <stdio.h>
#include <cstring>
#define fillarr(arr, c) memset(arr, c, sizeof(arr))
#define N 100001
using namespace std;
struct Edge{
        int to, next;
}edge[2 * N];
int cntEdge, cnt;
int head[N], visit[N];
void init() {
        fillarr(head, -1);
        fillarr(edge, 0);
        cntEdge = 0;
}
void addEdge(int x, int y) {
        edge[cntEdge].to = y; edge[cntEdge].next = head[x]; head[x] = cntEdge++;
}
void run(int u) {
        visit[u] = 1;
        if (head[u] == -1) return;
        for (int i = head[u]; i != -1; i = edge[i].next) {
                int v = edge[i].to;
                if (!visit[v]) {
                        cnt++;
                        run(v);
                }
        }
}
main() {
        int n, k, m, x;
        scanf("%d %d", &n, &k);
        init();
        for (int i = 1;i <= n;i++) {
                scanf("%d", &m);
                for (int j = 0;j < m;j++) {
                        scanf("%d", &x);
                        addEdge(i, x);
                }
                visit[i] = 0;
        }
        cnt = 1; run(1);
        printf("%d\n", cnt);
        for (int i = 1;i <= n;i++)
                if (visit[i]) printf("%d ", i);
}
