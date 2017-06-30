/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11515 - Cranes ->AC
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
#define M 16

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
struct circle{
    int x, y, r;
    circle(){}
    circle(int xx, int yy, int rr){
        x = xx; y = yy; r = rr;
    }
};
circle c[M];
int n;
int sqr(int x){
    return x * x;
}
bool is_common(int s){
    for (int i=0;i<n;i++) {
        if (And(s, i))
            for (int j=i+1;j<n;j++)
                if (And(s, j)) {
                    int d = sqr(c[i].x - c[j].x) + sqr(c[i].y - c[j].y);
                    if (d <= sqr(c[i].r + c[j].r)) return true;
                }
    }
    return false;
}
int calcArea(int s) {
    int res = 0;
    for (int i=0;i<n;i++)
        if (And(s, i)) res+=sqr(c[i].r);
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, lim, Ans;
    scanf("%d",&cases);
    while ( cases-- ) {
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d %d %d",&c[i].x,&c[i].y,&c[i].r);
        lim = (1 << n); Ans = -1;
        for (int i=1;i<lim;i++)
            if ( !is_common(i) )
                Ans = max(Ans, calcArea(i));
        printf("%d\n",Ans);
    }
}

