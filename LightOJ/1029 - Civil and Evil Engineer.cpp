/***********************************************
* Author - LUONG VAN DO                        *
* 1029 - Civil and Evil Engineer ->AC
* Algorithm Minimin Spaning tree
* Time Limit 0.107s
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
#define maxN 12005

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct state{
    int x, y, w;
    state(){}
    state(int xx, int yy, int ww){
        x = xx; y = yy; w = ww;
    }
};
int m, n;
state edge[maxN];
int Lab[100 + 5];
int Get(int v) {
    if ( Lab[v] < 0) return v;
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
bool cmp1(state a, state b){
    if ( a.w != b.w ) return a.w < b.w;
    return true;
}
bool cmp2(state a, state b){
    if ( a.w != b.w ) return a.w > b.w;
    return true;
}
int kruskal(){
    int res, cnt;
    res = cnt = 0;
    FOR(i, 0, n) Lab[i] = -1;
    FOR(i, 1, m) {
        int nx = Get( edge[i].x );
        int ny = Get( edge[i].y );
        if ( nx != ny) {
            Union(nx, ny);
            res+=edge[i].w;
            if ( ++cnt == n ) break;
        }
    }
    return res;
}
void Read() {
    int test, u, v, c, p, q;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        m = 0;
        while ( scanf("%d %d %d",&u,&v,&c) && (u + v + c ))
            edge[++m] = state(u,v,c);
        sort(edge+1,edge+m+1,cmp1);
        p = kruskal();
        sort(edge+1,edge+m+1,cmp2);
        q = kruskal();
        if ( (p + q) % 2 == 0 ) printf("Case %d: %d\n",t,(p + q) / 2);
        else printf("Case %d: %d/2\n",t,(p + q));
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
