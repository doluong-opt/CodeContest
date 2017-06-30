/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11378 - Bey Battle
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
#define INF 5000000000000LL
#define N 100010

using namespace std;

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
    bool operator == (const point& other) const{
        return (x == other.x && y == other.y);
    }
};
point p[N];
char s[N];
int ind;
bool cmp(point a, point b) {
    if (a.x != b.x) return (a.x > b.x);
    return a.y > b.y;
}
int64 min(int64 a, int64 b) {
    return (a < b ? a : b);
}
int64 max(int64 a, int64 b) {
    return (a > b ? a : b);
}
int64 dist(point a, point b) {
    int64 dx = a.x - b.x;
    int64 dy = a.y - b.y;
    return dx * dx + dy * dy;
}
int64 merge(int64 &sz, int64 l, int64 mid, int64 r, int64 ans) {
    int64 b = p[mid].x;
    int64 temp;
    for (int i=mid;i>=l;i--) {
        if ( (p[i].x - b) * (p[i].x - b) >= ans ) break;
        for (int j=mid+1;j<=r;j++) {
            if ( (p[j].x - p[i].x) * (p[j].x - p[i].x) >= ans) break;
            
            if (temp < ans) {
                ans = temp;
                sz = max(abs(p[l].x - p[r].x), abs(p[l].y - p[r].y));
            }
            else
            if (temp == ans) sz = min(sz, max( abs(p[l].x - p[r].x), abs(p[l].y - p[r].y)));
        }
    }
    return ans;
}
int64 findDistance(int64 &sz, int64 l, int64 r, int64 &ans) {
    if (l < r) {
        if (l == r - 1) {
            sz = max(abs(p[l].x - p[r].x), abs(p[l].y - p[r].y));
            sz = min(sz, max( abs(p[l].x - p[r].x), abs(p[l].y - p[r].y)));
            return dist(p[l], p[r]);
        }
        int mid = (l + r) >> 1;
        ans = min(ans, findDistance(sz, l, mid, ans));
        ans = min(ans, findDistance(sz, mid + 1, r, ans));
        ans = min(ans, merge(sz, l, mid, r, ans));
        return ans;
    }
    return INF;
}
int64 getInt(int64 m) {
    int64 v = 0, sign = 0;
    while (ind < m && s[ind] !=' ') {
        if (s[ind] == '-') {
            sign = 1;
            ind++;
        }
        else v = v * 10 + s[ind++] - '0';
    }
    ++ind;
    if (sign) v=-v;
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int64 n, m;
    int64 min_d, sz;
    while ( scanf(" %lld ",&n) != EOF) {
        for (int i=0;i<n;i++) {
            gets(s); ind = 0; m = strlen(s);
            p[i].x = getInt(m);
            p[i].y = getInt(m);
        }
        sort(p, p + n, cmp);
        min_d = INF; sz = INF;
        findDistance(sz, 0, n - 1, min_d);
        printf("%lld\n",sz);
    }
}
