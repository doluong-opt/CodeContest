/***********************************************
* Author - LUONG VAN DO                        *
* 1148 - Mad Counting ->AC
* Algorithm Adhoc
* Time Limit 0.206s
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
#define maxN 1000005

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int f[maxN];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, n, res, x, y;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        REP(i, maxN) f[i] = 0;
        res = 0;
        FOR(i, 1, n) {
            scanf("%d",&x);
            f[x]++;
        }
        REP(i, maxN)
            if (f[i]) {
                x = f[i] / (i + 1);
                y = f[i] % (i + 1);
                res+=(x * (i + 1));
                if (y) res+=(i + 1);                
            }
        printf("Case %d: %d\n",t,res);
    }
    return 0;
}
