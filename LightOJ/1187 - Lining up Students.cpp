/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1187 - Lining up Students ->AC
* Algorithm BIT
* Time Limit 0.428s
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
#define N 100010

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
int a[N], tree[N], n, ix;
char s[8 * N];
void update(int i, int x) {
    while (i <= n) {
        tree[i]+=x;
        i+=(i&-i);
    }
}
int get(int i) {
    int s = 0;
    while ( i ) {
        s+=tree[i];
        i-=(i&-i);
    }
    return s;
}
int binary_search(int x, int l, int r) {
    while (l<=r) {
        int mid = (l + r) >> 1;
        if (get(mid) >= x) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int getInt(int n) {
    int val = 0;
    while (ix < n && s[ix]!=' ') val = val * 10 + s[ix++] - '0';
    return val;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, Ans, l;
    gets(s); ix = 0;
    cases = getInt(strlen(s));
    while (cases--) {
        gets(s); ix = 0;
        n = getInt(strlen(s));
        for (int i=0;i<=n;i++) tree[i] = 0;
        gets(s); l = strlen(s); ix = 0;
        for (int i=1;i<=n;i++) {
            a[i] = getInt(l); ++ix;
            update(i, 1);
        }
        for (int i=n;i>=1;i--) {
            Ans = binary_search(i - a[i], 1, n);
            update(Ans, -1);
        }
        printf("Case %d: %d\n",++caseno,Ans);
    }
}
