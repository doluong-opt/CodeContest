/***********************************************
* Author - LUONG VAN DO                        *
* 1052 - String Growth ->AC
* Algorithm matrix
* Time Limit 0.002s
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
#define INF 1000000007
#define maxN 51

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int64, int64> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, x, m, y, k, nm;
int64 ma[maxN][5];
int64 ff[maxN];
void init() {
    ma[1][0] = 1; ma[1][1] = 1;
    ma[1][2] = 1; ma[1][3] = 0;
    FOR(i, 2, 32) {
        ma[i][0] = ((ma[i-1][0] * ma[i-1][0]) % INF + (ma[i-1][1] * ma[i-1][2]) % INF) % INF;
        ma[i][1] = ((ma[i-1][0] * ma[i-1][1]) % INF + (ma[i-1][1] * ma[i-1][3]) % INF) % INF;
        ma[i][2] = ma[i][1];
        ma[i][3] = ((ma[i-1][2] * ma[i-1][1]) % INF + (ma[i-1][3] * ma[i-1][3]) % INF) % INF;
    }
    ff[0] = 0; ff[1] = 1;
    FOR(i, 2, 40)
        ff[i] = ff[i-1] + ff[i-2];
}
int64 solve(ii ans) {
    int p[maxN];
    int64 tmp[] = {1, 0, 0, 1};
    int64 f[6];
    nm = 0;
    while ( k ) {
        p[nm++] = k % 2;
        k>>=1;
    }
    REP(i, nm) {
        if (!p[i]) continue;
        f[0] = ((ma[i+1][0] * tmp[0]) % INF + (ma[i+1][1] * tmp[2]) % INF) % INF;
        f[1] = ((ma[i+1][0] * tmp[1]) % INF + (ma[i+1][1] * tmp[3]) % INF) % INF;
        f[2] = f[1];
        f[3] = ((ma[i+1][2] * tmp[1]) % INF + (ma[i+1][3] * tmp[3]) % INF) % INF;
        tmp[0] = f[0];
        tmp[1] = f[1];
        tmp[2] = f[2];
        tmp[3] = f[3];
    }
    return ((ans.A * tmp[1]) % INF + (ans.B * tmp[0]) % INF) % INF;
}
ii check(){
    int64 a1, b1, a2, b2, c1, c2;
    a1 = ff[n]; b1 = ff[n+1]; c1 = -x;
    a2 = ff[m]; b2 = ff[m+1]; c2 = -y;
    int64 d, dx, dy;
    d = (int64)(a1 * b2) - (int64)(a2 * b1);
    dx = (int64)(b1 * c2) - (int64)(b2 * c1);
    dy = (int64)(a2 * c1) - (int64)(a1 * c2);
    if (d != 0 && dx % d == 0 && dy % d == 0 && dx / d >=0 && dy / d >=0 ) return ii(dx / d, dy / d);
    else return ii(-1, -1);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    ii nn;
    init();
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d %d %d %d",&n,&x,&m,&y,&k);
        printf("Case %d: ",t);
        if (n>=40 || m>=40) {
            printf("Impossible\n");
            continue;
        }
        nn = check();
        if (nn.A == -1 && nn.B == -1)
            printf("Impossible\n");
        else
            printf("%lld\n",solve(nn));
    }
    return 0;
}
