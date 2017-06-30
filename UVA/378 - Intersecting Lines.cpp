/***********************************************
* Author - LUONG VAN DO                        *
* Problem 378 - Intersecting Lines ->AC
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
struct Point{
    int x, y;
    Point(){}
    Point(int xx, int yy){
        x = xx; y = yy;
    }
};
Point A, B, C, D;
double x, y;
bool line(){
    int a1, b1, c1;
    int a2, b2, c2;
    int x1, y1, z1;
    int x2, y2, z2;
    int d, dx, dy;
    a1 = B.x - A.x;
    b1 = B.y - A.y;
    x1 = b1; y1 = -a1; z1 = -b1 * A.x + a1 * A.y;
    
    a2 = D.x - C.x;
    b2 = D.y - C.y;
    x2 = b2; y2 = -a2; z2 = -b2 * C.x + a2 * C.y;
    
    d = x1 * y2 - y1 * x2;
    dx = y1 * z2 - z1 * y2;
    dy = x2 * z1 - x1 * z2;
    return (d == 0 && dx == 0 && dy == 0);
}
bool none(){
    int a1, b1, c1;
    int a2, b2, c2;
    int x1, y1, z1;
    int x2, y2, z2;
    int d, dx, dy;
    a1 = B.x - A.x;
    b1 = B.y - A.y;
    x1 = b1; y1 = -a1; z1 = -b1 * A.x + a1 * A.y;
    
    a2 = D.x - C.x;
    b2 = D.y - C.y;
    x2 = b2; y2 = -a2; z2 = -b2 * C.x + a2 * C.y;
    
    d = x1 * y2 - y1 * x2;
    dx = y1 * z2 - z1 * y2;
    dy = x2 * z1 - x1 * z2;
    if (d == 0) return true;
    x = (double)dx / (double)d;
    y = (double)dy / (double)d;
    return false;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n;
    puts("INTERSECTING LINES OUTPUT");
    scanf("%d",&n);
    REP(i, n) {
        scanf("%d %d %d %d %d %d %d %d",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y,&D.x,&D.y);
        if (line()) puts("LINE");
        else
        if (none()) puts("NONE");
        else printf("POINT %.2lf %.2lf\n",x, y);
    }
    puts("END OF OUTPUT");
}
