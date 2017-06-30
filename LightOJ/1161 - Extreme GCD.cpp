/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1161 - Extreme GCD 
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
#define N 10010

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
int64 ans[N], c[N], maxV, res;
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    int m, x, n;
    c[4] = 1;
    for (int i = 5;i <= 10000;i++)
        c[i] = (c[i - 1] * i) / (i - 4);
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d",&n);
        for (int i = 1;i < N;i++) ans[i] = 0;
        maxV = 0;
        for (int i=0;i<n;i++) {
            scanf("%d",&x);
            maxV = max(maxV, x);
            for (int j = 1;j * j <= x;j++)
                if (x % j == 0) {
                    ans[j]++;
                    if (j * j != x) ans[x / j]++;
                }
        }
        for (int i = maxV;i >= 1;i--) {
            ans[i] = c[ans[i]];
            for (int j=i + i;j <= maxV;j+=i) ans[i] -= ans[j];
        }
        printf("Case %d: %lld\n",++caseno, ans[1]);
    }
}
