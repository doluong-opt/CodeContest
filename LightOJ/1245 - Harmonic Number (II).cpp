/***********************************************
* Author - LUONG VAN DO                        *
* 1245 - Harmonic Number (II) ->AC
* Algorithm math
* Time Limit 0.592s
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
#define FOR(i, a, b) for (int i=a; i<=b; i++)
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
int64 n;
int64 solve(){
    int64 cnt, res, a, b,p1,p2, len;
    int64 m = (int64)sqrt(n);
    cnt = 1; res = len = 0; b = n;
    p1 = n;
    res+=p1;
    len++;
    for (int i=2;i<=m;i++) {
        p2 = (n / i);
        res+=p2;
        len++;
        a = b - (p1 - p2) + 1;
        res+=(cnt * (b - a + 1));
        cnt++;
        len+=(p1 - p2);
        p1 = p2;
        b = a - 1;
    }
    while ( len < n ) {
        m++;
        res+=(n / m);
        len++;
    }
    return res;
}
void Read_Input(){
    int test;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%lld",&n);
        printf("Case %d: %lld\n",t,solve());
    }
}
int main(){
    //freopen("exam.inp","r",stdin);
    //freopen("exam.out","w",stdout);
    Read_Input();
    return 0;
}
