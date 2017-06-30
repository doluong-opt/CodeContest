/***********************************************
* Author - LUONG VAN DO                        *
* 1213 - Fantasy of a Summation ->AC
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
#define maxN 1005

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int MOD, K, n;
int a[maxN];
int64 square(int64 x){
    return ((x % MOD) * (x % MOD)) % MOD;
}
int64 mod(int64 x, int64 m){
    if (m == 0) return 1;
    if (m == 1) return x;
    if (m % 2 == 0) return square( ( mod(x, m/2) % MOD) ) % MOD;
    else return ((x % MOD) * mod(x, m-1) % MOD) % MOD;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    int64 res, ans;
    scanf("%d",&test);
    FOR(t, 1, test) {
        res = 0;
        scanf("%d %d %d",&n,&K,&MOD);
        REP(i, n) {
            scanf("%d",&a[i]);
            res = (res + a[i]) % MOD;
        }
        ans = (mod(n, K-1) % MOD * K) % MOD;
        printf("Case %d: %lld\n",t,(ans * res) % MOD);
    }
    return 0;
}
