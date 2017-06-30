/***********************************************
* Author - LUONG VAN DO                        *
* 1319 - Monkey Tradition ->AC
* Algorithm Extended Euclid
* Time Limit 0.045s
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
#define maxN 15

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int p[maxN], r[maxN];
int64 m[maxN], xx[maxN];
int n;
int64 x, y, d;
void extended(int64 a, int64 b){
    if (b == 0) {
        x = 1; y = 0; d = a;
        return;
    }
    extended(b, a % b);
    int64 x1 = y;
    int64 y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    int64 M;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        M = 1;
        FOR(i, 1, n) {
            scanf("%d %d",&p[i],&r[i]);
            M*=p[i];
        }
        FOR(i, 1, n) {
            m[i] = M / p[i];
            extended(m[i], p[i]);
            x = x * (r[i] / d);
            x = x % p[i];
            if (x<0) x+=p[i];
            xx[i] = x;
        }
        int64 res = 0;
        FOR(i, 1, n) {
            res+=(m[i] * xx[i]) % M;
        }
        res = res % M;
        if (res >=0 ) printf("Case %d: %lld\n",t,res % M);
        else printf("Case %d: Impossible\n",t);
    }
    return 0;
}
