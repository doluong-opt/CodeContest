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
#define N 100000
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
int a, b, sz, ans;
int mark[N];
vector <int> prime;
bool isPrime(int x) {
    for (int i = 2;i * i <= x;i++)
        if (x % i == 0) return false;
    return true;
}
bool check(int x, int y) {
    int nx[5], ny[5], m = 0, cnt = 0;
    while (x) {
        nx[m] = x % 10;
        ny[m] = y % 10;
        x /= 10; y /= 10;
        m++;
    }
    rep(i, m) if (nx[i] != ny[i]) cnt++;
    return (cnt == 1);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
	fr(i, 1000, 9999) if (isPrime(i)) prime.pb(i);
	sz = prime.size();
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%d %d", &a, &b);
	    fill(mark, 0);
	    queue <ii> q; q.push(ii(a, 0));
	    while (!q.empty()) {
	        ii st = q.front(); q.pop();
	        if (st.ff == b) {
	            ans = st.ss;
	            break;
	        }
	        rep(i, sz) {
	            if ( mark[prime[i]] ) continue;
	            if ( check(st.ff, prime[i]) ) {
	                mark[prime[i]] = 1;
	                q.push(ii(prime[i], st.ss + 1));
	            }
	        }
	    }
	    printf("%d\n", ans);
	}
	return 0;
}
