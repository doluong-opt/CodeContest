/***********************************************
* Author - LUONG VAN DO                        *
* 1197 - Help Hanzo ->AC
* Algorithm sieve
* Time Limit 0.178s
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
#define maxN 1000010
#define EM 0.5772156649015328606065120900824
using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int prime[maxN + 5], sz;
vector <int64> p;
void sieve(){
    FOR(i, 1, maxN - 1) prime[i] = 1;
    prime[0] = prime[1] = 0;
    for (int i=3;i*i<=maxN;i+=2)
        if (prime[i])
            for (int j=i*i;j<=maxN;j+=i + i) prime[j] = 0;
    p.pb( 2 );
    for (int i=3;i<maxN;i+=2)
        if (prime[i]) p.pb( i );
    sz = p.size();
}
int64 getNext(int64 N, int64 P){
    int64 S = (int64)(ceil((double)N / (double)P));
    S*=P;
    if (S == P) S+=P;
    return S;
}
void init(int64 a, int64 b) {
    FOR(i, 0, maxN - 1) prime[i] = 1;
    for (int64 i=0;i<sz && (int64)p[i] * (int64)p[i] <= b ;i++) {
        for (int64 j=getNext(a, p[i]);j<=b;j+=p[i])
            prime[j - a] = 0;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    int64 a, b, Ans;
    sieve();
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%lld %lld",&a,&b);
        Ans = 0; init(a, b);
        FOR(x, a, b)
            if (x != 1 && prime[x - a]) Ans++;
        printf("Case %d: %lld\n",t,Ans);
    }
    return 0;
}
