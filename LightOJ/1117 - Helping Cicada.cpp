/***********************************************
* Author - LUONG VAN DO                        *
* 1117 - Helping Cicada ->AC
* Algorithm Count
* Time Limit 0.74s
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
#define maxN 17

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, m;
int c[maxN], a[maxN];
int64 ans;
int64 GCD(int64 u, int64 v){
    if (u % v) return GCD(v, u % v);
    else return v;
}
int64 Count(int limit) {
    int64 gd, lcm, ss;
    lcm = a[1];
    FOR(i, 2, limit) {
        gd = GCD(lcm, a[i]);
        ss = lcm * a[i];
        lcm = ss / gd;
    }
    return (n / lcm);
}
void Call(int64 n, int64 level, int64 limit) {
    if (level >=1)
        a[level] = c[n];
    if (level == limit) {
        if (limit % 2 == 0) ans-=Count(limit);
        else ans+=Count(limit);
        return;
    }
    for (int i=n+1;i<=m;i++)
        Call(i, level + 1, limit);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&n,&m);
        ans = 0;
        FOR(i, 1, m) {
            scanf("%d",&c[i]);
            ans+=(n / c[i]);
        }
        FOR(i, 2, m)
            Call(0, 0, i);
        printf("Case %d: %lld\n",t,n - ans);
    }
    return 0;
}
