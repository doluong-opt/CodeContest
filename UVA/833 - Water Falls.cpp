/***********************************************
* Author - LUONG VAN DO                        *
* Problem 833 - Water Falls ->AC
* Algorithm Adhoc
* Time Limit 0.012s
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
    bool operator  == (const Point& other) const{
        return (x == other.x && y == other.y);
    }
};
struct Lines{
    Point a, b;
};
Lines Line[M + 1];
bool cmp(Lines xx, Lines yy){
    return xx.b.y > yy.b.y;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, n, q, ax, by;
    Point A;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        REP(i, n) {
            scanf("%d %d %d %d",&Line[i].a.x,&Line[i].a.y,&Line[i].b.x,&Line[i].b.y);
            if (Line[i].a.y > Line[i].b.y) {
                swap(Line[i].a.x, Line[i].b.x);
                swap(Line[i].a.y, Line[i].b.y);
            }
        }
        sort(Line, Line + n, cmp);
        if (t > 1) puts("");
        scanf("%d",&q);
        while (q--) {
            scanf("%d %d",&A.x,&A.y);
            ax = A.x; by = A.y;
            REP(i, n) {
                if (by <= Line[i].a.y) continue;
                if (ax >= min(Line[i].a.x, Line[i].b.x) && ax<= max(Line[i].a.x, Line[i].b.x)) {
                    ax = Line[i].a.x;
                    by = Line[i].a.y;
                }
            }
            printf("%d\n",ax);
        }
    }
}
