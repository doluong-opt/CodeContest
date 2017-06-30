// =============================================================================
// Author LUONG VAN DO
// Problem C. Beaver
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
#define N 100010
#define maxN 100
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
uint64 hash[N], hashPow[N], a[maxN], hashCur;
char s[N], ch[maxN][maxN];
int n, m;
uint64 getHash(int l, int r) {
    return (hash[r + 1] - hash[l]) * hashPow[n - r];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int maxLen, posStart, x;
    gets(s); n = strlen(s);
    scanf(" %d ", &m);
    for (int i = 0;i < m;i++) gets(ch[i]);
    hash[0] = 0; hashPow[0] = 1;
    for (int i = 1;i <= n;i++) {
        hashPow[i] = hashPow[i - 1] * P;
        hash[i] = hash[i - 1] + s[i - 1] * hashPow[i - 1];
    }
    for (int i = 0;i < m;i++) {
        a[i] = 0;
        for (int j = 0;j < strlen(ch[i]);j++)
            a[i] += ch[i][j] * hashPow[j];
        a[i] *= hashPow[n - strlen(ch[i]) + 1];
    }
    maxLen = 0; posStart = 0; x = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++)
            if (i + 1 >= strlen(ch[j])) {
                hashCur = getHash(i - strlen(ch[j]) + 1, i);
                if (hashCur == a[j]) x = max(x, i - strlen(ch[j]) + 2);
            }
        if (i - x + 1 > maxLen) {
            maxLen = i - x + 1;
            posStart = x;
        }
    }
    printf("%d %d\n", maxLen, posStart);
}
