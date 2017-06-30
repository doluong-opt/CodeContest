/***********************************************
* Author - LUONG VAN DO                        *
* 1123 - Trail Maintenance ->AC 
* Algorithm MST
* Time Limit 0.11s
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
#define maxN 10005
using namespace std;
   
const int MAXV = 205;   
   
int V, E, MST, edges;   
int u, v, w;   
int a, b, max_cost;   
int mark[MAXV];   
struct edge{ int u, w; };   
vector < edge > G[MAXV];   
   
bool find( int u, int v ) {   
    mark[u] = true;   
    if ( u == v ) return 1;   
    for ( int i = 0; i < G[u].size(); i++ )   
        if ( !mark[ G[u][i].u ] &&   
             find( G[u][i].u, v ) ) {   
            if ( G[u][i].w > max_cost ) {   
                max_cost = G[u][i].w;   
                a = u;
                b = G[u][i].u;   
            }   
            return 1;   
        }   
    return 0;   
}   
   
void delete_edge( int u, int v ) {   
    for ( int i = 0; i < G[u].size(); i++ )   
        if ( G[u][i].u == v ) {   
            swap( G[u][i], G[u].back() );   
            G[u].pop_back();   
            break;   
        }   
}   
   
int main() {   
   #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    scanf("%d",&test);
    for (int t = 1;t<=test;t++) {
        scanf("%d %d", &V, &E );
        for (int i=0;i<MAXV;i++) G[i].clear();
        printf("Case %d:\n",t);
        MST = edges = 0;
        while ( E-- )  {
            scanf( "%d %d %d", &u, &v, &w );
            u--; v--;
            max_cost = 0;
            memset(mark, false, sizeof(mark));
            if ( find( u, v ) ) {   
                if ( max_cost > w ) {   
                    MST -= max_cost - w;   
                    delete_edge( a, b );   
                    delete_edge( b, a );   
                    G[u].push_back( (edge){ v, w } );   
                    G[v].push_back( (edge){ u, w } );   
                }   
            } else {
                edges++;
                MST += w;   
                G[u].push_back( (edge){ v, w } );   
                G[v].push_back( (edge){ u, w } );   
            }
            printf("%d\n", edges == V - 1 ? MST : -1 );
        }
    }
    return 0;
}
