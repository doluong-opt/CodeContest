/***********************************************
* Author - LUONG VAN DO                        *
* 1340 - Story of Tomisu Ghost ->AC
* Algorithm math
* Time Limit 0.452s
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
#define INF 10000019
#define maxN 100005

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node{
    int64 p, cnt;
    node(){}
    node(int64 pp, int64 cc){
        p = pp; cnt = cc;
    }
};
vector <int> prime;
int color[maxN], nm, Size;
node A[maxN];
void sieve() {
    FOR(i, 1, maxN - 1) color[i] = 1;
    color[1] = 0;
    for (int i=4;i<maxN;i+=2) color[i] = 0;
    for (int i=3;i*i<maxN;i+=2)
        if (color[i])
            for (int j=i*i;j<maxN;j+=2*i) color[j] = 0;
    prime.pb(2);
    for (int i=3;i<maxN;i+=2)
        if (color[i]) prime.pb(i);
    Size = prime.size();
}
int64 square(int64 x){
    return ((x % INF) * (x % INF)) % INF;
}
int64 bigmod(int64 x, int64 y) {
    if (y == 0) return 1;
    if (y == 1) return x;
    if (y % 2 == 0) return square ( bigmod(x, y/2) % INF) % INF;
    else return ((x % INF) * bigmod(x, y-1) % INF) % INF;
}
void Call(int64 n) {
    int64 nn, x, inc;
    nm = 0;
    REP(i, Size) {
        nn = n;
        x = prime[i];
        if (x > n) break;
        inc = 0;
        for (int i=x;i<=n;i*=x)
            inc+=(nn / i);
        A[nm++] = node(x, inc);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, found;
    int64 n, t, ans;
    sieve();
    scanf("%d",&test);
    FOR(tt, 1, test) {
        scanf("%lld %lld",&n,&t);
        Call( n );
        ans = 1; found = 0;
        REP(i, nm)
            if ( A[i].cnt >= t ) {
                found = 1;
                ans*=bigmod( A[i].p, A[i].cnt / t ) % INF;
                ans%=INF;
            }
        if (found) printf("Case %d: %lld\n",tt,ans);
        else printf("Case %d: -1\n",tt);
    }
    return 0;
}
