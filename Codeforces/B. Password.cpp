// =============================================================================
// Author LUONG VAN DO
// Problem B. Password
// Algorithm
// Time Limit
// =============================================================================
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

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 111222333
#define N 1000100
#define P 999983
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vi pos;
char s[N];
uint64 hash[N], hashPow[N], hashCur;
int n;
uint64 getHash(int l, int r) {
    return (hash[r + 1] - hash[l]) * hashPow[n - r];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int flag, lo, hi, ans, len;
    gets(s); n = strlen(s);
    hashPow[0] = 1; hash[0] = 0;
    for (int i = 1;i <= n;i++) {
        hashPow[i] = hashPow[i - 1] * P;
        hash[i] = hash[i - 1] + s[i - 1] * hashPow[i - 1];
    }
    for (int i = 0;i < n ;i++)
        if ( getHash(0, i) == getHash(n - i - 1, n - 1) ) pos.pb(i);
    lo = 0; hi = pos.size() - 1; ans = -1;
    while ( lo <= hi ) {
        int mid = (lo + hi) >> 1;
        len = pos[mid] + 1;
        hashCur = getHash(0, pos[mid]);
        flag = 0;
        if (hashCur == getHash(n - pos[mid] - 1, n - 1)) {
            for (int j = 1; j <= n - len - 1 && !flag;j++)
                if (getHash(j, j + len - 1) == hashCur) flag = 1;
        }
        if (!flag) hi = mid - 1;
        else {
            ans = pos[mid];
            lo = mid + 1;
        }
    }
    if (ans == -1) puts("Just a legend");
    else {
        s[ans + 1] = '\0';
        puts(s);
    }
}
