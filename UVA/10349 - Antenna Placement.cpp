/***********************************************
* Author - LUONG VAN DO                        *
* 10349 - Antenna Placement ->AC
* Algorithm Bipartite graph
* Time Limit 0.008s
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
#define maxN 5000
using namespace std;
char s[maxN][maxN];
int w,h,rs,cnt;
int MatchX[maxN], MatchY[maxN];
int DistX[maxN], DistY[maxN];
vector <int> adj[maxN];
bool bfs(){
    int u,v,found;
    queue <int> Q;
    For(i,1,500) {
        DistX[i] = 0;
        if (!MatchX[i]) Q.push( i );
    }
    For(i,1,500) DistY[i] = 0;
    found = 0;
    while ( !Q.empty() ){
        u = Q.front(); Q.pop();
        Rep(i,adj[u].size()) {
            v = adj[u][i];
            if (!DistY[v]) {
                DistY[v] = DistX[u] + 1;
                if (!MatchY[v]) found = 1;
                else {
                    DistX[ MatchY[v] ] = DistY[v] + 1;
                    Q.push( MatchY[v] );
                }
            }
        }
    }
    return found;
}
bool dfs(int u){
    int v;
    Rep(i,adj[u].size()){
        v = adj[u][i];
        if (DistY[v] == DistX[u] + 1) {
            DistY[v] = 0;
            if ( !MatchY[v] || dfs( MatchY[v] ) ){
                MatchX[u] = v;
                MatchY[v] = u;
                return true;
            }
        }
    }
    return false;
}
void Solve(){
    cnt = 0;
    Rep(i,h)
        Rep(j,w)
            if (s[i][j]=='*') cnt++;
    Rep(i,h)
        Rep(j,w) {
            if (i-1>=0 && s[i][j]=='*' && s[i-1][j]=='*') adj[(i+1)*10 + j+1].pb(i*10 + j + 1);
            if (j-1>=0 && s[i][j]=='*' && s[i][j-1]=='*') adj[(i+1)*10 + j+1].pb((i+1)*10 + j);
            if (i+1<h && s[i][j]=='*' && s[i+1][j]=='*') adj[(i+1)*10 + j+1].pb((i+2)*10 + j + 1);
            if (j+1<w && s[i][j]=='*' && s[i][j+1]=='*') adj[(i+1)*10 + j+1].pb((i+1)*10 + j + 2);
        }
    For(i,1,500) MatchX[i] = 0;
    For(j,1,500) MatchY[j] = 0;
    rs = 0;
    while ( bfs() ){
        For(i,1,500)
            if (!MatchX[i] && dfs( i )) rs++;
    }
    //For(i,1,500)
        //if( MatchX[i] ) printf("%d %d\n",i,MatchX[i]);
}
void Write_Output(){
    printf("%d\n",rs/2 + cnt-rs);
}
void Read_Input(){
    int t;
    scanf("%d",&t);
    while (t--){
        For(i,1,500) adj[i].clear();
        scanf("%d %d ",&h,&w);
        Rep(i,h) gets(s[i]);
        Solve();
        Write_Output();
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
}
