/***********************************************
* Author - LUONG VAN DO                        *
* 1226 - One Unit Machine ->AC
* Algorithm math
* Time Limit 0.505s
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
#define maxN 1001
#define MAX 1000001
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int64 k[maxN], n, inc[maxN];
int64 x, y, d, ans;
int64 g[MAX + 5], f[MAX + 5];
void eculid(int64 a, int64 b){
    if (b == 0) {
        x = 1; y = 0; d = a;
        return;
    }
    eculid(b, a % b);
    int64 x1, y1;
    x1 = y;
    y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}
void init() {
    f[0] = 1; g[0] = 1;
    FOR(i, 1, 1000000) {
        f[i] = ((f[i-1] % INF) * (i % INF)) % INF;
        eculid(f[i], INF);
        while (x < 0) x+=INF;
        g[i] = x;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    init();
    int64 sum;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%lld",&n);
        sum = 0;
        FOR(i, 0, n) inc[i] = 0;
        FOR(i, 1, n) {
            scanf("%lld",&k[i]);
            inc[i] = inc[i-1] + k[i];
            sum+=k[i];
        }
        sum--;
        ans = f[sum];
        ans = ((ans % INF) * (g[k[1]] % INF)) % INF;
        FOR(i, 2, n) {
            ans = ((ans % INF) * (g[k[i] - 1] % INF)) % INF;
            if (i!=n) {
                eculid(inc[i], INF);
                while (x < 0) x+=INF;
                ans = ((ans % INF) * (x % INF)) % INF;
            }
        }
        if (n == 1) printf("Case %d: 1\n",t);
        else printf("Case %d: %lld\n",t,ans);
    }
    return 0;
}
