/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1239 - Convex Fence ->AC
* Algorithm convex_hull
* Time Limit 1.187s
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
#define N 100000

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
    int64 x, y;
    point(){}
    point(int64 xx, int64 yy) {
        x = xx; y = yy;
    }
};

point pivot;
int id;
char s[N];

int64 dist(point a, point b) {
    int64 dx = a.x - b.x;
    int64 dy = a.y - b.y;
    return (dx * dx + dy * dy);
}
int64 cross(point o, point a, point b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
bool angCmp(point a, point b) {
    if (!cross(pivot, a, b)) return dist(pivot, a) < dist(pivot, b);
    double dx1 = a.x - pivot.x, dx2 = b.x - pivot.x;
    double dy1 = a.y - pivot.y, dy2 = b.y - pivot.y;
    return atan2(dy1, dx1) < atan2(dy2, dx2);
}
vector <point> convex(vector <point> p) {
    int n = p.size(), p0 = 0;
    pivot = point(0, 0);
    for (int i=1;i<n;i++)
        if (p[i].y < p[p0].y || p[i].y == p[p0].y && p[i].x > p[p0].x) p0 = i;
    point temp = p[0]; p[0] = p[p0]; p[p0] = temp;
    pivot = p[0];
    sort(++p.begin(), p.end(), angCmp);
    stack <point> S;
    S.push(p[n - 1]); S.push(p[0]);
    point now(0, 0), pre(0, 0);
    int i = 1;
    while (i < n) {
        now = S.top(); S.pop();
        pre = S.top(); S.push(now);
        if ( cross(pre, now, p[i]) > 0 ) S.push(p[i++]);
        else if ( cross(pre, now, p[i]) == 0) ++i;
        else S.pop();
    }
    vector <point> ans;
    while (!S.empty()) {
        ans.pb(S.top());
        S.pop();
    }
    return ans;
}
int64 getInt(int n) {
    int64 v = 0, sign = 0;
    while (id < n && s[id] !=' ') {
        if (s[id] == '-') {
            sign = 1;
            ++id;
            continue;
        }
        v = v * 10 + s[id++] - '0';
    }
    if (sign) v=-v;
    return v;
}

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, d, caseno = 0, l;
    double alpha, add;
    int64 x, y;
    gets(s); id = 0; cases = getInt(strlen(s));
    while (cases--) {
        gets(s); id = 0;
        n = getInt(strlen(s)); ++id;
        d = getInt(strlen(s));
        vector <point> p, ans;
        for (int i=0;i<n;i++) {
            gets(s); id = 0; l = strlen(s);
            x = getInt(l); ++id;
            y = getInt(l);
            p.pb(point(x, y));
        }
        ans = convex( p ); n = ans.size();
        if (ans[0].x == ans[n-1].x && ans[0].y == ans[n-1].y) n--;
        //for (int i = 0;i < n;i++) cout << ans[i].x<<" "<<ans[i].y<<endl;
        alpha = (2 * PI) / n;
        add = alpha * 4 + alpha * 2;
        cout<<add<<endl;
        for (int i=0;i<n;i++)
            add+=sqrt(dist(ans[i], ans[(i + 1) % n]));
        printf("Case %d: %.10lf\n",++caseno, add);
    }
    
}
