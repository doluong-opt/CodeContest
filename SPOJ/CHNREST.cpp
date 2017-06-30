/***********************************************
* Author LUONG VAN DO                        *
* Problem CHNREST
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
#define INF 1000000000000000000LL
#define N 40
#define maxN 32770
#define M 10000
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
int m, n, id, l, m1, m2;
int64 p[N];
int a[N][N], x[N];
char s[M];
int64 A[maxN], B[maxN];
map <int64, int64> AA, BB;
void getInt(int i, char s[]) {
    int j, l, v;
    j = 0; l = strlen(s);
    while (j < l) {
        while ( j < l && s[j] == ' ') ++j;
            sscanf(s + j,"%d",&v);
            a[i][v] = 1;
        while ( j < l && s[j]!=' ') ++j;
    }
}
void processa(int x[], int na) {    
    int64 total, sl, num;
    total = sl = num = 0;
    rep(i, na)
        if (x[i]) total+=p[x[i]];
    rep(i, n) {
        sl = 0;
        rep(j, na)
            if (a[i][x[j]]) sl++;
        if (sl > 2) return;
        num = num * 10 + sl;
    }
    if (!num) return;
    if (!AA[num]) {
        AA[num] = total;
        A[m1++] = num;
    }
    else
    if (total < AA[num]) AA[num] = total;
}
void processb(int x[], int nb) {
    int64 total, sl, num;
    total = sl = num = 0;
    rep(i, nb)
        if (x[i]) total+=p[x[i]];
    rep(i, n) {
        sl = 0;
        rep(j, nb)
            if (a[i][x[j]]) sl++;
        if (sl > 2) return;
        num = num * 10 + sl;
    }
    if (!num) return;
    if (!BB[num]) {
        BB[num] = total;
        B[m2++] = num;
    }
    else
    if (total < BB[num]) BB[num] = total;
}
void TryA(int i, int k) {
    if (i == m / 2 + 1) {
        processa(x, k);
        return;
    }
    rep(j, 2) {
        x[k] = i * j;
        TryA(i + 1, k + 1);
    }
}
void TryB(int i, int k) {
    if (i == m + 1) {
        processb(x, k);
        return;
    }
    rep(j, 2) {
        x[k] = i * j;
        TryB(i + 1, k + 1);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int64 ans, pivot;
    scanf("%d %d",&m,&n);
    for (int i = 0;i < n;i++)
        for (int j = 1;j <= n;j++) a[i][j] = 0;
    fr(i, 1, m) scanf("%lld ",&p[i]);
    rep(i, n) {
        gets(s);
        getInt(i, s);
    }
    m1 = m2 = pivot = 0;
    AA.clear(); BB.clear();
    TryA(1, 0);
    TryB(m / 2 + 1, 0);
    ans = INF;
    rep(i, n) pivot = pivot * 10 + 2;
    rep(i, m1)
        if (pivot == A[i] && ans > AA[A[i]]) ans = AA[A[i]];
    rep(i, m2)
        if (pivot == B[i] && ans > BB[B[i]]) ans = BB[B[i]];
    rep(i, m1) {
        int64 tmp = pivot - A[i];
        if ( BB[tmp] )
            if (ans > AA[A[i]] + BB[tmp]) ans = AA[A[i]] + BB[tmp];
    }
    if ( ans != INF && m != 1 ) printf("%lld\n", ans);
    else printf("-1\n");
}
