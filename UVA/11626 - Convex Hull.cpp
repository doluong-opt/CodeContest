/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11626 - Convex Hull ->AC
* Algorithm Adhoc
* Time Limit 0.248s
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
#define M 100010

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
    int64 x, y;
    Point(){}
    Point(int64 xx, int64 yy){
        x = xx; y = yy;
    }
};
vector <Point> P;
Point pivot;
int64 dist(Point A, Point B){
    int64 dx = A.x - B.x;
    int64 dy = A.y - B.y;
    return (dx * dx + dy * dy);
}
int64 cross(Point O, Point A, Point B){
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
bool angleCmp(Point A, Point B){
    if (!cross(pivot, A, B)) return dist(pivot, A) < dist(pivot, B);
    double dx1 = A.x - pivot.x; double dx2 = B.x - pivot.x;
    double dy1 = A.y - pivot.y; double dy2 = B.y - pivot.y;
    return atan2(dy1, dx1) < atan2(dy2, dx2);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int64 cases, n, x, y, P0, N, last;
    char ch;
    scanf("%lld",&cases);
    while (cases--) {
        scanf("%lld",&n); P.clear();
        for (int i=1;i<=n;i++) {
            scanf(" %lld %lld %c",&x,&y,&ch);
            if (ch == 'Y') P.pb(Point(x, y));
        }
        P0 = 0; N = P.size();
        for (int i=1;i<N;i++)
            if (P[i].x < P[P0].x || P[i].x == P[P0].x && P[i].y < P[P0].y) P0 = i;
        Point temp = P[0]; P[0] = P[P0]; P[P0] = temp;
        pivot = P[0];
        sort(++P.begin(), P.end(), angleCmp);
        last = N - 1;
        while (last > 0 && cross(P[0], P[last], P[N - 1]) == 0) last--;
        reverse(P.begin() + last + 1, P.end());
        printf("%lld\n",N);
        for (int i=0;i<N;i++) printf("%lld %lld\n",P[i].x,P[i].y);
    }
}
