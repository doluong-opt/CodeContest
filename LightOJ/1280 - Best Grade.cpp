/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1280 - Best Grade ->AC
* Algorithm binary
* Time Limit 1.750s
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
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define frr(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i=n - 1; i>=0; i--)
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 21000

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
int n, d, p[N], m[N], id;
double f[N];
char s[N];
bool check(double e) {
    double sum;
    for (int i=0;i<n;i++)
        f[i] = p[i] - e * m[i];
    sort(f, f + n);
    sum = 0.0;
    for (int i = n - 1;i >= d; i--) sum+=f[i];
    
    return (sum > 0.0 || fabs(sum) <= eps);
}
int getNext(int m) {
    int v = 0;
    while (id < m && s[id] !=' ') v = v * 10 + s[id++] - '0';
    ++id;
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, l;
    double lo, hi, ans;
    gets(s); l = strlen(s); id = 0; cases = getNext( l );
    while ( cases-- ) {
        gets(s);
        gets(s); l = strlen(s); id = 0;
        n = getNext( l ); d = getNext( l );
        for (int i=0;i<n;i++) {
            gets(s); l = strlen(s); id = 0;
            p[i] = getNext(l); m[i] = getNext(l);
        }
        lo = 0.0; hi = 1.0;
        for (int i=0;i<50;i++) {
            double mid = (lo + hi) / 2.0;
            if ( check(mid) ) {
                ans = mid;
                lo = mid;
            }
            else hi = mid;
        }
        printf("Case %d: %.10lf\n", ++caseno, ans * 100.0);
    }
}
