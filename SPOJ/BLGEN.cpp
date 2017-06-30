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
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i = b;i >= a;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define pb push_back
#define ff first
#define ss second
#define fill(arr, val) memset(arr, val, sizeof(arr))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint32 unsigned int
#define INF 1000000000
#define N 100100
#define LMT 2200000
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
uint64 p[LMT + 1];
vector <uint64> primes;
uint64 a[N], b[N], num;
int na, nb, id, n, sz;
char s[N];
int dp[1001][1001];
void sieve() {
    for (int i = 1;i <= LMT;i++) p[i] = 1;
    p[1] = 0;
    for (int i = 4;i <= LMT;i += 2) p[i] = 0;
    for (int64 i = 3;i * i <= LMT;i += 2)
        if (p[i])
            for (int64 j = i * i;j <= LMT;j += i + i) p[j] = 0;
    primes.pb(8);
    for (int i = 3;i <= LMT;i += 2)
        if (p[i]) primes.pb((uint64)i * (uint64)i * (uint64)i);
    n = primes.size();
}
bool isOk(uint64 x) {
    if (x == 0) return false;
    uint64 y = (uint64)sqrt(x);
    if (y * y == x) return true;
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if ( primes[mid] == x ) return true;
        if ( primes[mid] > x ) hi = mid - 1;
        else lo = mid + 1;
    }
    return false;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	sieve();
	gets(s); sz = strlen(s); id = na = nb = 0;
	while (id < sz) {
        while (id < sz && s[id] == ' ') id++;
        num = 0LL;
        while (id < sz && s[id] != ' ') {
            num = num * 10 + s[id] - '0';
            id++;
        }
        if ( isOk(num) ) a[++na] = num;
	}
	gets(s); sz = strlen(s); id = 0;
	while (id < sz) {
        while (id < sz && s[id] == ' ') id++;
        num = 0LL;
        while (id < sz && s[id] != ' ') {
            num = num * 10 + s[id] - '0';
            id++;
        }
        if ( isOk(num) ) b[++nb] = num;
	}
	/*fr(i, 1, na) cout<<a[i]<<" ";
	cout<<endl;
	fr(i, 1, nb) cout<<b[i]<<" ";
	cout<<endl;*/
	fr(i, 1, na) dp[i][0] = 0;
	fr(i, 1, nb) dp[0][i] = 0;
	fr(i, 1, na) fr(j, 1, nb)
        if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
    else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    printf("%d\n", dp[na][nb]);
	return 0;
}
