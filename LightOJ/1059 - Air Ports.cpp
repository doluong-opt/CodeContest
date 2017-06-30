/***********************************************
* Author - LUONG VAN DO                        *
* 1059 - Air Ports ->AC
* Algorithm kruskal
* Time Limit 0.149s
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
#define maxN 10001

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node{
    int x,y,w;
    node(){}
    node(int xx, int yy, int ww){
        x = xx; y = yy; w = ww;
    }
};
int Lab[maxN];
node road[maxN*11];
int n,m,c;
int64 ans,air;
int Get(int v){
    if ( Lab[v] < 0) return v;
    else return Lab[v] = Get( Lab[v] );
}
void Union(int r1, int r2){
    int x = Lab[r1] + Lab[r2];
    if ( Lab[r1] > Lab[r2] ){
        Lab[r1] = r2;
        Lab[r2] = x;
    }
    else {
        Lab[r1] = x;
        Lab[r2] = r1;
    }
}
bool cmp(node x, node y){
    if (x.w!=y.w) return x.w < y.w;
    return true;
}
void Read_Input() {
    int test,cnt,u,v,w;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d %d %d",&n,&m,&c);
        for (int i=1;i<=n;i++) Lab[i] = -1;
        for (int i=1;i<=m;i++) {
            scanf("%d %d %d",&u,&v,&w);
            road[i] = node(u,v,w);
        }
        sort(road+1,road+1+m,cmp);
        ans = air = cnt = 0;
        for (int i=1;i<=m;i++) {
            u = Get( road[i].x ); v = Get( road[i].y );
            if (u!=v && road[i].w < c) {
                ans+=road[i].w;
                Union(u,v);
                if (++cnt == n - 1) break;
            }
        }
        for (int i=1;i<=n;i++)
            if ( Lab[i] < 0 ) {
                air++;
                ans+=c;
            }
        printf("Case %d: ",t);
        cout << ans <<" "<< air <<endl;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}
