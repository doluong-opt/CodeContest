/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10310 - Dog and Gopher ->AC
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

#define eps 1e-6
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
}p[M];
double dist(Point A, Point B){
    double dx = A.x - B.x;
    double dy = A.y - B.y;
    return (dx * dx + dy * dy);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Point A, B;
    int found, n;
    while ( scanf("%d",&n) != EOF){
        scanf("%lf %lf %lf %lf",&A.x,&A.y,&B.x,&B.y);
        for (int i=0;i<n;i++) scanf("%lf %lf",&p[i].x,&p[i].y);
        found = 0;
        for (int i=0;i<n;i++) {
            if ( dist(A, p[i]) * 4.0 <= dist(B, p[i]) ) {
                found = 1;
                printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",p[i].x,p[i].y);
                break;
            }
        }
        if (!found) printf("The gopher cannot escape.\n");
        
    }
}
