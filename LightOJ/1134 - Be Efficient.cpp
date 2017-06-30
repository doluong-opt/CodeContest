/***********************************************
* Author - LUONG VAN DO                        *
* 1134 - Be Efficient ->AC
* Algorithm combination
* Time Limit 0.1s
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
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int a[maxN], x[maxN], n, m;
int64 mod[maxN];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    uint64 ans;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&n,&m);
        REP(i, m) mod[i] = 0;
        x[0] = 0;
        FOR(i, 1, n) {
            scanf("%d",&a[i]);
            x[i] = (x[i-1] + a[i]) % m;
            mod[x[i]]++;
        }
        mod[0]++; ans = 0;
        REP(i, m)
            ans+=(mod[i] * (mod[i] - 1)) / 2;
        printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}
