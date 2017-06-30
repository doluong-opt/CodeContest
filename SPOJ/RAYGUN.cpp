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
int p[N];
ii c[N];
vector <int> prime;
int cnt;
int64 ans, n, m;
void sieve() {
    for (int i = 1;i < N;i++) p[i] = 1; p[1] = 0;
    for (int i = 3;i * i < N;i += 2)
        if (p[i])
            for (int j = i * i;j < N;j += 2 * i) p[j] = 0;
    prime.pb(2);
    for (int i = 3;i < N;i += 2)
        if (p[i]) prime.pb(i);
}
void dfs(int mul,int pos,int cur) {  
    c[cnt].ff=cur;
    c[cnt++].ss=mul;
    int up=1000000/mul;  
    for(int i=pos;prime[i]<=up;i++) dfs(mul * prime[i],i+1,cur + 1);
}
bool cmp(ii a, ii b) {
    return a.ss < b.ss;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	sieve(); cnt = 0; dfs(1, 0, 0); sort(c, c + cnt, cmp);
	int cases, caseno = 0;
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%lld %lld", &m, &n);
	    ans = 0;
	    for(int i=0;i<cnt;i++) {
            if(c[i].ss > min(n, m)) break;
            else if(c[i].ff & 1) ans -= (n/c[i].ss)*(m/c[i].ss);
            else ans += (n/c[i].ss)*(m/c[i].ss);
	    }
        if(n == 0 && m == 0) ans = 0;
        else if(n == 0||m == 0) ans = 1;  
        else ans += 2;
        printf("Case %d: %lld\n",++caseno, ans);
	}
	return 0;
}
