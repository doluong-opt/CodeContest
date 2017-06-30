/***********************************************
* Author - LUONG VAN DO                        *
* 10791 - Minimum Sum LCM ->AC
* Algorithm Adhoc
* Time Limit 0.008s
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
#define maxN 50001
using namespace std;
int Free[maxN];
vector <int64> p;
int64 n;
void sieve(){
    For(i,1,50000) Free[i] = 1;
    Free[1] = 0;
    for (int i=4;i<maxN;i+=2) Free[i] = 0;
    for (int i=3;i*i<maxN;i+=2)
        if (Free[i])
            for (int j=i*i;j<maxN;j+=2*i) Free[j] = 0;
        p.pb( 2 );
    for (int i=3;i<maxN;i+=2)
        if (Free[i]) p.pb( i );
}
void Solve(int Case){
    int64 sum = 0, nn;
    int64 tmp = 1;
    printf("Case %d: ",Case);
    if (n==1) {
        printf("2\n");
        return;
    }
    int id = 0;
    nn = n;
    while (p[id]*p[id]<=nn){
        tmp = 1;
        if (nn % p[id]==0)
        while ( nn % p[id]==0 ) {
            tmp*=p[id];
            nn/=p[id];
        }
        if (tmp > 1) sum+=tmp;
        id++;
    }
    if (nn > 1) sum+=nn;
    if ( sum == n ) sum++;
    printf("%lld\n",sum);
}
void Read_Input(){
    sieve();
    int Case = 0;
    while (scanf("%lld",&n) && n) {
        Solve(++Case);
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
