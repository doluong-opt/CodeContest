/***********************************************
* Author - LUONG VAN DO                        *
* 1138 - Trailing Zeroes (III) ->AC
* Algorithm Adhoc
* Time Limit 0.020s
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
#define maxN 50001

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

bool check(int M, int Q){
    int r = 0;
    for (int i=5;i<=M;i*=5)
        r+=( M / i );
    return (r >= Q);
}
int solve(int Q){
    int L = 5, R = INF;
    int res = -1;
    while (L<=R) {
        int mid = (L + R) >> 1;
        if ( check(mid, Q) ) {
            res = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }
    return res;
}
bool ok(int nn, int Q){
    int r = 0;
    for (int i=5;i<=nn;i*=5)
        r+=(nn / i);
    return (r == Q);
}
void Read() {
    int test, ans, Q;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d",&Q);
        ans = solve( Q );
        if (ans !=-1 && ok(ans, Q) ) printf("Case %d: %d\n",t,ans);
        else printf("Case %d: impossible\n",t);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
