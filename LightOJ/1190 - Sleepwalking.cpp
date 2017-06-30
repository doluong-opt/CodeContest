/***********************************************
* Author - LUONG VAN DO                        *
* 1190 - Sleepwalking ->AC
* Algorithm Adhoc
* Time Limit 0.004s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
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
#define maxN 105
#define eps 1e-9
using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct point {
    int x, y;
    point(){}
    point(int xx, int yy){
        x = xx; y = yy;
    }
    bool operator ==(const point &other) const{
        return (x == other.x && y == other.y);
    }
};
double angle(point a, point b, point c) {
    double ux = b.x - a.x, uy = b.y - a.y;
    double vx = c.x - a.x, vy = c.y - a.y;
    return acos((ux * vx + uy * vy) / sqrt((ux * ux + uy * uy) * (vx * vx + vy * vy)));
}
int cross(point O, point A, point B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
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
bool inside(point a, vector <point> p) {
    int N = (int)p.size();
    for (int i=0;i<N;i++) {
        if (a == p[i]) return true;
        if ( is_on_seg(a, p[i], p[(i + 1) % N]) ) return true;
    }
    double sum = 0.0;
    for (int i=0;i<N;i++) {
        if ( cross(a, p[i], p[(i + 1) % N]) < 0)
            sum-=angle(a, p[i], p[(i + 1) % N]);
        else
            sum+=angle(a, p[i], p[(i + 1) % N]);
    }
    return ( fabs(sum - 2 * PI) <=eps || fabs(sum + 2 * PI) <=eps );
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, q, n;
    int x, y;
    point a;
    vector <point> p;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n); p.clear();
        for (int i = 0;i < n;i++) {
            scanf("%d %d",&x,&y);
            p.pb(point(x, y));
        }
        printf("Case %d:\n",t);
        scanf("%d",&q);
        while (q--) {
            scanf("%d %d",&a.x,&a.y);
            if ( inside(a, p) ) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
