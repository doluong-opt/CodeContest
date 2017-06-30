/***********************************************
* Author - LUONG VAN DO                        *
* 11226 - Reaching the fix-point. ->AC
* Algorithm Adhoc
* Time Limit 0.428s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define For(i, a, b) for (int i=a; i<=b; i++)
#define Ford(i,a,b) for (int i=a;i>=b;i--)
#define Rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 1000005
using namespace std;
int Free[maxN];
vector <int64> prime;
int lsopf[maxN];
int n,m;
void sieve(){
    for (int i=1;i<maxN;i++) {
        Free[i] = 1;
        lsopf[i] = 0;
    }
    for (int i=4;i<maxN;i+=2) Free[i] = 0;
    for (int i=3;i*i<maxN;i+=2)
        if (Free[i])
            for (int j=i*i;j<maxN;j+=2*i) Free[j] = 0;
    prime.pb(2); lsopf[2] = 1;
    for (int i=3;i<maxN;i+=2)
        if (Free[i]) {
            prime.pb(i);
            lsopf[i] = 1;
        }
}
int ptich(int nn){
    int id, sum;
    sum = id = 0;
    while (prime[id]*prime[id]<=nn) {
        if (nn % prime[id]==0) {
            while (nn % prime[id]==0) {
                sum+=prime[id];
                nn/=prime[id];
            }
        }
        id++;
    }
    if ( nn > 1 ) sum+=nn;
    return sum;
}
void Fill(int nn){
    int tmp;
    tmp = ptich( nn );
    if (tmp == nn && !lsopf[tmp]) {
        lsopf[tmp] = 1;
        return;
    }
    else
    if ( lsopf[ tmp ] ) {
        lsopf[nn] = lsopf[tmp] + 1;
        return;
    }
    else Fill( tmp );
    lsopf[nn] = lsopf[tmp] + 1;
}
void init(){
    for (int i=2;i<=500000;i++)
        if (!lsopf[i]) Fill( i );
}
void Read_Input() {
    int t,ans,Case;
    sieve();
    init();
    Case = 0;
    scanf("%d",&t);
    while ( t-- ) {
        scanf("%d %d",&n,&m);
        if (n>m) swap(n,m);
        ans = 0;
        For(i,n,m)
            ans = max(lsopf[i],ans);
        printf("Case #%d:\n",++Case);
        printf("%d\n",ans);
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    //Write_Output();
}
