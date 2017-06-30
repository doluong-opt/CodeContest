/***********************************************
* Author - LUONG VAN DO                        *
* 12385 - Interesting Sequences ->AC
* Algorithm dp
* Time Limit 0.324s
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
#define maxN 100005

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, a[maxN], pos[maxN], f[maxN];
int64 dp[maxN];
void Read(){
    int test, ans;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d",&n);
        ans = 0;
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        memset(f, 0, sizeof(f));
        memset(pos, 0, sizeof(pos));
        pos[1] = 0; f[ a[1] ] = 1;
        for (int i=2;i<=n;i++) {
            pos[i] = f[ a[i] ];
            f[a[i]] = i;
        }
        dp[1] = 0;
        for (int i=2;i<=n;i++)
            if ( !pos[i] ) dp[i] = dp[i-1];
            else dp[i] = max(dp[i-1],dp[ pos[i] ] + 1);
        printf("%lld\n",dp[n]);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
