/***********************************************
* Author - LUONG VAN DO                        *
* 1014 - Ifter Party ->AC
* Algorithm math
* Time Limit 0.062s
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
int64 P, L;
vector <int64> res;
vector <int64> :: iterator it;
void solve(){
    int64 m = (int64)(sqrt(P));
    for (int i=1;i<=m;i++)
        if ( P % i == 0 ) {
            if ( i > L )
                res.pb( i );
            if ( P / i > L && (P / i)!=i)
                res.pb(P / i);
        }
    sort(res.begin(), res.end());
}
void Read(){
    int test;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%lld %lld",&P,&L);
        P = P - L;
        if (P <= L) {
            printf("Case %d: impossible\n",t);
            continue;
        }
        solve();
        printf("Case %d:",t);
        for (it=res.begin(); it!=res.end(); it++)
            printf(" %lld",*it);
            printf("\n");
        res.clear();
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
