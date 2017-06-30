/***********************************************
* Author - LUONG VAN DO                        *
* Problem 152 - Tree's a Crowd ->AC
* Algorithm Adhoc
* Time Limit 0.284s
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
#define M 100000

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
    int x, y, z;
    point(){}
    point(int xx, int yy, int zz){
        x = xx; y = yy; z = zz;
    }
};
point p[5001];
int dist(point a, point b){
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    int dz = a.z - b.z;
    return (int)sqrt(dx * dx + dy * dy + dz * dz);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n = 0, x, y, z, d, s;
    int Ans[11];
    while ( scanf("%d %d %d",&x,&y,&z) && (x + y + z))
        p[n++] = point(x, y, z);
    for (int i=0;i<10;i++) Ans[i] = 0;
    for (int i=0;i<n;i++) {
        d = INF;
        for (int j=0;j<n;j++)
            if (i!=j) {
                s = dist(p[i], p[j]);
                if (d > s) d = s;
            }
        if (d >= 10) continue;
        Ans[d]++;
    }
    for (int i=0;i<10;i++)
        printf("%4d",Ans[i]);
    printf("\n");
}
