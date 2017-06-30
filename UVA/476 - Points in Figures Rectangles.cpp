/***********************************************
* Author - LUONG VAN DO                        *
* Problem 476 - Points in Figures: Rectangles ->AC
* Algorithm Adhoc
* Time Limit 0.016s
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
    double x, y;
    Point(){}
    Point(double xx, double yy){
        x = xx; y = yy;
    }
};
Point A[M + 1], B[M + 1];
bool inside(Point a, Point b, Point p){
    return (p.x > a.x && p.x < b.x && p.y > b.y && p.y < a.y);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    char s[M + 1];
    int n, m;
    m = 0;
    while ( gets(s) && strcmp(s,"*")){
        sscanf(s + 2,"%lf %lf %lf %lf",&A[m].x,&A[m].y,&B[m].x,&B[m].y);
        ++m;
    }
    int cases = 0, ok;
    while ( gets(s) && strcmp(s,"9999.9 9999.9")){
        Point p;
        sscanf(s,"%lf %lf",&p.x,&p.y);
        ++cases; ok = 0;
        REP(i, m)
            if (inside(A[i], B[i], p)) {
                printf("Point %d is contained in figure %d\n",cases, i + 1);
                ok = 1;
            }
        if (!ok) printf("Point %d is not contained in any figure\n",cases);
    }
}
