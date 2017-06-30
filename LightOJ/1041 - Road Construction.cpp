/***********************************************
* Author - LUONG VAN DO                        *
* 1041 - Road Construction ->AC
* Algorithm kruskal
* Time Limit 0.013s
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
#define maxN 201

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
map <string, int> Name;
int a[maxN][maxN];
int Lab[maxN];
node e[maxN];
int nm,m;
int Get(int v){
    if ( Lab[v] < 0 ) return v;
    else return Lab[v] = Get( Lab[v] );
}
void Union(int r1, int r2){
    int x = Lab[r1] + Lab[r2];
    if ( Lab[r1] > Lab[r2] ) {
        Lab[r2] = x;
        Lab[r1] = r2;
    }
    else {
        Lab[r1] = x;
        Lab[r2] = r1;
    }
}
bool cmp(node a, node b){
    if ( a.w != b.w ) return a.w < b.w;
    return true;
}
int kruskal(){
    int u,v, ans, cnt;
    ans = cnt = 0;
    for (int i=1;i<=nm;i++) {
        u = Get( e[i].x ); v = Get( e[i].y );
        if ( u!=v ) {
            ans+=e[i].w;
            Union(u, v);
            if (++cnt == m - 1) break;
        }
    }
    if ( cnt == m - 1) return ans;
    else return -1;
}
void Read() {
    int test,n,cost;
    string x,y;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d ",&n); Name.clear();
        for (int i=0;i<maxN;i++)
            for (int j=0;j<maxN;j++) a[i][j] = INF;
        m = nm = 0;
        for (int i=0;i<n;i++) {
            cin >> x >> y >> cost;
            if (!Name[x]) Name[x] = ++m;
            if (!Name[y]) Name[y] = ++m;
            a[Name[x]][Name[y]] = min(a[Name[x]][Name[y]], cost);
        }
        for (int i=1;i<=m;i++)
            for (int j=1;j<=m;j++)
                if (a[i][j]!=INF) e[++nm] = node(i,j,a[i][j]);
        for (int i=1;i<=m;i++) Lab[i] = -1;
        sort(e+1,e+nm+1,cmp);
        int ans = kruskal();
        if ( ans == -1 ) printf("Case %d: Impossible\n",t);
        else printf("Case %d: %d\n",t,ans);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
