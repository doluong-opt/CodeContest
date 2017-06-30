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
char s1[N], s2[N];
uint64 hashA[N], hashB[N], hashPow[N], f1, f2;
int nA, nB, q, lo, hi;
int u1, v1, u2, v2, l1, l2;

uint64 getHashA(int l, int r) {
    return (hashA[r + 1] - hashA[l]) * hashPow[nA - r];
}

uint64 getHashB(int l, int r) {
    return (hashB[r + 1] - hashB[l]) * hashPow[nB - r];
}

int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf(" %d %d ", &nA, &nB);
	gets(s1);
	hashA[0] = 0; hashPow[0] = 1;
	for (int i = 1;i <= nA;i++) {
	    hashPow[i] = hashPow[i - 1] * P;
	    hashA[i] = hashA[i - 1] + s1[i - 1] * hashPow[i - 1];
	}
	gets(s2);
	hashB[0] = 0; hashPow[0] = 1;
	for (int i = 1;i <= nB;i++) {
	    hashPow[i] = hashPow[i - 1] * P;
	    hashB[i] = hashB[i - 1] + s2[i - 1] * hashPow[i - 1];
	}
	f1 = f2 = 1LL;
    if (nA < nB) f1 = hashPow[nB - nA];
    if (nA > nB) f2 = hashPow[nA - nB];
	scanf(" %d ", &q);
	for (int i = 0;i < q;i++) {
	    scanf(" %d %d %d %d ", &u1, &v1, &u2, &v2);
	    u1--; v1--; u2--; v2--;
	    l1 = v1 - u1 + 1; l2 = v2 - u2 + 1;
	    lo = 1; hi = min(l1, l2);
	    int p1 = u1 + hi - 1, p2 = u2 + hi - 1;
	    while (lo <= hi) {
	        int mid = (lo + hi) >> 1;
	        if ( getHashA(u1, u1 + mid - 1) * f1 == getHashB(u2, u2 + mid - 1) * f2 ) lo = mid + 1;
	        else {
	            p1 = u1 + mid - 1;
	            p2 = u2 + mid - 1;
	            hi = mid - 1;
	        }
	    }
	    if (s1[p1] == s2[p2] && l1 < l2) printf("<");
	    else 
	    if (s1[p1] == s2[p2] && l1 > l2) printf(">");
	    else 
	    if (s1[p1] == s2[p2] && l1 == l2) printf("=");
	    else 
	    if (s1[p1] > s2[p2]) printf(">");
	    else 
	    if (s1[p1] < s2[p2]) printf("<");
	}
	return 0;
}
