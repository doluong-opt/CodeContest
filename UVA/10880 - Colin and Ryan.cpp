/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10880 - Colin and Ryan
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
#define N 100000

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
void solve(int64 C, int64 R) {
    if (C <= R) {
        puts("");
        return;
    }
    int64 m = (int64)sqrt(C);
    int64 x, y;
    vector <int64> res;
    for (int i=1;i<=m;i++) {
        if (C % i == 0) {
            x = i;
            y = C / i;
            if (x != y) {
                if (x > R) res.pb(x);
                if (y > R) res.pb(y);
            }
            else
            if (x > R) res.pb(x);
        }
    }
    sort(res.begin(), res.end());
    for (int i=0;i<res.size();i++)
        printf(" %lld",res[i]);
    puts("");
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    int64 C, R;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%lld %lld",&C,&R);
        printf("Case #%d:",++caseno);
        if (C == R) printf(" 0\n");
        else solve(C - R, R);
    }
}
