/***********************************************
* Author - LUONG VAN DO                        *
* 1189 - Sum of Factorials ->AC
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
uint64 x[30];
void init(){
    x[0] = 1;
    for (int i=1;i<=20;i++)
        x[i] = x[i-1] * i;
}
void solve(uint64 n){
    int i = 20;
    vector <int> res;
    while ( n < x[i] ) i--;
    res.pb(i);
    n-=x[i];
    i--;
    while ( i>=0 ){
        if ( n >= x[i] ) {
            res.pb( i );
            n-=x[i];
        }
        i--;
    }
    if ( n ) {
        printf("impossible\n");
        return;
    }
    printf("%d!",res[ res.size()-1]);
    for (int i=res.size()-2;i>=0;i--)
        printf("+%d!",res[i]);
    printf("\n");
}
void Read(){
    int test;
    uint64 n;
    init();
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%lld",&n);
        printf("Case %d: ",t);
        solve(n);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
