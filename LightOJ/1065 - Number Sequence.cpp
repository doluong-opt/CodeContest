/***********************************************
* Author - LUONG VAN DO                        *
* 1065 - Number Sequence ->AC
* Algorithm power matrix
* Time Limit 0.079s
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
#define maxN 35

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int mm[5] = {1, 10, 100, 1000, 10000};
int a, b, n, m, nm;
int64 ma[maxN][5];
int aa[maxN];
void init() {
    ma[1][0] = 1; ma[1][1] = 1;
    ma[1][2] = 1; ma[1][3] = 0;
    FOR(i, 2, 32) {
        ma[i][0] = ((ma[i-1][0] * ma[i-1][0]) % mm[m] + (ma[i-1][1] * ma[i-1][2]) % mm[m]) % mm[m];
        ma[i][1] = ((ma[i-1][0] * ma[i-1][1]) % mm[m] + (ma[i-1][1] * ma[i-1][3]) % mm[m]) % mm[m];
        ma[i][2] = ma[i][1];
        ma[i][3] = ((ma[i-1][2] * ma[i-1][1]) % mm[m] + (ma[i-1][3] * ma[i-1][3]) % mm[m]) % mm[m];
    }
}
void ptich(){
    nm = 0;
    while ( n ) {
        aa[nm++] = n % 2;
        n>>=1;
    }
}
int64 solve() {
    int64 ans;
    ptich();
    int tmp[] = {1, 0, 0, 1};
    int f[6];
    REP(i, nm) {
        if (!aa[i]) continue;
        f[0] = ((ma[i+1][0] * tmp[0]) % mm[m] + (ma[i+1][1] * tmp[2]) % mm[m]) % mm[m];
        f[1] = ((ma[i+1][0] * tmp[1]) % mm[m] + (ma[i+1][1] * tmp[3]) % mm[m]) % mm[m];
        f[2] = f[1];
        f[3] = ((ma[i+1][2] * tmp[1]) % mm[m] + (ma[i+1][3] * tmp[3]) % mm[m]) % mm[m];
        tmp[0] = f[0];
        tmp[1] = f[1];
        tmp[2] = f[2];
        tmp[3] = f[3];
    }
    ans = ((a * tmp[3]) % mm[m] + (b * tmp[2]) % mm[m]) % mm[m];
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d %d %d",&a,&b,&n,&m);
        init();
        printf("Case %d: %lld\n",t,solve());
    }
    return 0;
}
