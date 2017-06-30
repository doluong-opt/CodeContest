/***********************************************
* Author LUONG VAN DO                        *
* Problem  1056 - Degrees of Separation 
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
#define N 55
#define M 100010
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
int a[N][N];
char s[M];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int m, n, sl, cnt, x, y, l, id;
    int caseno = 0, ans;
    string x1, x2;
    while ( scanf(" %d %d ", &n, &m) && (m + n)){
        map <string, int> mm;
        cnt = sl = 0;
        for (int i = 1; i <= n;i++)
            for (int j = 1;j <= n;j++)
                if (i == j) a[i][j] = 0; else a[i][j] = INF;
                
        for (int i = 0;i < m;i++) {
            cin >> x1 >> x2;
            if ( !mm[x1] ) mm[x1] = ++cnt;
            if ( !mm[x2] ) mm[x2] = ++cnt;
            x = mm[x1]; y = mm[x2];
            a[x][y] = a[y][x] = 1;
        }
        for (int k = 1;k <= n;k++)
            for (int i = 1;i <= n;i++)
                for (int j = 1;j <= n;j++)
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
        ans = -1;
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                ans = max(ans, a[i][j]);
        if ( ans == -1 || ans >= INF ) printf("Network %d: DISCONNECTED\n", ++caseno);
        else printf("Network %d: %d\n", ++caseno, ans);
        puts("");
    }
}
