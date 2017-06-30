/***********************************************
* Author - LUONG VAN DO                        *
* 1174 - Commandos -> AC
* Algorithm Floyd
* Time Limit 0.011s
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
#define maxN 101

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int a[maxN][maxN];
int n;
void reset(){
    for (int i=0;i<n-1;i++) {
        a[i][i] = 0;
        for (int j=i+1;j<n;j++)
            a[i][j] = a[j][i] = INF;
    }
}
void Read() {
    int test,s,d,ans,r,u,v;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d %d",&n,&r);
        reset();
        for (int i=1;i<=r;i++) {
            scanf("%d %d",&u,&v);
            a[u][v] = 1;
            a[v][u] = 1;
        }
        scanf("%d %d",&s,&d);
        for (int k=0;k<n;k++)
            for (int i=0;i<n;i++)
                for (int j=0;j<n;j++)
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
        ans = a[s][0] + a[0][d];
        for (int i=1;i<n;i++)
            if ( ans < a[s][i] + a[i][d] ) ans = a[s][i] + a[i][d];
        printf("Case %d: %d\n",t,ans);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
