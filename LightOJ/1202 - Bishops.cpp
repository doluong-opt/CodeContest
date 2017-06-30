/***********************************************
* Author - LUONG VAN DO                        *
* 1202 - Bishops ->AC
* Algorithm Adhoc
* Time Limit 0.006s
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
int r1,c1,r2,c2;
void solve(){
    int res = 0;
        if ( abs(r1 - r2) == abs(c1 - c2) ) res = 1;
    else
        if ( (r1 % 2 == 0 && c1 % 2 == 0) || (r1 % 2 == 1 && c1 % 2 == 1) ) {
            if ( ( r2 % 2 == 0 && c2 % 2 == 0) || ( r2 % 2 == 1 && c2 % 2 == 1) ) res = 2;
        }
    else
        if ((r1 % 2 == 1 && c1 % 2  == 0) || ( r1 % 2 == 0 && c1 % 2 == 1)) {
            if ((r2 % 2 == 1 && c2 % 2  == 0) || ( r2 % 2 == 0 && c2 % 2 == 1)) res = 2;
        }
    if (!res) printf("impossible\n");
    else printf("%d\n",res);
}
void Read(){
    int test;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
        printf("Case %d: ",t);
        solve();
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
