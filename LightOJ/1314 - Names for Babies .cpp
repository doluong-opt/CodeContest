/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1314 - Names for Babies
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
char s[N];
int n, l, r;
int SA[N], RA[N];
int tempSA[N], tempRA[N];
int c[N];
int phi[N], LCP[N], PLCP[N];
int64 ans;
void countingSort(int k) {
    int i, sum, maxi = max(300, n);
    for (int i = 0;i < maxi;i++) c[i] = 0;
    
    for (i = 0;i < n;i++)
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0;i < maxi;i++) {
        int t = c[i]; c[i] = sum; sum += t;
    }
    
    //for (i = 0;i < maxi;i++)
        //if (c[i] > 0 ) printf("%d %d\n", i, c[i]);
        
    
    for (i = 0;i < n;i++) {
        //if (SA[i] + k < n) printf("%d %d %d %d\n", i, RA[SA[i] + k], c[RA[SA[i] + k]], SA[i]);
        //else printf("%d %d\n", i, 0);
        tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
    }
    for (i = 0;i < n;i++)
        SA[i] = tempSA[i];
}
void constructSA() {
    int i, k, r;
    for (i = 0;i < n;i++) RA[i] = s[i] - '.';
    for (i = 0;i < n;i++) SA[i] = i;
    for (k = 1;k < n; k <<= 1) {
        countingSort(k);
        countingSort(0);
        tempRA[SA[0]] = r = 0;
        for (i = 1;i < n;i++)
            tempRA[SA[i]] = 
                (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
        for (i = 0;i < n;i++)
            RA[i] = tempRA[i];
    }
}
void computeLCP() {
    int i, L;
    phi[SA[0]] = -1;
    for (i = 1;i < n;i++)
        phi[SA[i]] = SA[i - 1];
    for (i = L = 0;i < n;i++) {
        if (phi[i] == -1) { PLCP[i] = 0; continue; }
        while (s[i + L] == s[phi[i] + L]) L++;
        PLCP[i] = L;
        L = max(L - 1, 0);
    }
    for (i = 1;i < n;i++)
        LCP[i] = PLCP[SA[i]];
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
	scanf(" %d ", &cases);
	while (cases--) {
        n = (int)strlen(gets(s));
        scanf(" %d %d ", &l, &r);        
        constructSA();
        computeLCP();
        ans = 0LL;
        for (int i = 0;i < n;i++) {
            int ll = max(l, LCP[i] + 1);
            int rr = min(r, n - SA[i]);
            if (ll <= rr) ans += rr - ll + 1;
        }
        printf("Case %d: %lld\n", ++caseno, ans);
        for (int i = 0;i < n;i++) printf("%2d\t%s\n", SA[i], s + SA[i]);
        //for (int i = 0;i < n;i++) printf("%d %d\n", i, LCP[i]);
	}
	return 0;
}
