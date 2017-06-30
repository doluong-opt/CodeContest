// =============================================================================
// Author LUONG VAN DO
// Problem
// Algorithm
// Time Limit
// =============================================================================
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fillarr(arr, c) memset(arr, c, sizeof(arr))
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 100000

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct Edge{
        int to, next;
}edge[2 * N];

int n,m, u, v, ans;
int cntEdge, head[N];
int cnt[N];

void init() {
        fillarr(head, -1);
        fillarr(edge, 0);
        cntEdge = 0;
}
void addEdge(int u, int v) {
        edge[cntEdge].to = v; edge[cntEdge].next = head[u]; head[u] = cntEdge++;
        edge[cntEdge].to = u; edge[cntEdge].next = head[v]; head[v] = cntEdge++;
}
void run(int u, int par) {
        cnt[u] = 1;
        for (int i = head[u]; i != -1; i = edge[i].next) {
                int v = edge[i].to;
                if (v != par) {
                        run(v, u);
                        cnt[u] += cnt[v];
                }
        }
}
int main() {
        //freopen("exam.inp","r", stdin);
        //freopen("exam.out","w", stdout);
        scanf("%d %d", &n, &m);
        init();
        for (int i = 0;i < m;i++) {
                scanf("%d %d", &u, &v);
                addEdge(u, v);
        }
        run(1, -1);
        ans = 0;
        for (int i = 2;i <= n;i++) if (cnt[i] % 2 == 0) ans++;
        printf("%d\n", ans);
        //for (int i = 2;i <= n;i++) cout<<i<<" "<<cnt[i]<<endl;
        return 0;
}
