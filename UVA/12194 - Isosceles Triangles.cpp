/***********************************************
* Author - LUONG VAN DO                        *
* Problem 12194 - Isosceles Triangles ->AC
* Algorithm Adhoc
* Time Limit 2.064s
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
#define M 1010

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
};
struct node{
    int64 id, side;
    node(){}
    node(int64 idd, int64 sidee){
        id = idd; side = sidee;
    }
    bool operator < (const node& other) const{
        return side < other.side;
    }
};
point p[M];
int64 d[M][M];
node data[M][M];
int64 dist(point a, point b) {
    int64 dx = a.x - b.x;
    int64 dy = a.y - b.y;
    return dx * dx + dy * dy;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n;
    while (scanf("%d",&n) && n) {
        for (int i=0;i<n;i++) scanf("%lld %lld",&p[i].x,&p[i].y);
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                d[i][j] = d[j][i] = dist(p[i], p[j]);
                data[i][j].id = j;
                data[i][j].side = dist(p[i], p[j]);
            }
            sort(data[i], data[i] + n);
        }
        int Ans = 0;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++) {
                int64 m = data[i][j].side;
                for (int k=j+1; m == data[i][k].side && k<n; ++k)
                    if ( d[data[i][j].id][data[i][k].id] != m) Ans++;
            }
        printf("%d\n",Ans);
    }
}
