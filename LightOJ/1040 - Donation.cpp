/***********************************************
* Author - LUONG VAN DO                        *
* 1040 - Donation ->AC
* Algorithm kruskal
* Time Limit 0.019s
* *********************************************/
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
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 2500

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct state{
    int x, y, w;
    state(){}
    state(int xx, int yy, int ww){
        x = xx; y = yy; w = ww;
    }
    bool operator < (const state &other) const{
        return (w < other.w);
    }
};
int n, m, sum;
state edge[maxN + 5];
int Lab[maxN + 5], a[maxN + 5][maxN + 5];
int Get(int v) {
    if ( Lab[v] < 0) return v;
    else return Lab[v] = Get( Lab[v] );
}
void Union(int r1, int r2){
    int x = Lab[r1] + Lab[r2];
    if ( Lab[r1] > Lab[r2] ) {
        Lab[r2] = x;
        Lab[r1] = r2;
    }
    else {
        Lab[r1] = x;
        Lab[r2] = r1;
    }
}
int kruskal() {
    int res, cnt;
    res = cnt = 0;
    FOR(i, 1, n)
        Lab[i] = -1;
    REP(i, m) {
        int nx = Get( edge[i].x );
        int ny = Get( edge[i].y );
        if ( nx != ny ) {
            Union(nx, ny);
            res+=edge[i].w;
            if (++cnt == n - 1) break;
        }
    }
    if ( cnt != n - 1 ) return -1;
    else return sum - res;
}
void Read() {
    int test;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        m = sum = 0;
        FOR(i, 1, n)
            FOR(j, 1, n) {
                scanf("%d",&a[i][j]);
                sum+=a[i][j];
            }
        FOR(i, 1, n - 1)
            FOR(j, i + 1, n)
                    if (a[i][j] && a[j][i]) edge[m++] = state(i, j, min(a[i][j], a[j][i]));
                else
                    if (a[i][j]) edge[m++] = state(i, j, a[i][j]);
                else
                    if (a[j][i]) edge[m++] = state(i, j, a[j][i]);
        sort(edge, edge+m);
        printf("Case %d: %d\n",t,kruskal());
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
