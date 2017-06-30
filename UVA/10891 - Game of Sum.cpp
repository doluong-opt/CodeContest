/***********************************************
* Author - LUONG VAN DO                        *
* 10891 - Game of Sum ->AC
* Algorithm dp
* Time Limit 0.092s
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
#define For(i, a, b) for (int i=a; i<=b; i++)
#define Ford(i,a,b) for (int i=a;i>=b;i--)
#define Rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 101
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n;
int a[maxN];
int dp[maxN][maxN];
int f(int u, int v){
    if (u==v) return a[u];
    if (dp[u][v]!=-1) return dp[u][v];
    int best, res = -INF;
    best = 0;
    for (int i=u;i<=v;i++) {
        best+=a[i];
        if (i==v) res = max(res, best);
        else res = max(res, best - f(i+1,v) );
    }
    best = 0;
    for (int i=v;i>=u;i--) {
        best+=a[i];
        if (i==u) res = max(res, best);
        else res = max(res, best - f(u,i-1) );
    }
    return dp[u][v] = res;
}
void Read_Input(){
    while ( scanf("%d",&n) && n){
        for (int i=1;i<=n;scanf("%d",&a[i++]));
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++) dp[i][j] = -1;
        printf("%d\n",f(1,n));
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}
