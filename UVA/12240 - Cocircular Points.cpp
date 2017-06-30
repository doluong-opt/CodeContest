/***********************************************
* Author - LUONG VAN DO                        *
* Problem 12240 - Cocircular Points
* Algorithm
* Time Limit
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
#define M 110

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
struct point{
    int x, y;
    point(){}
    point(int xx, int yy){
        x = xx; y = yy;
    }
};
point p[M];
bool get_center(point p1, point p2, point *c) {
    int d = (p1.x - p2.x) * (p1.x - p2.x);
            (p1.y - p2.y) * (p1.y - p2.y);
    int det = d * d / r
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int Ans = 0, r;
    point c;
    while ( scanf("%d",&n) && n){
        for (int i=0;i<n;i++) scanf("%d %d",&p[i].x,&p[i].y);
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++) {
                if ( get_center(p[i], p[j], &c) )
                    Ans = 2; r = (c.x - p[i].x) * (c.x - p[i].x) + (c.y - p[i].y) * (c.y - p[i].y);
                    for (int k=0;k<n;k++)
                        if (k!=i && k!=j && lie_on_cir(p[k], c, r)) Ans++;
            }
        printf("%d\n",Ans);
    }
}
