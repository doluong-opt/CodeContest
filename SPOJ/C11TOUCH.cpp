/***********************************************
* Author LUONG VAN DO                        *
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
#define N 15

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
int n, ans, lim;
char s[N][N];
int a[N][N], temp[N][N];
int dx[] = {0, 0, 1, 0, -1};
int dy[] = {0, 1, 0, -1, 0};
int isOk(int u, int v) {
    return (u >= 0 && v >= 0 && u < n && v < n);
}

bool check1() {
    int zeros = 0;
    for (int i = 0;i < n;i++)
        if (temp[n - 1][i] == 0) zeros++;
    return (zeros == n);
}
bool check2() {
    int ones = 0;
    for (int i = 0;i < n;i++)
        if (temp[n - 1][i] == 1) ones++;
    return (ones == n);
}
void flip(int x, int y) {
    for (int i = 0;i < 5;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if ( !isOk(nx, ny) ) continue;
        temp[nx][ny]^=1;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cnt;
    scanf(" %d ", &n);
    for (int i = 0;i < n;i++) gets(s[i]);
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++) a[i][j] = s[i][j] - '0';
    ans = INF; lim = (1<<n);
    for (int mask = 0; mask < lim; mask++) {
        
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++) temp[i][j] = a[i][j];
        cnt = 0;
        for (int i = 0;i < n;i++)
            if ( And(mask, i) ) {
                flip(0, i);
                cnt++;
            }
        for (int i = 1;i < n;i++)
            for (int j = 0;j < n;j++)
                if ( temp[i - 1][j] == 1 ) {
                    flip(i, j);
                    cnt++;
                }
        if ( check1() && cnt < ans ) ans = cnt;
        
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++) temp[i][j] = a[i][j];
        cnt = 0;
        for (int i = 0;i < n;i++)
            if ( !And(mask, i) ) {
                flip(0, i);
                cnt++;
            }
            
        for (int i = 1;i < n;i++)
            for (int j = 0;j < n;j++)
                if ( temp[i - 1][j] == 0 ) {
                    flip(i, j);
                    cnt++;
                }
        if ( check2() && cnt < ans ) ans = cnt;
    }
    if (ans != INF) printf("%d\n", ans);
    else puts("-1");
}
