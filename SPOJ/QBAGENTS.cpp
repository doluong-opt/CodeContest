/***********************************************
* Author - LUONG VAN DO                        *
* QBAGENTS ->AC
* Algorithm dp queue
* Time Limit 1.02s
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
#define maxN 251
using namespace std;
typedef struct node{
    int x,y,z;
    node(){}
    node(int xx, int yy, int zz){
        x = xx; y = yy; z = zz;
    }    
};
vector <int> adj[maxN];
vector <int> :: iterator it;
int d[maxN][maxN][3];
int check[maxN][maxN][3];
int n,m,s,t,rs;
void Read_Input(){
    scanf("%d %d",&n,&m);
    scanf("%d %d",&s,&t);
    Rep(i,m) {
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].pb( v );
    }
}
void Solve(){
    int v,found;
    node root, tmp;
    root.x = s; root.y = t; root.z = 0;
    check[s][t][0] = 1;
    d[s][t][0] = 0;
    queue <node> Q;
    Q.push( root );
    rs = -1; found = 0;
    while ( !Q.empty() && !found){
        tmp = Q.front(); Q.pop();
        if (tmp.z==0) {
            for (int i=0;i<adj[tmp.x].size();i++) {
                v = adj[tmp.x][i];
                if (check[v][tmp.y][1]) continue;
                check[v][tmp.y][1] = 1;
                d[v][tmp.y][1] = d[tmp.x][tmp.y][0] + 1;
                root = node(v,tmp.y,1);
                Q.push( root );
            }
        }
        else {
            for (int i=0;i<adj[tmp.y].size();i++) {
                v = adj[tmp.y][i];
                if (check[tmp.x][v][0]) continue;
                check[tmp.x][v][0] = 1;
                d[tmp.x][v][0] = d[tmp.x][tmp.y][1];
                root = node(tmp.x,v,0);
                Q.push( root );
                if (tmp.x == v){
                    rs = d[tmp.x][v][0];
                    found = 1;
                    break;
                }
            }
        }
    }
}
void Write_Output(){
    printf("%d\n",rs);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}
