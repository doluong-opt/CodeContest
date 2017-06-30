/***********************************************
* Author - LUONG VAN DO                        *
* 1370 - Bi-shoe and Phi-shoe ->AC
* Algorithm basic math
* Time Limit 0.121s
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
#define maxN 1100005
#define M 1100000
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
bool Free[maxN];
int ans[maxN];
int64 rs[maxN];
int64 res;
int n;
void sieve() {
    for (int i=1;i<maxN;i++) Free[i] = true;
    Free[1] = false;
    for (int i=4;i<maxN;i+=2) Free[i] = false;
    for (int i=3;i*i<maxN;i+=2)
        if (Free[i])
            for (int j=i*i;j<maxN;j+=2*i) Free[j] = false;
}
void init() {
    int k;
    ans[1] = 0;
    for (int i=2;i<=1100000;i++) {
        ans[i] = i;
        rs[i] = 0;
    }
    
    for (int i=2;i<=1100000;i++) {
        if ( !Free[i] ) continue;
        k = 1;
        while ( (int64)i * (int64)k <= 1100000 ) {
            ans[i * k]-=( ans[i * k] / i );
            ++k;
        }
    }
    for (int i=1;i<=1000000;i++) {
        for (int j=i+1;j<maxN;j++)
            if ( ans[j] >= i) {
                rs[i] = j;
                break;
            }
    }
}
void Read() {
    sieve();
    init();
    int test,x;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d",&n);
        res = 0;
        for (int i=1;i<=n;i++) {
            scanf("%d",&x);
            res+=rs[x];
        }
        printf("Case %d: ",t);
        printf("%lld Xukha\n",res);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
