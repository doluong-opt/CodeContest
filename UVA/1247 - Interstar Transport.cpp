/***********************************************
* Author LUONG VAN DO                        *
* Problem 1247 - Interstar Transport
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
#define N 30

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
int n, m;
int a[N][N], trace[N][N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    char u, v;
    int c, q, x, y;
    while ( scanf(" %d %d ", &n, &m) != EOF) {
        fill(trace, 0);
        for (int i = 0;i < 26;i++)
            for (int j = 0;j < 26;j++)
                a[i][j] = (i == j) ? 0 : INF;
        rep(i, m) {
            scanf(" %c %c %d ", &u, &v, &c);
            a[u - 'A'][v - 'A'] = c;
            a[v - 'A'][u - 'A'] = c;
        }
        for (int i = 0;i < 26;i++)
            for (int j = 0;j < 26;j++) trace[i][j] = j;
        for (int k = 0;k < 26;k++)
            for (int i = 0;i < 26;i++)
                for (int j = 0;j < 26;j++)
                    if (a[i][j] > a[i][k] + a[k][j]) {
                        a[i][j] = a[i][k] + a[k][j];
                        trace[i][j] = trace[i][k];
                    }
        scanf(" %d ", &q);
        while (q--) {
            scanf(" %c %c ", &u, &v);
            x = u - 'A';
            y = v - 'A';
            do{
                printf("%c ", x + 65);
                x = trace[x][y];
            }while (x != y);
            printf("%c\n", y + 65);
        }
    }
}
