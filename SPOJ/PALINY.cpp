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
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1010

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

#define N 50010
#define P 999983

vector <int> odd, even;
uint64 hl[N], hr[N], hp[N];
char s[N];
int n, lenMax, lo, hi;

uint64 getLeft(int l, int r) {
    return (hl[r + 1] - hl[l]) * hp[n - r];
}
uint64 getRight(int l, int r) {
    return (hr[r + 1] - hr[l]) * hp[n - r];
}
bool check(int k) {
    int l1, r1, l2, r2;
    for (int i = 0;i < n + k - 1;i++) {
       l1 = i;
       r1 = i + k - 1;
       l2 = n - r1 - 1;
       r2 = n - l1 - 1;
       if (l1 <= r1 && l2 <= r2 && l1 >= 0 && l2 >= 0 && getLeft(l1, r1) == getRight(l2, r2)) return true;
    }
    return false;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
    scanf(" %d ", &n);
    gets(s);
    hp[0] = 1LL; hl[0] = hr[0] = 0;
    for (int i = 1;i <= n;i++) {    
        hp[i] = hp[i - 1] * P;
        hl[i] = hl[i - 1] + s[i - 1] * hp[i - 1];
    }
    hp[0] = 1LL;
    for (int i = n;i >= 1;i--) {
        hp[n - i + 1] = hp[n - i] * P;
        hr[n - i + 1] = hr[n - i] + s[i - 1] * hp[n - i];
    }
    for (int i = 1;i <= n;i++)
        if (i & 1) odd.pb(i);
        else even.pb(i);
    
    lo = 0; hi = odd.size() - 1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if ( check(odd[mid]) ) {
            lenMax = max(lenMax, odd[mid]);
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    lo = 0; hi = even.size() - 1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if ( check(even[mid]) ) {
            lenMax = max(lenMax, even[mid]);
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    printf("%d\n", lenMax);
}
