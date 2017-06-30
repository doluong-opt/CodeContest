/***********************************************
* Author - LUONG VAN DO                        *
* 1102 - Problem Makes Problem ->AC
* Algorithm Combinations
* Time Limit 0.887s
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
#define maxN 2000005

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, k;
int64 x, y, d;
int64 f[maxN], g[maxN];
void extendedEuclid(int64 a, int64 b) {
    if (b == 0) {
        x = 1; y = 0; d = a;
        return;        
    }
    extendedEuclid(b, a % b);
    int64 x1 = y;
    int64 y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}
void init() {
    f[0] = 1;
    g[0] = 1;
    FOR(i, 1, 2000000) {
        f[i] = ((f[i-1] % INF) * i) % INF;
        extendedEuclid(f[i], INF);
        while (x < 0) x+=INF;
        g[i] = x;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    init();
    uint64 ans;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&n,&k);
        ans = ((( (f[n+k-1] % INF) * (g[k-1] % INF) ) % INF) * (g[n] % INF)) % INF;
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}
