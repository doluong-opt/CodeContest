/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11473 - Campus Roads
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
    double x, y;
    point(){}
    point(double xx, double yy){
        x = xx; y = yy;
    }
};
point p[M];
double dist(point a, point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
    
}
double cal(point p[], int n){
    double s = 0.0;
    for (int i=0;i<n;i++)
        s+=dist(p[i], p[(i + 1) % n]);
    return s;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, k;
    double perimeter, d;
    scanf("%d",&cases);
    while ( cases-- ) {
        scanf("%d %d",&n,&k);
        for (int i=0;i<n;i++) scanf("%lf %lf",&p[i].x,&p[i].y);
        perimeter = cal(p, n); d = -INF;
        for (int i=0;i<n;i++) {
            if (d < dist(p[i], p[(i + 1) % n])) d = dist(p[i], p[(i + 1) % n]);
        }
        cout<<perimeter<<" "<<d<<endl;
    }
}
