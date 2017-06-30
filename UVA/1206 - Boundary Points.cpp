/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1206 - Boundary Points ->AC
* Algorithm Graham's scan
* Time Limit 0.08s
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
#define M 500000

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
struct point{
    double x, y;
    point(){}
    point(double xx, double yy){
        x = xx; y = yy;
    }
};
vector <point> p, Convex;
char s[M];
int n, id;
point pivot;
double cross(point O, point A, point B){
    return  (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
double dist(point A, point B){
    double dx = A.x - B.x;
    double dy = A.y - B.y;
    return dx * dx + dy * dy;
}
bool angleCmp(point A, point B){
    if ( fabs(cross(pivot, A, B)) <= eps ) return dist(pivot, A) < dist(pivot, B);
    double dx1 = A.x - pivot.x; double dx2 = B.x - pivot.x;
    double dy1 = A.y - pivot.y; double dy2 = B.y - pivot.y;
    return atan2(dy1, dx1) < atan2(dy2, dx2);
}
vector <point> ConvexHull(vector <point> p){
    int N = (int)p.size();
    int p0 = 0;
    for (int i=1;i<N;i++)
        if (p[i].y < p[p0].y || p[i].y == p[p0].y && p[i].x < p[p0].x) p0 = i;
    point temp = p[0]; p[0] = p[p0]; p[p0] = temp;
    pivot = p[0];
    sort(++p.begin(), p.end(), angleCmp);
    stack <point> S;
    point now(0.0,0.0), pre(0.0,0.0);
    S.push(p[N - 1]); S.push(p[0]);
    int i = 1;
    while (i < N){
        now = S.top(); S.pop();
        pre = S.top(); S.push(now);
        if ( cross(pre, now, p[i]) >= 0) S.push(p[i++]);
        else S.pop();
    }
    vector <point> Ans;
    while (!S.empty()){
        Ans.pb(S.top());
        S.pop();
    }
    return Ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    double x, y;
    while ( gets(s) ) {
        n = strlen(s); id = 0; p.clear(); Convex.clear();
        while (id < n) {
            if (s[id] == '(') {
                ++id;
                while (id < n && s[id] ==' ') ++id;
                sscanf(s + id,"%lf",&x);
                while (id < n && s[id]!=' ' && s[id]!=',') ++id;
                while (id < n && s[id]==' ') ++id;
                if (s[id]==',') ++id;
                while (id < n && s[id]==' ') ++id;
                sscanf(s + id,"%lf",&y);
                while (id < n && s[id]==' ') ++id;
                if (s[id] ==')') ++id;
                while (id < n && s[id]==' ') ++id;
                p.pb(point(x, y));
            }
            else ++id;
        }
        Convex = ConvexHull( p );
        n = Convex.size();
        for (int i=n-2;i>=0;i--)
            cout<<"("<<Convex[i].x<<","<<Convex[i].y<<") ";
            cout<<"("<<Convex[n-2].x<<","<<Convex[n-2].y<<")"<<endl;
    }
}
