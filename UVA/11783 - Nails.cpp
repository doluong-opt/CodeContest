/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11783 - Nails
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
#define N 1010

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
struct point {
    int x, y;
    point(){}
    point(int xx, int yy){
        x = xx; y = yy;
    }
};
point p1[N], p2[N];
int inc[N], ind;
char s[N];
double dist(point a, point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}
int64 cross(point o, point a, point b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
bool intersection(point a, point b, point c, point d) {
    int64 s1, s2, s3, s4;
    s1 = cross(a, c, d);
    s2 = cross(b, c, d);
    s3 = cross(c, a, b);
    s4 = cross(d, a, b);
    return (s1 * s2 < eps && s3 * s4 < eps);
}
int getInt(int m) {
    int v = 0;
    while (ind < m && s[ind] !=' ') v = v * 10 + s[ind++] - '0';
    ind++;
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, ans, add, m;
    while (gets(s) && strcmp(s,"0")) {
        ind = 0; n = getInt(strlen(s));
        for (int i=0;i<n;i++) {
            inc[i] = 0;
            gets(s); ind = 0; m = strlen(s);
            p1[i].x = getInt(m);
            p1[i].y = getInt(m);
            p2[i].x = getInt(m);
            p2[i].y = getInt(m);
        }
        ans = 0;
        for (int i=0;i<n;i++)
            for (int j=i + 1;j<n;j++)
                if (intersection(p1[i], p2[i], p1[j], p2[j])) {
                    ans++;
                    inc[i]++;
                    inc[j]++;
                }
        for (int i=0;i<n;i++)
            if (!inc[i]) ans+=2;
        printf("%d\n",ans);
    }
}
