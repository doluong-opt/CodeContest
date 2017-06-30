/***********************************************
* Author - LUONG VAN DO                        *
* 11160 - Going Together ->AC
* Algorithm bfs
* Time Limit 0.055s
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
#define maxN 1000001

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char s[11][11];
int d[maxN], poss[4], pose[4];
int S, E1, E2, E3, E4, E5, E6, n;
int inSide(int u, int v){
    return (u>=0 && u < n && v>=0 && v < n);
}
int move(int p, int k) {
    int u, v;
    u = p / n; v = p % n;
    u +=dx[k];
    v +=dy[k];
    if ( inSide(u, v) && s[u][v]!='#' ) p = u * n + v;
    return p;
}
int bfs() {
    int p[4], tp[4], u, tmp;
    queue <int> Q;
    REP(i, maxN)
        d[i] = INF;
        
    d[S] = 0;
    Q.push( S );
    while ( !Q.empty() ) {
        u = Q.front(); Q.pop();
        p[0] = u / 10000; p[1] = (u % 10000) / 100; p[2] = u % 100;
        REP(k, 4) {
            
            tp[0] = move(p[0], k);
            tp[1] = move(p[1], k);
            tp[2] = move(p[2], k);
            
            if (tp[0] == tp[1]) {
                tp[0] = p[0];
                tp[1] = p[1];
            } 
            if (tp[0] == tp[2]) {
                tp[0] = p[0];
                tp[2] = p[2];
            }
            if (tp[1] == tp[2]) {
                tp[1] = p[1];
                tp[2] = p[2];
            }
            
            tmp = tp[0] * 10000 + tp[1] * 100 + tp[2];
            if ( d[tmp]!=INF ) continue;
            d[tmp] = d[u] + 1;
            Q.push( tmp );
        }
        if ( d[E1]!=INF ) return d[E1];
        if ( d[E2]!=INF ) return d[E2];
        if ( d[E3]!=INF ) return d[E3];
        if ( d[E4]!=INF ) return d[E4];
        if ( d[E5]!=INF ) return d[E5];
        if ( d[E6]!=INF ) return d[E6];
    }
    return INF;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, k, h, ans;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d ",&n);
        REP(i, n) gets(s[i]);
        k = h = 0;
        REP(i, n)
            REP(j, n)
                if (s[i][j] == 'A' || s[i][j] == 'B' || s[i][j] == 'C')
                    poss[k++] = i * n + j;
                else
                if (s[i][j] == 'X')
                    pose[h++] = i * n + j;
                    
        S = poss[0] * 10000 + poss[1] * 100 + poss[2];
        E1 = pose[0] * 10000 + pose[1] * 100 + pose[2];
        E2 = pose[0] * 10000 + pose[2] * 100 + pose[1];
        E3 = pose[1] * 10000 + pose[2] * 100 + pose[0];
        E4 = pose[1] * 10000 + pose[0] * 100 + pose[2];
        E5 = pose[2] * 10000 + pose[1] * 100 + pose[0];
        E6 = pose[2] * 10000 + pose[0] * 100 + pose[1];
        ans = bfs();
        if (ans != INF) printf("Case %d: %d\n",t,ans);
        else printf("Case %d: trapped\n",t);
    }
    return 0;
}
