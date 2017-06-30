/***********************************************
* Author - LUONG VAN DO                        *
* Problem 675 - Convex Hull of the Polygon ->AC
* Algorithm Graham's scan
* Time Limit  0.092s
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
#define M 100000

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
    int x, y;
    Point(){}
    Point(int xx, int yy){
        x = xx; y = yy;
    }
    bool operator < (const Point &other) const{
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    bool operator ==(const Point &other) const{
        return (x == other.x && y == other.y);
    }
    bool operator !=(const Point &other) const{
        return !(*this == other);
    }
};
vector <Point> convex, p;
int cross(Point O, Point A, Point B){
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
vector<Point> convex_hull(vector<Point> P){
    int n = P.size(), k = 0;
    vector <Point> r(2 * n);
    sort(P.begin(), P.end());
    for(int i = 0; i < n; ++i){
        while(k >= 2 && cross(r[k - 2], r[k - 1], P[i]) <= 0) --k;
        r[k++] = P[i];
    }
    for(int i = n - 2, t = k + 1; i >= 0; --i){
        while(k >= t && cross(r[k - 2], r[k - 1], P[i]) <= 0) --k;
        r[k++] = P[i];
    }
    r.resize(k - 1);
    return r;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    char s[1010];
    int n, blank = 0, z, start;
    Point A;
    while (gets(s)) {
        p.clear();
        do {
            if ( sscanf(s," %d, %d ",&A.x,&A.y) != 2) break;
            p.pb( A );
        } while (gets(s) && strlen(s));
        convex = convex_hull( p );
        n = convex.size();
        if ( blank ) puts("");
        blank = 1; start = -1; z = p.size();
        for (int i=0,j;i<n;i++) {
            for (j = 0;j < z && p[j]!=convex[i]; ++j);
            if (j < z) start = i, z = j;
        }
        for (int i=0;i<=n;i++)
            printf("%d, %d\n",convex[(start + i) % n].x,convex[(start + i) % n].y);
    }
}
