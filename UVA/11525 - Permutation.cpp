/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11525 - Permutation ->AC
* Algorithm BIT
* Time Limit 0.272s
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
int tree[N], k;
void update(int i, int v) {
    while ( i <= k) {
        tree[i]+=v;
        i+=(i&-i);
    }
}
int get(int i) {
    int s = 0;
    while ( i ){
        s+=tree[i];
        i-=(i&-i);
    }
    return s;
}
int binary_search(int x, int l, int r) {
    while ( l<= r ) {
        int mid = (l + r) >> 1;
        if ( get(mid) >= x) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, s, x;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d",&k);
        for (int i=1;i<=k;i++) tree[i] = 0;
        for (int i=1;i<=k;i++) update(i, 1);
        for (int i=0;i<k;i++) {
            scanf("%d",&s);
            x = binary_search(s + 1, 1, k);
            update(x, -1);
            if (i) printf(" ");
            printf("%d",x);
        }
        puts("");
    }
}
