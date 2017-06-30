/***********************************************
* Author - LUONG VAN DO                        *
* Problem 12598 - Starting School
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
#define INF 2000000000
#define N 100111
#define M 3000000
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

int64 n, k, q, ll, id, m, pos;
int64 a[N], b[N], x;
int64 cnt[N];
char s[M];

int64 findX(int64 key, int64 l, int64 r) {
    while (l <= r) {
        int64 mid = (l + r) >> 1;
        if ( cnt[mid] >= key ) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}

int64 nextInt() {
    int64 v = 0LL, sign = 1;
    while (id < m && s[id] == ' ') ++id;
    while (id < m && s[id] != ' ') {
        if (s[id] == '-') {
            sign = -1;
            ++id;
        }
        else v = v * 10LL + s[id++] - '0';
    }
    while (id < m && s[id] == ' ') ++id;
    return v * sign;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;	
	gets(s); id = 0; m = strlen(s);
	cases = nextInt();	
	while (cases--) {
	    //gets(s);
	    gets(s); id = 0; m = strlen(s);
	    n = nextInt(); k = nextInt(); q = nextInt();
	    //scanf("%d %d %d", &n, &k, &q);
        gets(s); id = 0; m = strlen(s);
	    fr(i, 1, k) {
	        a[i] = nextInt();
	        //scanf("%d", &a[i]);
	        b[i] = a[i];
	    }
	    sort(a + 1, a + k + 1);
	    a[0] = cnt[0] = 0;
	    a[k + 1] = INF;
	    fr(i, 1, k) {
	        cnt[i] = a[i] - a[i - 1] - 1;
	        cnt[i] += cnt[i - 1];
	    }
	    gets(s); id = 0; m = strlen(s);
	    
	    printf("Case %d:\n", ++caseno);	    
	    fr(i, 1, q) {
	        x = nextInt();
	        if (x <= k) printf("%lld\n", b[x]);
	        else {
	            pos = findX(x - k, 1, k);
	            pos--;
	            x = x - k;
	            printf("%lld\n",a[pos] + x - cnt[pos]);
	        }
	    }
	}
	return 0;
}
