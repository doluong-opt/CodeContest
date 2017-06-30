/***********************************************
* Author - LUONG VAN DO                        *
* Problem 634 - Polygon ->AC
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
#define M 1010

#define eps 1e-9
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
int n;
vector <Point> P;
Point pivot;
double angle(Point A, Point B, Point C){
    double a1 = B.x - A.x; double a2 = C.x - A.x;
    double b1 = B.y - A.y; double b2 = C.y - A.y;
    return acos((a1 * a2 + b1 * b2) / sqrt((a1 * a1 + b1 * b1) * (a2 * a2 + b2 * b2)));
}
int cross(Point O, Point A, Point B){
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
bool isInsidePolygon(Point A, vector <Point> P){
    int N = (int)P.size();
    if (N == 0) return false;
    double sum = 0.0;
    for (int i=0;i<N;i++) {
        if ( cross(A, P[i], P[(i + 1) % N]) < 0 )
            sum-=angle(A, P[i], P[(i + 1) % N]);
        else
            sum+=angle(A, P[i], P[(i + 1) % N]);
    }
    return (fabs(sum - 2.0 * PI) <= eps || fabs(sum + 2.0 * PI) <= eps);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Point A;
    int x, y, P0;
    while ( scanf("%d",&n) &&  n){
        P.clear();
        for (int i=0;i<n;i++) {
            scanf("%d %d",&x, &y);
            P.pb(Point(x, y));
        }
        scanf("%d %d",&A.x,&A.y);
        if ( isInsidePolygon(A, P) ) puts("T");
        else puts("F");
    }
}
