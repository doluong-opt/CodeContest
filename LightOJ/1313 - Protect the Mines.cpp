/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1313 - Protect the Mines 
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
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1000

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
struct point{
    int x, y;
    point(){}
    point(int xx, int yy){
        x = xx; y = yy;
    }
};
int n, m, P, G, mine_in, nn, temp;
vector <point> p, ppp, mx, a, pp, mine;
point pivot;
int dist(point a, point b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return (dx * dx + dy * dy);
}
int cross(point o, point a, point b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
bool angCmp(point a, point b) {
    if (!cross(pivot, a, b)) return dist(pivot, a) < dist(pivot, b);
    double dx1 = a.x - pivot.x, dx2 = b.x - pivot.x;
    double dy1 = a.y - pivot.y, dy2 = b.y - pivot.y;
    return atan2(dy1, dx1) < atan2(dy2, dx2);
}
double angle(point a, point b, point c) {
    double ux = b.x - a.x, uy = b.y - a.y;
    double vx = c.x - a.x, vy = c.y - a.y;
    return acos((ux * vx + uy * vy) / sqrt((ux * ux + uy * uy) * (vx * vx + vy * vy)));
}
bool inside(point a, vector <point> p) {
    double sum = 0.0;
    int n = p.size();
    for (int i=0;i<n;i++) {
        if ( cross(a, p[i], p[(i + 1) % n]) < 0)
            sum-=angle(a, p[i], p[(i + 1) % n]);
        else
            sum+=angle(a, p[i], p[(i + 1) % n]);
    }
    return ( fabs(sum - 2 * PI) <=eps || fabs(sum + 2 * PI) <=eps );
}
vector <point> convex_hull(vector <point> p) {
    int n = p.size(), p0 = 0;
    pivot = point(0, 0);
    for (int i=1;i<n;i++)
        if (p[i].y < p[p0].y || p[i].y == p[p0].y && p[i].x > p[p0].x) p0 = i;
    point temp = p[0]; p[0] = p[p0]; p[p0] = temp;
    pivot = p[0];
    sort(++p.begin(), p.end(), angCmp);
    stack <point> S;
    S.push(p[n-1]); S.push(p[0]);
    point now(0,0), pre(0, 0);
    int i = 1;
    while (i < n) {
        now = S.top(); S.pop();
        pre = S.top(); S.push(now);
        if (cross(pre, now, p[i]) > 0) S.push(p[i++]);
        else S.pop();
    }
    vector <point> ans;
    while (!S.empty()) {
        ans.pb(S.top()); 
        S.pop();
    }
    return ans;
}
bool cal1(int k, vector <point> mine, int add) {
    a.clear();
    for (int i=0;i<n;i++) {
        if ( i == k ) continue;
        a.pb(p[i]);
    }
    int cnt = 0;
    for (int i=0;i<add;i++)
        if (inside(mine[i], a)) cnt++;
    return (cnt == add);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    int x, y, d, ans, pos;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d %d %d",&n,&m,&G,&P);
        p.clear(); mx.clear(); mine.clear();
        for (int i=0;i<n;i++) {
            scanf("%d %d",&x,&y);
            p.pb(point(x, y));
        }
        p = convex_hull( p );
        if (p[0].x == p[p.size()-1].x && p[0].y == p[p.size()-1].y) n = p.size() - 1;
        for (int i=0;i<m;i++) {
            scanf("%d %d",&x,&y);
            mx.pb(point(x, y));
        }
        ans = m * G; mine_in = 0;
        for (int i=0;i<m;i++)
            if (inside(mx[i], p)) {
                mine_in++;
                mine.pb(mx[i]);
            }
        int i = 0;
        while (i < n) {
            if (cal1(i, mine, mine_in)) {
                i = 0;
                p = a;
                n--;
            }
            else i++;
        }
        ans = min(ans, (m - mine_in) * G + n * P);
        printf("Case %d: %d\n",++caseno, ans);
    }
}
