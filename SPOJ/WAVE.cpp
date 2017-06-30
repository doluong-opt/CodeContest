/***********************************************
* Author LUONG VAN DO                        *
* Problem WAVE
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

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 111222333
#define N 100000

using namespace std;

inline int64 max(int64 a, int64 b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct point{
    int64 x, y;
    point(){}
    point(int64 xx, int64 yy){
        x = xx; y = yy;
    }
}p[N];
int64 dist(point a, point b) {
    int64 dx = (a.x - b.x);
    int64 dy = (a.y - b.y);
    return dx * dx + dy * dy;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int64 ans;
    int n;
    double res;
    scanf("%d", &n);
    for (int i = 1;i <= n;i++) scanf("%lld %lld", &p[i].x, &p[i].y);
    ans = 0;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            ans = max(ans, dist(p[i], p[j]));
    res = (double)sqrt(ans) / 2.0;
    printf("%.6lf\n", res);
}
