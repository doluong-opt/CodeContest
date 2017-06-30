/***********************************************
* Author - LUONG VAN DO                        *
* 1259 - Goldbach`s Conjecture ->AC
* Algorithm Number Theory
* Time Limit 0.894s
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
#define MAX 10000001
#define LMT 3170
#define chkC(n)(flag[n>>6]&(1<<((n>>1)&31)))
#define setC(n)(flag[n>>6]|=(1<<((n>>1)&31)))
using namespace std;
int flag[MAX/64];
vector <int> prime;
int n, m;
void sieve() {
    int i,j,k;
    flag[0]|=0;
    for (i=3;i<LMT;i+=2)
        if ( !chkC(i) )
            for (j=i*i, k=i<<1;j<MAX;j+=k) setC(j);
    prime.pb(3);
    for (int i=5;i<MAX;i+=2)
        if (!chkC(i)) prime.pb(i);
    m = prime.size();
}
void Read(){
    sieve();
    int test, ans;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d",&n);
        ans = 0;
        if ( n <= 3 ) {
            printf("Case %d: 0\n",t);
            continue;
        }
        else
        if ( n == 4) {
            printf("Case %d: 1\n",t);
            continue;
        }
        else {
            int x = 0, y = m - 1, nn = n;
            while ( x <= y && prime[x] <= n && nn>=2*prime[x]) {
                if  ( (nn - prime[x]) % 2 == 1 && !chkC(nn - prime[x]) ) {
                    ans++;
                    n = nn - prime[x];
                    ++x;
                }
                else ++x;
            }
        }
        printf("Case %d: %d\n",t,ans);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
