/***********************************************
* Author - LUONG VAN DO                        *
* 1028 - Trailing Zeroes (I) ->AC
* Algorithm Adhoc
* Time Limit 0.376s
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
#define maxN 1000005
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int64 n, Size;
bool Free[maxN];
vector <int64> V;
void sieve(){
    for (int i=1;i<maxN;i++) Free[i] = true;
    Free[1] = false;
    for (int i=3;i*i<maxN;i+=2)
        if (Free[i])
            for (int j=i*i;j<maxN;j+=2*i) Free[j] = false;
    V.pb(2);
    for (int i=3;i<maxN;i+=2)
        if (Free[i]) V.pb(i);
    Size = V.size();
}
int solve(){
    int64 ind = 0, res;
    int cnt = 0;
    res = 1;
    while ( ind < Size && (int64)V[ind] * (int64)V[ind] <= n ) {
        cnt = 0;
        while ( n % V[ind] == 0) {
            n/=V[ind];
            cnt++;
        }
        ind++;
        res *= (cnt + 1);
    }
    if ( n > 1) res*=2;
    return res - 1;
}
void Read_Input(){
    int test;
    sieve();
    scanf("%d",&test);
    FOR(t,1,test) {
        scanf("%lld",&n);
        printf("Case %d: %d\n",t,solve());
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}
