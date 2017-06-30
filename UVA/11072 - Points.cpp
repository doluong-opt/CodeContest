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
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i = b;i >= a;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define pb push_back
#define ff first
#define ss second
#define fill(arr, val) memset(arr, val, sizeof(arr))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint32 unsigned int
#define INF 1000000000
#define N 100100
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
struct point {
    int x, y;
    point(){}
    point(int _x, int _y){
        x = _x; y = _y;
    }
    bool operator == (const point &p) const { return x==p.x && y==p.y; }
};
point pivot;
int x, y;
int n, k;
vector <point> p, ans;
inline int dist(point a, point b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return (dx * dx + dy * dy);
}
inline int cross(point o, point a, point b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
inline bool angCmp(point a, point b) {
    if (!cross(pivot, a, b)) return dist(pivot, a) < dist(pivot, b);
    double dx1 = a.x - pivot.x, dx2 = b.x - pivot.x;
    double dy1 = a.y - pivot.y, dy2 = b.y - pivot.y;
    return atan2(dy1, dx1) < atan2(dy2, dx2);
}
inline int area(point a, point b, point c) {
    int s = (a.x - b.x) * (a.y + b.y);
    s += (b.x - c.x) * (b.y + c.y);
    s += (c.x - a.x) * (c.y + a.y);
    return (s > 0) ? s : -s;
}
inline bool is_on_seg(point p, point a, point b) {
    double dx = dist(p, a); dx = sqrt(dx);
    double dy = dist(p, b); dy = sqrt(dy);
    double dz = dist(a, b); dz = sqrt(dz);
    return fabs(dx + dy - dz) < eps;
}
vector <point> convex(vector <point> p) {
    int m = p.size(), p0 = 0;
    pivot = point(0, 0);
    for (int i = 1;i < m;i++)
        if (p[i].y < p[p0].y || p[i].y == p[p0].y && p[i].x > p[p0].x) p0 = i;
    point temp = p[0]; p[0] = p[p0]; p[p0] = temp;
    pivot = p[0];
    sort(++p.begin(), p.end(), angCmp);
    stack <point> st;
    st.push(p[m - 1]); st.push(p[0]);
    point now(0, 0), pre(0, 0);
    int i = 1;
    while (i < m) {
        now = st.top(); st.pop();
        pre = st.top(); st.push(now);
        if (cross(pre, now, p[i]) > 0) st.push(p[i++]);
        else st.pop();
    }
    vector <point> ans;
    while ( !st.empty() ) {
        ans.pb(st.top());
        st.pop();
    }
    return ans;
}
inline bool isInside(point p0) {
    if ( cross(ans[0], ans[1], p0) > 0) return false;
    if ( cross(ans[0], ans[n - 1], p0) < 0) return false;
    int l = 1, r = n - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (ans[mid] == p0) return true;
        int turn = cross(ans[0], ans[mid], p0);
        if (turn < 0)
            l = mid + 1;
        else if (turn > 0)
            r = mid;
        else return is_on_seg(p0, ans[0], ans[mid]);
    }
    int s0 = area(ans[0], ans[r - 1], ans[r]);
    int s1 = area(p0, ans[r], ans[r - 1]) + area(p0, ans[0], ans[r]) + area(p0, ans[0], ans[r - 1]);
    if (s0) return (s0 == s1);
    return is_on_seg(p0, ans[r], ans[0]) || is_on_seg(p0, ans[0], ans[r - 1]) || is_on_seg(p0, ans[r - 1], ans[r]);
}
inline void nextint(int &number) {
    bool sign = false; char c; number = 0;
    do { c = getchar(); } while ((c < '0' || c > '9') && (c != '-'));
    if (c == '-') sign = true, c = getchar();
    do { number = number * 10 + c - '0'; c = getchar(); }
    while (c >= '0' && c <= '9');
    if (sign) number = -number;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while ( scanf("%d", &n) != EOF ) {
	    ans.clear(); p.clear();
	    rep(i, n) {
	        nextint(x); nextint(y);
	        p.pb(point(x, y));
	    }
	    ans = convex(p); n = ans.size();
	    if (ans[0] == ans[n - 1]) n--;
	    //rep(i, n) cout << ans[i].x<<" "<<ans[i].y<<endl;
	    nextint(k);
	    rep(i, k) {
	        nextint(x); nextint(y);
	        if ( isInside(point(x, y)) ) puts("inside");
	        else puts("outside");
	    }
	}
	//cout << cross(point(0, 0), point(1, 1), point(0, 2)) << endl;
	return 0;
}
