/***********************************************
* Author - LUONG VAN DO                        *
* Problem 
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
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 100111
#define MAX_LOG 20
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
       point(int _x, int _y){
              x = _x; y = _y;
       }
};
int n;
point  p[N];
int f[N];
int64 ans, x, y, minXY;
vector <ii> r;
bool cmp(point a, point b) {
       if (a.x != b.x) return a.x < b.x;
       return a.y < b.y;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
       scanf("%d", &n);
       fill(f, 0);
       rep(i, n) {
              scanf("%d %d", &p[i].x, &p[i].y);
              f[p[i].y]++;
       }
       for (int i = 1;i <= 100000;i++) if (f[i] > 0) r.pb(ii(i, f[i]));
       ans = 0LL;
       for (int i = 1;i < r.size();i++) {
              x = r[i].ss; y = r[i - 1].ss;
              minXY = min(x, y) - 1;
              ans += 4 * minXY;
              minXY++;
              if (x - minXY > 0) ans += (x - minXY) * minXY;
              if (y - minXY > 0) ans += (y - minXY) * minXY;
       }
       printf("%lld\n", ans);
	return 0;
}
