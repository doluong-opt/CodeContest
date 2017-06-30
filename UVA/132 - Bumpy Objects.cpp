/***********************************************
* Author - LUONG VAN DO                        *
* Problem 132 - Bumpy Objects ->AC
* Algorithm convexhull
* Time Limit  0.008s
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
#define NN 100000

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
    int x, y, ind;
    point(){}
    point(int xx, int yy, int id){
        x = xx; y = yy; ind = id;
    }
};
point pivot;
vector <point> p, convex;
int dist(point A, point B){
    int dx = A.x - B.x;
    int dy = A.y - B.y;
    return (dx * dx + dy * dy);
}
int cross(point O, point A, point B){
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
bool angleCmp(point A, point B) {
    if (!cross(pivot, A, B)) return dist(pivot, A) < dist(pivot, B);
    double dx1 = A.x - pivot.x; double dx2 = B.x - pivot.x;
    double dy1 = A.y - pivot.y; double dy2 = B.y - pivot.y;
    return (atan2(dy1, dx1) < atan2(dy2, dx2));
}
vector <point> ConvexHull(vector <point> P) {
    pivot = point(0, 0, -1);
    int P0 = 0, N = (int)P.size();
    for (int i=1;i<N;i++)
        if (P[i].y < P[P0].y || P[i].y == P[P0].y && P[i].x > P[P0].x) P0 = i;
    point temp = P[0]; P[0] = P[P0]; P[P0] = temp;
    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp);
    point now, pre;
    stack <point> S;
    S.push(P[N-1]); S.push(P[0]);
    int i = 1;
    while ( i < N ) {
        now = S.top(); S.pop();
        pre = S.top(); S.push( now );
        if ( cross(pre, now, P[i]) >= 0) S.push(P[i++]);
        else S.pop();
    }
    vector <point> Ans;
    while ( !S.empty() ) {
        Ans.pb(S.top());
        S.pop();
    }
    return Ans;
}
bool ang(point a, point b, point c) {
    int ux = b.x - a.x, uy = c.x - a.x;
    int vx = b.y - a.y, vy = c.y - a.y;
    return (ux * uy + vx * vy >= 0);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    char s[NN];
    point I, A, B;
    int n, x, y, m, ans;
    while (gets(s) && strcmp(s,"#")) {
        scanf("%d %d",&I.x,&I.y);
        n = 0; p.clear();
        while ( scanf(" %d %d ",&x,&y) && (x + y) ) {
            p.pb(point(x, y, n));
            n++;
        }
        convex = ConvexHull( p ); m = convex.size(); m--;
        ans = p.size() - 1;
        for (int i=0;i<m;i++) {
            A = convex[i];
            B = convex[(i + 1) % m];
            if ( cross(A, I, B) != 0 && ang(A, I, B) && ang(B, I, A) ) {
                x = convex[i].ind;
                y = convex[(i + 1)  % m].ind;
                ans = min(ans, max(x, y));
            }
        }
        printf("%-19s %d\n",s, ans + 1);
    }
}
