// =============================================================================
// Author LUONG VAN DO
// Problem
// Algorithm
// Time Limit
// =============================================================================
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

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint unsigned int

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline double min(double a, double b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 111222333
#define N 111
struct point{
    int x, y;
    point(){};
    point(int _x, int _y){
        x = _x; y = _y;
    }
};
point p1[N], p2[N];
int n, m;
double res;
double dist(point a, point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
double solve(point x1, point y1, point x2, point y2) {
    double a, b, c, p, S, r1, r2, r3, r4;
    a = dist(x1, y1); b = dist(x1, x2); c = dist(y1, x2);
    p = (a + b + c) * 0.5;
    S = sqrt(p * (p - a) * (p - b) * (p - c));
    r1 = (a * b * c) / (4 * S);
    
    a = dist(x1, y1); b = dist(x1, y2); c = dist(y1, y2);
    p = (a + b + c) * 0.5;
    S = sqrt(p * (p - a) * (p - b) * (p - c));
    r2 = (a * b * c) / (4 * S);
    
    a = dist(x2, y2); b = dist(x2, x1); c = dist(y2, x1);
    p = (a + b + c) * 0.5;
    S = sqrt(p * (p - a) * (p - b) * (p - c));
    r3 = (a * b * c) / (4 * S);
    
    a = dist(x2, y2); b = dist(x2, y1); c = dist(y2, y1);
    p = (a + b + c) * 0.5;
    S = sqrt(p * (p - a) * (p - b) * (p - c));
    r4 = (a * b * c) / (4 * S);
    return min(min(r1, r2), min(r3, r4));
}
int main(){
	freopen("exam.inp","r",stdin);
	freopen("exam.out","w",stdout);
	int cases, caseno = 0;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &m);
        rep(i, m) scanf("%d %d", &p1[i].x, &p1[i].y);
        scanf("%d", &n);
        rep(i, n) scanf("%d %d", &p2[i].x, &p2[i].y);
        res = INF;
        rep(i, m)
            rep(j, n) res = min(res, solve(p1[i], p1[(i + 1) % m], p2[j], p2[(j + 1) % n]));
        printf("%.10lf\n", res);
    }
}
