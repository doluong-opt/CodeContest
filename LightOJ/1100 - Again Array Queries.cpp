/***********************************************
* Author - LUONG VAN DO                        *
* 1100 - Again Array Queries ->AC
* Algorithm Adhoc
* Time Limit 1.356s
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
int a[maxN], n;
int solve(int x, int y) {
    int b[maxN], m = 0;
    int ans;
    for (int i=x;i<=y;i++)
        b[m++] = a[i];
    sort(b, b + m);
    ans = INF;
    REP(i, m - 1)
        if ( b[i+1] - b[i] < ans ) ans = b[i+1] - b[i];
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, q, x, y;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&n,&q);
        REP(i, n)
            scanf("%d",&a[i]);
        printf("Case %d:\n",t);
        FOR(i, 1, q) {
            scanf("%d %d",&x,&y);
            if (y - x + 1 > 1000) printf("0\n");
            else printf("%d\n",solve(x, y));
        }
    }
    return 0;
}
