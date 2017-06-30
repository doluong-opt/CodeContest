/***********************************************
* Author - LUONG VAN DO                        *
* NKLEAGUE ->AC
* Algorithm Topo
* Time Limit 0.59s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <map>
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
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 1001
using namespace std;
int n,found;
char s[maxN][maxN];
int a[maxN][maxN], num[maxN], q[maxN];
int color[maxN], id;
void Read_Input(){
    scanf("%d ",&n);
    Rep(i,n) gets(s[i]);
    Rep(i,n)
        Rep(j,n) a[i+1][j+1] = s[i][j] - '0';    
}
void dfs(int u){
    color[u] = 1;
    for (int i=1;i<=n;i++)
        if (!color[i] && a[u][i]) dfs( i );
    num[u] = id;
    q[id] = u;
    id--;
}
void Solve(){
    id = n;
    For(i,1,n)
        if (!color[i]) dfs( i );
    found = 1;
    for (int i=1;i<n && found;i++)
        if (!a[q[i]][q[i+1]]) found = 0;
}
void Write_Output(){
    if (!found) puts("-1");
    else
    {
        For(i,1,n){
            if (i > 1) printf(" ");
            printf("%d",q[i]);            
        }
        puts("");
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}
