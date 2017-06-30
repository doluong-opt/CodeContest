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
#define INF 1000000000
#define N 10000100

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int64> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, sz;
vector <ii> res;
int p[N], lo, hi;
void init() {
    for (int i = 1;i < N;i++) p[i] = 1;
    p[1] = 0;
    for (int i = 4;i < N;i += 2) p[i] = 0;
    for (int i = 3;i * i < N;i += 2)
        if (p[i])
            for (int j = i * i;j < N;j += 2 * i) p[j] = 0;
    
    for (int i = 3;i <= 10000000;i += 2)
        if ( p[i] ) {
            int64 k = 2, total;
            int num;
            while ( (int64)i * k <= 10000000 ) {
                num = i * k; total = (2 * k - 1) * (i + 1) - 2 * k * i;
                res.pb(ii(num, total) );
                k *= 2;
            }
        }
    sort(res.begin(), res.end());
    sz = res.size();
    for (int i = 1;i < sz;i++) res[i].ss += res[i - 1].ss;
    //for (int i = 0;i < 100;i++) cout << res[i].ff<<" "<<res[i].ss<<endl;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	init();	
	while ( scanf("%d", &n) && n) {
	    lo = 0; hi = sz - 1;
	    while (lo <= hi) {
	        int mid = (lo + hi) >> 1;
	        if ( res[mid].ff <= n ) lo = mid + 1;
	        else hi = mid - 1;
	    }
	    if (hi == -1) printf("%d 0\n", n);
	    else printf("%d %lld\n", n, res[hi].ss);
	}
	return 0;
}
