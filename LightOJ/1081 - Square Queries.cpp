/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1081 - Square Queries  ->AC 
* Algorithm RMQ
* Time Limit 0.502s
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
#define N 510
#define MAX_LOG 9
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
int a[N][N], n, q;
int r1, r2, c1, c2, S;
int mx[N][N][MAX_LOG];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    int Ans;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d",&n,&q);
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                mx[i][j][0] = j;
                
        for (int k=0;k<n;k++)
            for (int j=1;(1<<j)<=n;j++)
                for (int i=0;i + (1<<j) - 1 < n;i++)
                    if ( a[k][mx[k][i][j - 1]] > a[k][mx[k][i + (1<<(j - 1))][j - 1]] )
                        mx[k][i][j] = mx[k][i][j - 1];
                    else
                        mx[k][i][j] = mx[k][i + (1<<(j-1))][j - 1];
                        
        printf("Case %d:\n",++caseno);
        while (q--) {
            Ans = 0;
            scanf("%d %d %d",&r1,&c1,&S);
            r1--;
            c1--;
            r2 = r1 + S - 1;
            c2 = c1 + S - 1;
            int x = (int)log2(c2 - c1 + 1);
            for (int k=r1;k<=r2;k++)
                Ans = max(Ans, max(a[k][mx[k][c1][x]], a[k][mx[k][c2 - (1<<x) + 1][x]]));
            printf("%d\n",Ans);
        }
    }
}
