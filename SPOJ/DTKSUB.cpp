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
#define N 100111
#define P 999983
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

uint64 hash[N], hashPow[N], st[N];
char s[N];
int n, k, l, r, lenMax, sz, cnt, tempK;
uint64 getHash(int l, int r) {
    return (hash[r + 1] - hash[l]) * hashPow[n - r];
}
bool check(int m) {
    sz = cnt = tempK = 0;
    for (int i = 0;i < n - m + 1;i++)
        st[sz++] = getHash(i, i + m - 1);
    sort(st, st + sz); cnt = 1;
    rep(i, sz) {
        if (i && st[i] == st[i - 1]) cnt++;
        else {            
            tempK = max(tempK, cnt);
            cnt = 1;
        }
    }
    tempK = max(tempK, cnt);
    return tempK >= k;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf(" %d %d ", &n, &k);
	gets(s);
	hash[0] = 0; hashPow[0] = 1LL;
	fr(i, 1, n) {
	    hashPow[i] = hashPow[i - 1] * P;
	    hash[i] = hash[i - 1] + s[i - 1] * hashPow[i - 1];
	}
	l = 0; r = n; lenMax = 0;
	while (l <= r) {
	    int mid = (l + r) >> 1;
	    if ( check(mid) ) {
	        lenMax = mid;
	        l = mid + 1;
	    }
	    else r = mid - 1;
	}
	printf("%d\n", lenMax);
	return 0;
}
