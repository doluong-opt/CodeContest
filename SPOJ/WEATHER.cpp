/***********************************************
* Author - LUONG VAN DO                        *
* WEATHER ->AC
* Algorithm Cau
* Time Limit 0.06s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <map>
#include <set>
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
#define maxN 105
using namespace std;
int Low[maxN], Num[maxN];
int Parent[maxN], IsCut[maxN], Child[maxN];
vector <int> adj[maxN];
int n,m,cnt;
int64 rs;
void Read_Input(){
    scanf("%d",&n);
    scanf("%d",&m);
    int u,v;
    For(i,1,m){
        scanf("%d %d",&u,&v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
}
void Visit(int u){
    Num[u] = ++cnt;
    Low[u] = Num[u];
    Rep(i,adj[u].size()) {
        int v = adj[u][i];
        if (!Parent[v]) {
            Parent[v] = u;
            Child[u]++;
            Visit( v );
            Child[u]+=Child[v];
            Low[u] = min(Low[u],Low[v]);
            if (Parent[u]==-1)
                IsCut[u] = IsCut[u] || ( Low[v]>=Num[u] && Child[u] > 1);
            else
                IsCut[u] = IsCut[u] || (Low[v]>=Num[u]);
        }
        else
            if ( Parent[u]!=v ) Low[u] = min(Low[u], Num[v]);
    }
}
void Solve(){
    cnt = 0;
    rs = 0;
    For(i,1,n)
        if (!Parent[i]) {
            Parent[i] = -1;
            Visit( i );
        }
    For(i,1,n) {
        int u = Parent[i];
        if (u!=-1 && Low[i]>=Num[i] )
            rs+=(n-Child[i]-1)*(Child[i]+1);
    }
}
void Write_Output(){
    printf("%lld\n",rs);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}
