/***********************************************
* Author LUONG VAN DO                        *
* Problem 1060 - nth Permutation 
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
#define N 22

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
int64 p[N];
int f[30];
void init() {
    p[0] = 1;
    fr(i, 1, 20)
        p[i] = p[i - 1] * i;
}
int64 g(int x) {
    int64 m = p[x];
    rep(i, 26) m/=p[f[i]];
    return m;
}
void dfs(int n, int64 total) {
    if (!n) return;
    int64 cur;
    rep(i, 26)
        if (f[i]) {
            f[i]--;
            cur = g(n - 1);
            if (cur < total) total-=cur;
            else {
                printf("%c",i + 97);
                dfs(n - 1, total);
                return;
            }
            f[i]++;
        }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, n;
    int64 k, com;
    init();
    scanf(" %d ", &cases);
    while (cases--) {
        scanf("%s %lld", s, &k);
        n = strlen(s); fill(f, 0);
        rep(i, n) f[s[i] - 'a']++;
        com = p[n];
        rep(i, 26) com/=p[f[i]];
        printf("Case %d: ", ++caseno);
        if (k > com) puts("Impossible");
        else {
            dfs(n, k);
            puts("");
        }
    }
}
