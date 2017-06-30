// =============================================================================
// Author LUONG VAN DO
// Problem
// Algorithm
// Time Limit
// =============================================================================
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
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint unsigned int
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 111222333
#define N 555
struct stones{
    int x, y, w;
    stones(){}
    stones(int _x, int _y, int _w){
        x = _x; y = _y; w = _w;
    }
}p[N * N];
int n, m, a[N];
uint tree[N][N], ans, inc;
vector <stones> d;
bool cmp(stones a, stones b) {
    if (a.w != b.w) return a.w < b.w;
    if (a.x != b.x) return a.x > b.x;
    return a.y < b.y;
}
void update(int x, int y, uint v) {
    while ( x ) {
        int y1 = y;
        while ( y1 <= n) {
            tree[x][y1] += v;
            y1 += (y1 & -y1);
        }
        x -= (x & -x);
    }
}
uint get(int x, int y) {
    uint res = 0;
    while ( x <= n ) {
        int y1 = y;
        while ( y1 ) {
            res += tree[x][y1];
            y1 -= (y1 & -y1);

        }
        x += (x & -x);
    }
    return res;
}
int main(){
	freopen("exam.inp","r",stdin);
	freopen("exam.out","w",stdout);
	int cases, caseno = 0;
	scanf("%d", &cases);
    while ( cases-- ) {
        scanf("%d", &n);
        fr(i, 1, n)
            fr(j, 1, n) tree[i][j] = 0;
        fr(i, 1, n) scanf("%d", &a[i]);
        m = 0;
        fr(i, 1, n)
            fr(j, i + 1, n)
                p[m++] = stones(i, j, a[i] + a[j]);
        sort(p, p + m, cmp);
        ans = 0; d.clear();
        rep(i, m) {
            if (i && p[i].w > p[i - 1].w) {
                while ( !d.empty() ) {
                    update(d.back().x, d.back().y, d.back().w);
                    d.pop_back();
                }
            }
            inc = get(p[i].x + 1, p[i].y - 1) + 1;
            ans += inc;
            d.pb(stones(p[i].x, p[i].y, inc));
        }
        printf("Case %d: %u\n", ++caseno, ans);
    }
}

