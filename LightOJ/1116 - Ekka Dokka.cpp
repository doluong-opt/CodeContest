/***********************************************
* Author - LUONG VAN DO                        *
* 1116 - Ekka Dokka ->AC
* Algorithm Adhoc
* Time Limit 0.013s
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
void Read(){
    int test;
    uint64 w,s,cnt;
    scanf("%d",&test);
    for (int t=1;t<=test;t++){
        scanf("%lld",&w);
        if ( w & 1 ) printf("Case %d: Impossible\n",t);
        else {
            cnt = 2;
            while ( true ) {
                if (w % cnt == 0) {
                    s = w / cnt;
                    if (s & 1) break;
                }
                cnt+=2;
            }
            printf("Case %d: %lld %lld\n",t,s,cnt);
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
