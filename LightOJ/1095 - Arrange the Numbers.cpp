/***********************************************
* Author - LUONG VAN DO                        *
* 1095 - Arrange the Numbers ->AC
* Algorithm dp
* Time Limit 0.009s
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
#define maxN 1010

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
uint64 c[maxN][maxN];
uint64 fact[maxN];
int N, M, K;
void init() {
    fact[0] = 1;
    FOR(i, 1, maxN - 1) fact[i] = (i * fact[i-1]) % INF;
    FOR(i, 0, 1000) c[i][0] = 1;
    FOR(i, 0, 1000)
        FOR(j, 0, 1000)
            if (j > i) c[i][j] = 0;
        else
            if (i == j) c[i][j] = 1;
        else
            c[i][j] = (c[i-1][j-1] % INF + c[i-1][j] % INF) % INF;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    uint64 xx, a, y;
    int64 yy;
    init();
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d %d",&N,&M,&K);
        xx = c[M][K];
        a = M - K;
        y = N - K;
        yy = 0;
        for (int i=0;i<=a;i++) {
            if (i & 1) yy-=(c[a][i] * fact[y] ) % INF;
            else yy+=(c[a][i] * fact[y]) % INF;
            y--;
        }
        while (yy < 0) yy+=INF;
        yy%=INF;
        printf("Case %d: %lld\n",t,(xx * yy ) % INF);
    }
    return 0;
}
