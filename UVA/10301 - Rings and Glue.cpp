/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10301 - Rings and Glue ->AC
* Algorithm Adhoc
* Time Limit 0.008s
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
#define M 100

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
struct Rings{
    double x, y, r;
    Rings(){}
    Rings(double xx, double yy, double rr){
        x = xx; y = yy; r = rr;
    }
}cricle[M + 1];
int color[M + 1], maxi;
vi adj[M + 1];
double dist(Rings A, Rings B){
    double dx = A.x - B.x;
    double dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}
bool inside(Rings A, Rings B, double d){
    double dx;
    dx = A.r - d;
    return (dx <= B.r);
}
bool intersection(Rings A, Rings B){
    double d = dist(A, B);
    if (d<= A.r || d<= B.r) {
        if (A.r > B.r) return inside(A, B, d);
        else return inside(B, A, d);
    }
    return d < A.r + B.r;
}
void dfs(int u){
    if (color[u]) return;
    color[u] = 1;
    maxi++;
    REP(i, adj[u].size())
        dfs( adj[u][i] );
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, Ans;
    while (scanf("%d",&n) ){
        if (n == -1) break;
        FOR(i, 1, n) {
            scanf("%lf %lf %lf",&cricle[i].x,&cricle[i].y,&cricle[i].r);
            color[i] = 0;
            adj[i].clear();
        }
        FOR(i, 1, n - 1)
            FOR(j, i + 1, n)
                if (intersection(cricle[i], cricle[j])) {
                    adj[i].pb(j);
                    adj[j].pb(i);
                }
        Ans = 0;
        FOR(i, 1, n) {
            maxi = 0;
            dfs( i );
            Ans = max(Ans, maxi);
        }
        if (Ans != 1) printf("The largest component contains %d rings.\n",Ans);
        else printf("The largest component contains %d ring.\n",Ans);
    }
}
