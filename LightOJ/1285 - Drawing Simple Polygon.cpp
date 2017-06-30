/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1285 - Drawing Simple Polygon
* Algorithm convex
* Time Limit 0.074s
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
#define NM 100010

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
    int x, y, id;
    Point(){}
    Point(int xx, int yy, int idd){
        x = xx; y = yy; id = idd;
    }
};
vector <Point> P, ans;
Point pivot;
int id;
char s[NM];
int dist(Point A, Point B){
    int dx = A.x - B.x;
    int dy = A.y - B.y;
    return (dx * dx + dy * dy);
}
int cross(Point O, Point A, Point B){
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
bool angCmp(Point A, Point B){
    if (!cross(pivot, A, B)) return dist(pivot, A) < dist(pivot, B);
    double dx1 = A.x - pivot.x; double dx2 = B.x - pivot.x;
    double dy1 = A.y - pivot.y; double dy2 = B.y - pivot.y;
    return atan2(dy1, dx1) < atan2(dy2, dx2);
}
bool check() {
    int i = 2, n = P.size();
    while (i < n && !cross(P[0], P[1], P[i]) ) ++i;
    return (i < n);
}
int getInt(int n) {
    int v = 0, sign = 0;
    while (id < n && s[id]!=' ') {
        if (s[id] =='-') {
            sign = 1;
            ++id;
        }
        else v = v * 10 + s[id++] - '0';
    }
    if (sign) return v*-1;
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, x, y, P0, N, last, l;
    int caseno = 0;
    gets(s); id = 0; cases = getInt(strlen(s));
    while (cases--) {
        gets(s); id = 0; n = getInt(strlen(s)); P.clear();
        gets(s); id = 0; l = strlen(s);
        for (int i=1;i<=n;i++) {
            x = getInt(l); ++id;
            y = getInt(l); ++id;
            P.pb(Point(x, y, i - 1));
        }
        if ( !check() ) {
            printf("Case %d:\n",++caseno);
            puts("Impossible");
            continue;
        }
        P0 = 0; N = P.size();
        for (int i=1;i<N;i++)
            if (P[i].x < P[P0].x || P[i].x == P[P0].x && P[i].y < P[P0].y) P0 = i;
        Point temp = P[0]; P[0] = P[P0]; P[P0] = temp;
        pivot = P[0];
        sort(++P.begin(), P.end(), angCmp);
        last = N - 1;
        while (last > 0 && cross(P[0], P[last], P[N - 1]) == 0) last--;
        reverse(P.begin() + last + 1, P.end());
        printf("Case %d:\n",++caseno);
        printf("%d",P[0].id);
        for (int i=1;i<N;i++) printf(" %d",P[i].id);
        puts("");
    }
}
