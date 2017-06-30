/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10078 - The Art Gallery ->AC
* Algorithm Adhoc
* Time Limit 0.008s
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
#define M 51

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
point p[M];
int cross(point o, point a, point b){
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
bool is_Convexhull(point p[], int n){
    int sign = cross(p[0], p[1], p[2]);
    for (int i=1;i<n;i++) {
        int turn = cross(p[i], p[(i+1)%n], p[(i+2)%n]);
        if (turn * sign < 0) return false;
    }
    return true;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n;
    while (scanf("%d",&n) && n) {
        for (int i=0;i<n;i++) scanf("%d %d",&p[i].x,&p[i].y);
        if ( is_Convexhull(p, n) ) puts("No");
        else puts("Yes");
    }
}
