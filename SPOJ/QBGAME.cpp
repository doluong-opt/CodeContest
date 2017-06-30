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
#define N 10100

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
vi mask;
int64 a[N][1<<8], res;
int64 ans[N][1<<8];
int n;
int64 Sum(int bit, int64 *a) {
    int64 ans = 0;
    for (int i = 0;i < 8;i++)
        if ( And(bit, i) ) ans += a[i];
    return ans;
}
bool check(int x) {
    return ((x | 3) == x || (x | 6) == x || (x | 12) == x || (x | 24) == x || (x | 48) == x || (x | 96) == x || (x | 192) == x);
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n); res = -1000000000LL;
	for (int j = 0;j <= 7;j++)
        for (int i = 1;i <= n;i++) {
            scanf("%lld", &a[i][j]);
            if (res < a[i][j]) res = a[i][j];
        }
    
    if (res <= 0) {
        printf("%lld\n", res);
        return 0;
    }
    for (int i = 0;i < 256;i++)
        if (!check(i)) mask.pb(i);
    for (int i = 1;i <= n;i++) {
        for (int j = 0;j < mask.size();j++) {
            int64 temp = 0;
                for (int k = 0;k < mask.size();k++) {
                    if (mask[j] & mask[k]) continue;
                    if (ans[i - 1][mask[k]] > temp) temp = ans[i - 1][mask[k]];
                }
            ans[i][mask[j]] = temp + Sum(mask[j], a[i]);
            if (res < ans[i][mask[j]]) res = ans[i][mask[j]];
        }
    }
    printf("%lld\n", res);
}
