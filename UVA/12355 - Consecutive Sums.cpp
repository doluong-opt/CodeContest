/***********************************************
* Author - LUONG VAN DO                        *
* 12355 - Consecutive Sums ->AC
* Algorithm Adhoc
* Time Limit 3.028s
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
#define For(i, a, b) for (int i=a; i<=b; i++)
#define Ford(i,a,b) for (int i=a;i>=b;i--)
#define Rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 10000005

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

unsigned long long n;
int Free[maxN];
vector <int> V;
int Size;
void sieve(){
    for (int i=1;i<maxN;i++) Free[i] = 1;
    Free[1] = 0;
    for (int i=4;i<maxN;i+=2) Free[i] = 0;
    for (int i=3;i*i<maxN;i+=2)
        if ( Free[i] )
            for (int j=i*i;j<maxN;j+=2*i) Free[j] = 0;
    for (int i=3;i<maxN;i+=2)
        if ( Free[i] ) V.push_back( i );
    Size = V.size();
}
long long solve(){
    long long cnt, ind, ans;
    ans = 1; ind = 0;
    while (n % 2 == 0) n/=2;
    while (ind < Size && (int64)V[ind] * (int64)V[ind] <= n) {
        cnt = 0;
        while ( n % V[ind] == 0 ) {
            cnt++;
            n/=V[ind];
        }
        ans*=(cnt * 2 + 1);
        ind++;
    }
    if (n > 1) ans*=3;
    return ans * 2;
}
void Read_Input(){
    sieve();
    while ( scanf("%lld",&n) && n)
        printf("%lld\n",solve());
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}
