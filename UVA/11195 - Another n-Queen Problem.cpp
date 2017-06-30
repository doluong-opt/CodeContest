/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11195 - Another n Queen Problem ->AC
* Algorithm bitmask
* Time Limit 0.944s
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
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define M 100000

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
int row[M + 1];
int n, d, Ans;
char s[16];
int run(int level, int x, int d1, int d2){
    if (level == n) return 1;
    int x1 = (d1 >> 1) | (1 << (n - 1));
    int x2 = (d2 << 1) | 1;
    int cur = x & x1 & x2 & row[level];
    int res = 0;
    while ( cur ) {
        int xx = (cur & -cur);
        res+=run(level + 1, x^xx, x1^xx, x2^xx);
        cur^=xx;
    }
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int Case = 0;
    while ( scanf(" %d ",&n) && n) {
        REP(i, n) {
            gets(s);
            row[i] = (1 << n) - 1;
            REP(j, n)
                if (s[j] == '*') row[i]^= (1<<j);
        }
        d = (1 << n) - 1;
        Ans = run(0, d, d, d);
        printf("Case %d: %d\n",++Case,Ans);
    }
}
