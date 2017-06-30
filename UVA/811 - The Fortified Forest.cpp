/***********************************************
* Author - LUONG VAN DO                        *
* Problem 811 - The Fortified Forest ->AC
* Algorithm Graham's scan
* Time Limit 0.840s
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
#define M 20

#define eps 1e-9
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int64 And(int64 mask, int64 bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct point{
    int64 x, y, v, l;
    point(){}
    point(int64 xx, int64 yy, int64 vv, int64 ll){
        x = xx; y = yy; v = vv; l = ll;
    }
};
point p[M], pivot;
vector <point> convex, s, t;
int64 len(point a, point b){
    int64 dx = a.x - b.x;
    int64 dy = a.y - b.y;
    return (dx * dx + dy * dy);
}
int64 cross(point o, point a, point b){
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
bool angleCmp(point a, point b){
    if (!cross(pivot, a, b)) return len(pivot, a) < len(pivot, b);
    double dx1 = a.x - pivot.x; double dx2 = b.x - pivot.x;
    double dy1 = a.y - pivot.y; double dy2 = b.y - pivot.y;
    return atan2(dy1, dx1) < atan2(dy2, dx2);
}
vector <point> convexhull(vector <point> p) {
    int n = (int)p.size();
    if (n <= 3) return p;
    int p0 = 0;
    for (int i=1;i<n;i++)
        if (p[i].y < p[p0].y || p[i].y == p[p0].y && p[i].x > p[p0].x) p0 = i;
    point temp = p[0]; p[0] = p[p0]; p[p0] = temp;
    pivot = p[0];
    sort(++p.begin(), p.end(), angleCmp);
    stack <point> S;
    point now(0,0,0,0), pre(0,0,0,0);
    S.push(p[n-1]); S.push(p[0]);
    int i = 1;
    while (i < n) {
        now = S.top(); S.pop();
        pre = S.top(); S.push(now);
        if ( cross(pre, now, p[i]) > 0) S.push(p[i++]);
        else S.pop();
    }
    vector <point> ss;
    while (!S.empty()){
        ss.pb(S.top());
        S.pop();
    }
    return ss;
}
int64 cal(int64 mm){
    int64 z = 0;
    while ( mm ) {
        if (mm % 2 == 0) z++;
        mm/=2;
    }
    return z;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int64 x, y, lim, smin, value, sz, status, trees;
    int64 blank = 0, Cases = 0;
    int n;
    double need, wood, mini, maxi;
    while ( scanf("%d",&n) && n){
        for (int i=0;i<n;i++)
            scanf("%lld %lld %lld %lld",&p[i].x,&p[i].y,&p[i].v,&p[i].l);
        lim = (1<<n); smin = INF;
        status = lim - 1;
        for (int i=0;i<lim;i++) {
            s.clear(); t.clear(); convex.clear();
            wood = value = 0;
            for (int j=0;j<n;j++)
                if (And(i, j)) s.pb(p[n-j-1]);
            else
                t.pb(p[n-j-1]);
            for (int k=0;k<t.size();k++) {
                wood+=t[k].l;
                value+=t[k].v;
            }
            
            convex = convexhull( s );
            sz = convex.size(); need = 0.0;
            for (int h=0;h<sz;h++)
                need+=(double)sqrt(len(convex[h], convex[(h + 1) % sz]));
            if (wood >= need) {
                if (smin > value) {
                    smin = value;
                    status = i;
                    mini = need;
                    maxi = wood;
                }
                else
                if (smin == value && cal(status) > cal(i)) {
                    status = i;
                    mini = need;
                    maxi = wood;
                }
            }
        }
        if ( blank ) puts("");
        blank = 1;
        printf("Forest %lld\n",++Cases);
        printf("Cut these trees:");
        trees = n; vector <int64> ans;
        while ( status ) {
            if (status % 2 == 0) ans.pb(trees);
            status/=2;
            trees--;
        }
        while ( trees ) ans.pb(trees--);
        for (int i=ans.size()-1;i>=0;i--) printf(" %lld",ans[i]);
        printf("\n");
        printf("Extra wood: %.2lf\n",maxi - mini);
    }
}
