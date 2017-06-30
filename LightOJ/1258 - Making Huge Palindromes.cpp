/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1258 - Making Huge Palindromes ->AC
* Algorithm kmp
* Time Limit 0.083s
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
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1000010

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
char P[N], S[N];
int next[N], n, m;
void preKmp() {
    int i, j;
    i = 0; j = next[0] = -1;
    while (i < m) {
        while (j>=0 && S[i] != S[j]) j = next[j];
        ++i; ++j;
        next[i] = j;
    }
}
int kmp() {
    int i, j;
    i = j = 0;
    while (i < n) {
        while (j>=0 && P[i] != S[j]) j = next[j];
        ++i; ++j;
        if (j == m)
            j = next[j];
    }
    return abs(i - j);
}
bool isPalin() {
    int l, r;
    l = 0; r = n - 1;
    while (l<=r) {
        if (P[l] != P[r]) return false;
        l++;
        r--;
    }
    return true;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    scanf(" %d ",&cases);
    while (cases--) {
        gets(P); n = strlen(P); m = n;
        if ( isPalin() ) {
            printf("Case %d: %d\n",++caseno,n);
            continue;
        }
        for (int i=0;i<n;i++) S[i] = P[n-i-1];
        preKmp();
        printf("Case %d: %d\n",++caseno, kmp() + n);
    }
}
