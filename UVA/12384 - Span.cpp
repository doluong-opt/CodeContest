/***********************************************
* Author - LUONG VAN DO                        *
* 12384 - Span ->AC
* Algorithm Adhoc
* Time Limit 0.076s
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
#define maxN 1300001

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int Free[maxN];
vector <uint64> primes;
int Size,n,m;
int a[maxN], Left[maxN];
void sieve() {
    for (int i=1;i<maxN;i++) Free[i] = 1;
    Free[1] = 0;
    for (int i=4;i<maxN;i+=2) Free[i] = 0;
    for (int i=3;i*i<maxN;i+=2)
        if (Free[i])
            for (int j=i*i;j<maxN;j+=2*i) Free[j] = 0;
    primes.pb(2);
    for (int i=3;i<maxN;i+=2)
        if (Free[i]) primes.pb(i);
    Size = primes.size();
}
void Read(){
    int test,ans;
    sieve();
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d %d",&n,&m);
        for (int i=1;i<=n;i++) a[i] = primes[i-1] % m;
        
        memset(Left, 0, sizeof(Left));
        Left[1] = 0; a[0] = INF;
        for (int i=2;i<=n;i++) {
            Left[i] = i - 1;
            while ( a[i] >= a[ Left[i] ] ) Left[i] = Left[ Left[i] ];
        }
        ans = 0;
        for (int i=1;i<=n;i++)
            ans = (ans + i - Left[i]) % m;
        printf("%d\n",ans);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
