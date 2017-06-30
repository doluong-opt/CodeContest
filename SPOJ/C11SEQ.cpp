/***********************************************
* Author LUONG VAN DO                        *
* Problem C11SEQ
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
struct node{
    int64 x, y;
    node(){}
    node(int64 xx, int64 yy){
        x = xx; y = yy;
    }
};
node a[N];
int64 n, l, r, m, p;
int64 s[3 * N], ind[3 * N], f[3 * N], tree[3 * N];

int64 conver(int64 x, int64 l, int64 r) {
    while (l<=r) {
        int64 mid = (l + r) >> 1;
        if ( f[mid] == x ) return mid;
        if ( f[mid] > x ) r = mid - 1;
        else l = mid + 1;
    }
}

void update(int64 i) {
    while ( i<=p ) {
        tree[i]++;
        i+=(i&-i);
    }
}

int64 getSum(int64 i) {
    int64 s = 0;
    while ( i ) {
        s+=tree[i];
        i-=(i&-i);
    }
    return s;
}

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int64 x, res;
    scanf("%lld %lld %lld",&n,&l,&r);
    s[0] = m = p = 0;
    fr(i, 1, n) {
        scanf("%lld",&x);
        s[i] = s[i - 1] + x;
        ind[++m] = s[i];
    }
    fr(i, 1, n) {
        a[i].x = s[i - 1] + l;
        a[i].y = s[i - 1] + r;
        ind[++m] = a[i].x;
        ind[++m] = a[i].y;
    }
    sort(ind + 1, ind + m + 1);
    ind[0] = ind[1] - 1;
    fr(i, 1, m)
        if ( ind[i] > ind[i - 1] ) f[++p] = ind[i];
    fr(i, 1, n) {
        s[i] = conver(s[i], 1, p);
        a[i].x = conver(a[i].x, 1, p);
        a[i].y = conver(a[i].y, 1, p);
    }
    res = 0;
    frr(i, 1, n) {
        update( s[i] );
        res+=(getSum(a[i].y) - getSum(a[i].x - 1));
    }
    printf("%lld\n", res);
}
