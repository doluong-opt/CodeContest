/***********************************************
* Author - LUONG VAN DO                        *
* Problem 
* Algorithm
* Time Limit
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1000111
#define mod 1000000007
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct node{
    int noNum, id;
    double sumF;
    int64 ansL;
    node(){}
    node(int _noNum, int _id, double _sumF, int64 _ansL) {
        noNum = _noNum; id = _id; sumF = _sumF; ansL = _ansL;
    }
}a[155];

int prime[N], n, m, pre, cur;
int64 p, resMin, ansL[2][10];
vector <int64> factorPrime, factorofP;
double multiF, sumF[2][10];
int64 powInc[2][10][55];

void sieve() {
    for (int i = 1;i < N;i++) prime[i] = 1; prime[1] = 0;
    for (int i = 4;i < N;i += 2) prime[i] = 0;
    for (int i = 3;i * i < N;i += 2)
        if ( prime[i] )
            for (int j = i * i;j < N; j += 2 * i) prime[j] = 0;
    factorPrime.pb(2);
    for (int i = 3;i < N;i += 2)
        if ( prime[i] ) factorPrime.pb(i);
    n = factorPrime.size();
}
bool cmp(node x, node y) {
    return x.sumF < y.sumF;
}
int64 power(int64 x, int64 y) {
    int64 res = 1LL;
    while ( y ) {
        if (y & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}
void init() {
    factorofP.clear();
    for (int i = 0; factorPrime[i] * factorPrime[i] <= p;i++) {
        while ( p % factorPrime[i] == 0 ) {
            p /= factorPrime[i];
            factorofP.pb(factorPrime[i]);
        }
    }
    if (p > 1) factorofP.pb(p);
    m = factorofP.size();
    reverse(factorofP.begin(), factorofP.end());
}
void dfs(int at, int noNum) {
    if (at == m) {
        for (int i = 1;i <= noNum;i++) if ( sumF[pre][i] < multiF ) {
            multiF = sumF[pre][i];
            resMin = ansL[pre][i];
        }
        return;
    }
    int64 p = factorofP[at], sz = 0, tempnoNum = 0, xx, yy;
    for (int i = 1;i <= noNum;i++) for (int j = 1; j <= m;j++) {
        a[sz].noNum = i; a[sz].id = j;
        a[sz].sumF = sumF[pre][i] + powInc[pre][i][j] * (p - 1) * log(factorPrime[j] * 1.0);
        a[sz].ansL = ansL[pre][i] * power(factorPrime[j], powInc[pre][i][j] * (p - 1));
        a[sz].ansL %= mod; sz++;
    }
    sort(a, a + sz, cmp);
    for (int i = 0;i < sz && tempnoNum < 9;i++) {
        tempnoNum++;
        sumF[cur][tempnoNum] = a[i].sumF;
        ansL[cur][tempnoNum] = a[i].ansL;
        xx = a[i].noNum; yy = a[i].id;
        for (int j = 1;j <= m;j++) powInc[cur][tempnoNum][j] = powInc[pre][xx][j];
        powInc[cur][tempnoNum][yy] *= p;
    }
    pre ^= 1; cur ^= 1;
    dfs(at + 1, tempnoNum);
}
int64 solve() {
    init();
    multiF = 1e50;
    for (int i = 1;i <= m;i++) powInc[0][1][i] = 1LL;
    sumF[0][1] = 0.0; ansL[0][1] = 1LL;
    pre = 0; cur = 1; dfs(0, 1);
    return resMin;
}
inline void nextint(int64 &res) {
    char c; res = 0LL;
    do { c = getchar(); } while (c  < '0' || c > '9');
    do { res = res * 10 + c - '0'; c = getchar(); } while (c >= '0' && c <= '9');
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
	sieve();
	scanf("%d", &cases);
	while (cases--) {
	    nextint(p); p++;
	    if (p == 1) printf("Case %d: 1\n", ++caseno);
	    else printf("Case %d: %lld\n", ++caseno, solve());
	}
	return 0;
}
