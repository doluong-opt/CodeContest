/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11665 - Chinese Ink ->AC
* Algorithm geometry
* Time Limit 0.232s
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

#define eps 1e-8
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
    point(int64 xx, int64 yy){
        x = xx; y = yy;
    }
    bool operator == (const point& other) const{
        return (x == other.x && y == other.y);
    };
};
int64 m, n;
vector <point> poly;
vector < vector <point> > polygon;
char s[N];
int64 ind, parent[N], mark[N];

int64 getInt(int64 m) {
    int64 v = 0, sign = 0;
    while (ind < m && s[ind] !=' ') {
        if (s[ind] == '-') {
            sign = 1;
            ind++;
        }
        else v = v * 10 + s[ind++] - '0';
    }
    ++ind;
    if (sign) v=-v;
    return v;
}

void init() {
    for (int i=0;i<n;i++) parent[i] = i;
}

int64 findSet(int64 x) {
    return (x == parent[x] ? x : parent[x] = findSet(parent[x]));
}

int64 unionSet(int64 x, int64 y){
    parent[findSet(x)] = findSet(y);
}

double angle(point a, point b, point c) {
    double ux = b.x - a.x, uy = b.y - a.y;
    double vx = c.x - a.x, vy = c.y - a.y;
    return acos((ux * vx + uy * vy) / sqrt((ux * ux + uy * uy) * (vx * vx + vy * vy)));
}

double dist(point A, point B){
    double dx = A.x - B.x;
    double dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}

bool is_on_seg(point p, point A, point B){
    if (p == A || p == B) return true;
    return ( fabs(dist(p, A) + dist(p, B) - dist(A, B)) <= eps);
}

int64 cross(point o, point a, point b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool inside(point a, vector <point> p) {
    int64 n = (int)p.size();
    for (int i=0;i<n;i++) {
        if (a == p[i]) return true;
        if ( is_on_seg(a, p[i], p[(i + 1) % n]) ) return true;
    }
    double sum = 0.0;
    for (int i=0;i<n;i++) {
        if ( cross(a, p[i], p[(i + 1) % n]) < 0)
            sum-=angle(a, p[i], p[(i + 1) % n]);
        else
            sum+=angle(a, p[i], p[(i + 1) % n]);
    }
    return ( fabs(sum - 2 * PI) <=eps || fabs(sum + 2 * PI) <=eps );
}
bool inter(point a, point b, point c, point d) {
    int64 s1, s2, s3, s4;
    s1 = cross(a, c, d);
    s2 = cross(b, c, d);
    s3 = cross(c, a, b);
    s4 = cross(d, a, b);
    return (s1 * s2 < 0 && s3 * s4 < 0);
}
bool intersection(vector <point> a, vector <point> b) {
    int64 n = a.size(), m = b.size();
    for (int i=0;i<n;i++) {
        if ( inside(a[i], b) ) return true;
        for (int j=0;j<m;j++)
            if ( inter(a[i], a[(i + 1) % n], b[j], b[(j + 1) % m]) ) return true;
    }
    for (int i=0;i<m;i++)
        if ( inside(b[i], a) ) return true;
        
    return false;
}

void solve(int64 i, int64 j) {
    vector <point> a, b;
    a = polygon[i]; b = polygon[j];
    if ( intersection(a, b) ) unionSet(i, j);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int64 x, y, ans;
    while (scanf(" %lld ",&n) && n){
        polygon.clear();
        for (int i=0;i<n;i++) {
            mark[i] = 0;
            gets(s); m = strlen(s); ind = 0; poly.clear();
            while (ind < m) {
                x = getInt(m);
                y = getInt(m);
                poly.pb(point(x, y));
            }
            polygon.pb(poly);
        }
        init(); ans = 0;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if ( findSet(i) != findSet(j) ) solve(i, j);
        for (int i=0;i<n;i++) findSet(i);
        for (int i=0;i<n;i++) mark[parent[i]] = 1;
        for (int i=0;i<n;i++)
            if (mark[i]) ans++;
        printf("%lld\n",ans);
    }
}
