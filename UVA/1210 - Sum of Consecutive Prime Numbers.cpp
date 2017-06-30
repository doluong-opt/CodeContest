/***********************************************
* Author - LUONG VAN DO                        *
* 1210 - Sum of Consecutive Prime Numbers ->AC
* Algorithm sieve
* Time Limit 0.116s
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
#define maxN 10005
using namespace std;
vector <int> prime;
int color[maxN];
int l;
int64 s[maxN],n;
void Sieve(){
    For(i,1,10000) color[i] = true; color[1] = false;
    for (int i=4;i<maxN;i+=2) color[i] = false;
    for (int i=3;i*i<maxN;i+=2)
        if (color[i])
            for (int j=i*i;j<maxN;j+=2*i) color[j] = false;
    prime.pb(2);
    for (int i=3;i<maxN;i+=2)
        if (color[i]) prime.pb( i );
}
int Write_Output(){
    int rs = 0;
    for (int i=-1;i<l;i++)
        for (int j=0;j<l;j++)
                if (s[j]-s[i-1]==n) rs++;
            else
                if (s[j]-s[i-1] > n) break;
    return rs;
}
void Read_Input(){
    Sieve();
    l = prime.size();
    s[0] = prime[0];
    for (int i=1;i<l;i++)
        s[i] = s[i-1] + prime[i];
    while ( scanf("%lld",&n) && n) {
        printf("%d\n",Write_Output());
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
