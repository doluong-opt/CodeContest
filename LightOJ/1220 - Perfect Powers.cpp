/***********************************************
* Author - LUONG VAN DO                        *
* 1220 - Perfect Powers ->AC
* Algorithm math
* Time Limit 0.008s
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
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int y;
bool check(int64 c, int64 x) {
    y = (int)(log2(x) / log2(c));
    return (y > 0);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, ok;
    int64 x, ans, m;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%lld",&x);
        ok = 0;
        if (x > 0) {
            m = (int)sqrt(x);            
            for (int i=2;i<=m;i++) {
                int64 b = i;
                int64 y = x;
                int64 cnt = 0;
                while ( y % b == 0) y/=b, cnt++;
                
                if (y == 1) {
                    printf("Case %d: %d\n",t,cnt);
                    ok = 1;
                    break;
                }
            }
            if (!ok) printf("Case %d: 1\n",t);
        }
        else {
            m = (int)(sqrt(x*-1));
            for (int i=-2;i>=-m;i--) {
                int64 b = i;
                int64 y = x;
                int64 cnt = 0;
                while ( y % b == 0) y/=b, cnt++;
                if (y == 1) {
                    printf("Case %d: %d\n",t,cnt);
                    ok = 1;
                    break;
                }
            }
            if (!ok) printf("Case %d: 1\n",t);
        }
    }
    return 0;
}
