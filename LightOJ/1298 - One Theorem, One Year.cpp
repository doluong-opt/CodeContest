/***********************************************
* Author - LUONG VAN DO                        *
* 1298 - One Theorem, One Year ->AC 
* Algorithm math
* Time Limit 0.018s
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
#define INF 1000000007
#define maxN 3605
#define N 500
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector <int> primes;
int mark[maxN], sz, k, p;
int64 dp[N + 1][N + 1];
int64 ans[N + 1];
void sieve() {
    for (int i=1;i<=3600;i++) mark[i] = 1;
    mark[1] = 0;
    for (int i=4;i<=3600;i+=2) mark[i] = 0;
    for (int i=3;i<=3600;i+=2)
        if (mark[i])
            for (int j=i*i;j<=3600;j+=i+i) mark[j] = 0;
    primes.pb(1);
    primes.pb(2);
    for (int i=3;i<=3600;i+=2)
        if (mark[i]) primes.pb(i);
    sz = primes.size();
}
void initial(){
    sieve();
    int64 x, y;
    ans[1] = 1;
    FOR(i, 2, 500)
        ans[i] = ((ans[i-1] % INF) * (primes[i] - 1)) % INF;
    FOR(i, 0, 500) dp[i][0] = 1;
    FOR(i, 1, 500)
        FOR(j, 1, 500) {
            x = dp[i-1][j];
            y = ((dp[i][j-1] % INF) * (primes[i] % INF)) % INF;
            dp[i][j] = (x + y) % INF;
        }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    initial();
    int64 res;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&k,&p);
        res = ((ans[p] % INF) * (dp[p][k-p] % INF)) % INF;
        printf("Case %d: %lld\n",t,res);
    }
    return 0;
}
