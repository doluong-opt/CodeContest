/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11492 - Babel ->AC
* Algorithm dijk
* Time Limit 1.160s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
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
#define M 4010

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct Node{
    int x, y;
    string word;
    Node(){}
    Node(int xx, int yy, string wo){
        x = xx; y = yy; word = wo;
    }
};
map <int, list <int> > adj, adjj;
set <int> ad[M];
map <string, int> Name;
char wc[M];
int n, nheap, nm;
int pos[M], heap[M];
int d[M], color[M], cost[M];
void update(int v){
    int child, parent;
    child = pos[v];
    if (!child) child = ++nheap;
    parent = child >> 1;
    while ( parent > 0 && d[heap[parent]] > d[v]) {
        heap[child] = heap[parent];
        pos[heap[child]] = child;
        child = parent;
        parent = child >> 1;
    }
    heap[child] = v;
    pos[v] = child;
}
int pop(){
    int u = heap[1];
    int r, v = heap[nheap--];
    r = 1;
    while (2 * r<= nheap) {
        int c = 2 * r;
        if (c < nheap && d[heap[c+1]] < d[heap[c]]) ++c;
        if (d[v]<=d[heap[c]]) break;
        heap[r] = heap[c];
        pos[heap[r]] = r;
        r = c;
    }
    heap[r] = v;
    pos[v] = r;
    return u;
}
void dijkstra(int s){
    nheap = 0;
    for (int i=1;i<=n;i++) {
        d[i] = INF;
        pos[i] = heap[i] = 0;
        color[i] = 0;
    }
    d[s] = cost[s]; update(s);
    while ( nheap ) {
        int u = pop();
        color[u] = 1;
        for (set <int> :: iterator it=ad[u].begin(); it!= ad[u].end(); it++) {
            int v = (*it);
            if (color[v]) continue;
            if (d[v] > d[u] + cost[v]) {
                d[v] = d[u] + cost[v];
                update( v );
            }
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    string x, y, w;
    int u, v, c, Ans;
    while ( scanf("%d",&n) && n) {
        Name.clear(); nm = 0;
        adj.clear(); adjj.clear();
        cin >> x >> y;
        if (!Name[x]) Name[x] = ++nm;
        if (!Name[y]) Name[y] = ++nm;
        for (int i=1;i<=n;i++) {
            cin >> x >> y >> w;
            if (!Name[x]) Name[x] = ++nm;
            if (!Name[y]) Name[y] = ++nm;
            u = Name[x]; v = Name[y]; c = w.size();
            adj[u].pb( i );
            adj[v].pb( i );
            adjj[i].pb( u );
            adjj[i].pb( v );
            wc[i] = w[0];
            cost[i] = c;
        }
        for (int i=1;i<=n;i++) ad[i].clear();
        
        for (int i=1;i<=n;i++) {
            for (list <int> :: iterator it1=adjj[i].begin(); it1!=adjj[i].end(); it1++) {
                for (list <int> :: iterator it2=adj[(*it1)].begin(); it2!=adj[(*it1)].end(); it2++) {
                    if ( wc[i] != wc[(*it2)] ) ad[i].insert(*it2);
                }
            }
        }
        Ans = INF;
        for (list <int> :: iterator it1 = adj[1].begin(); it1!=adj[1].end(); it1++) {
            dijkstra(*it1);
            for (list <int> :: iterator it2 = adj[2].begin(); it2!=adj[2].end(); it2++)
                Ans = min(Ans, d[*(it2)]);
        }
        if (Ans != INF) printf("%d\n",Ans);
        else printf("impossivel\n");
    }
}
