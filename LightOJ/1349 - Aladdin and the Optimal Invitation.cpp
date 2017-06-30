/***********************************************
* Author - LUONG VAN DO                        *
* 1349 - Aladdin and the Optimal Invitation ->AC
* Algorithm dp
* Time Limit 0.22s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
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
#define maxN 50005

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
ii x[maxN], y[maxN];
int m, n, q, best, id;
char s[1001];
bool cmp(ii a, ii b) {
    return a.A < b.A;
}
int position(ii *a) {
    int64 sum[maxN], cost[maxN];
    sum[0] = cost[0] = 0;
    for (int i=1;i<q;i++) {
        sum[i] = sum[i-1] + a[i-1].B;
        cost[i] = cost[i-1] + sum[i] * (int64)(a[i].A - a[i-1].A);
    }
    int64 W1, W2, best;
    int pos;
    best = cost[q-1]; pos = a[q-1].A; W1 = W2 = 0;
    for (int i=q-2;i>=0;i--) {
        W1+=a[i + 1].B;
        W2+=W1 * (int64)(a[i+1].A - a[i].A);
        if (W2 + cost[i] < best) {
            best = W2 + cost[i];
            pos = a[i].A;
        }
    }
    return pos;
}
int getInt(int n) {
    int v = 0;
    while (id < n && s[id]!=' ') v = v * 10 + s[id++] - '0';
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, w;
    int xx, yy, l;
    gets(s); id = 0;
    cases = getInt(strlen(s));
    while (cases--) {
        gets(s);
        gets(s); id = 0; l = strlen(s);
        n = getInt(l); ++id;
        m = getInt(l); ++id;
        q = getInt(l);
        for (int i=0;i<q;i++) {
            gets(s); id = 0; l = strlen(s);
            x[i].A = getInt(l); ++id;
            y[i].A = getInt(l); ++id;
            w = getInt(l);
            x[i].B = w;
            y[i].B = w;
        }
        sort(x, x + q, cmp);
        sort(y, y + q, cmp);
        xx = position(x); yy = position(y);
        printf("Case %d: %d %d\n",++caseno,xx,yy);
    }
    return 0;
}
