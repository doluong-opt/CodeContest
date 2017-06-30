/***********************************************
* Author - LUONG VAN DO                        *
* 1169 - Monkeys on Twin Tower ->AC
* Algorithm dp
* Time Limit 0.018s
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
#define maxN 1005

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n;
int LTR[maxN + 5];
int RTL[maxN + 5];
int a[maxN], b[maxN];
int f[maxN], g[maxN];
void reset() {
    FOR(i, 1, n) LTR[i] = RTL[i] = 0;
    FOR(i, 1, n) {
        f[i] = g[i] = 0;
    }
}
int solve() {
    f[1] = a[1];
    g[1] = b[1];
    FOR(i, 2, n) {
        f[i] = min(f[i-1] + a[i], g[i-1] + RTL[i-1] + a[i]);
        g[i] = min(g[i-1] + b[i], f[i-1] + LTR[i-1] + b[i]);
    }
    return min( f[n] , g[n]);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        reset();
        FOR(i, 1, n) scanf("%d",&a[i]);
        FOR(i, 1, n) scanf("%d",&b[i]);
        FOR(i, 1, n - 1) scanf("%d",&LTR[i]);
        FOR(i, 1, n - 1) scanf("%d",&RTL[i]);
        printf("Case %d: %d\n",t,solve());
    }
    return 0;
}
