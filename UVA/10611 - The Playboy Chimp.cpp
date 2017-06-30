/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10611 - The Playboy Chimp ->AC
* Algorithm binary sreach
* Time Limit 0.036s
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
#define N 50010

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
int a[N], n;
int fl(int x, int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if ( a[mid] > x ) r = mid - 1;
        else l = mid + 1;
    }
    if (l >= n) return -1;
    return a[l];
}
int fr(int x, int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if ( a[mid] < x ) l = mid + 1;
        else r = mid - 1;
    }
    if (r < 0) return -1;
    return a[r];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int q, x, lo, hi;
    while ( scanf("%d",&n) != EOF){
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        scanf("%d",&q);
        while (q--) {
            scanf("%d",&x);
            lo = fr(x, 0, n - 1);
            hi = fl(x, 0, n - 1);
            
            if (lo != -1) printf("%d",lo);
            else printf("X");
            printf(" ");
            if (hi != -1) printf("%d",hi);
            else printf("X");
            puts("");
        }
    }
}
