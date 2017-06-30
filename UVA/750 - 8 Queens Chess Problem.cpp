/***********************************************
* Author LUONG VAN DO                        *
* Problem 750 - 8 Queens Chess Problem
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
#define N 100000

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
int a[10], b[10], c[20];
int color[10], x[10], n;
vector <int> adj[N];
void Printf() {
    n++;
    for (int i = 1;i <= 8;i++)
        adj[n].pb(x[i]);
}
void backTrack(int i){ 
    for (int j = 1;j <= 8;j++) {
        if (!a[j] && !b[i - j] && !c[i + j]) {
            x[i] = j;
            a[j] = 1;
            b[i - j] = 1;
            c[i + j] = 1;
            if (i == 8) Printf();
            else backTrack(i + 1);
            a[j] = 0;
            b[i - j] = 0;
            c[i + j] = 0;
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    n = 0;
    backTrack(1);
    int cases, x, y, caseno = 0, cnt;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d", &x, &y);
        if (caseno) puts("");
        caseno = 1;
        cnt = 0;
        puts("SOLN       COLUMN");
        puts(" #      1 2 3 4 5 6 7 8");
        puts("");
        for (int i = 1;i <= 92;i++) {
            int flag = 0;
            for (int j = 0;j < 8 && !flag;j++)
                if (x == adj[i][j] && y == j + 1) flag = 1;
            if (flag) {
                printf("%2d      ",++cnt);
                for (int j = 0;j < 8;j++) {
                    if (j) printf(" ");
                    printf("%d", adj[i][j]);
                }
                puts("");
            }
        }
    }
}
