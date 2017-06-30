/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1173 - The Vindictive Coach ->AC
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
#define N 55
#define fill(arr, val) memset(arr, val, sizeof(arr))

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
int n, m;
int a[N];
uint64 f[N][N], g[N][N];
void init() {
    fill(f, 0); fill(g, 0);
    f[1][0] = 1; g[0][1] = 1;
    for (int k = 2;k <=49;k++)
        for (int a = 0;a <= k;a++) {
            int b = k - a;
            
            for (int i = 1;i <= b;i++)
                g[a][b] += f[a + i - 1][b - i];
            
            for (int i = 1;i <= a;i++)
                f[a][b] += g[a - i][b + i - 1];
        }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    init();
    int cases, caseno = 0;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d",&n, &m);
        if (m == 1) printf("Case %d: %llu\n", ++caseno, g[max(n - 3,0)][1]);
        else printf("Case %d: %llu\n", ++caseno, g[n - m][m - 1]);
    }
}
