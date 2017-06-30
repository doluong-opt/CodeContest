/***********************************************
* Author - LUONG VAN DO                        *
* Problem 989 - Su Doku ->AC
* Algorithm batracking
* Time Limit 0.008s
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
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define frr(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i=n - 1; i>=0; i--)
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 100
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

int row[N], col[N], box[N], id[N][N], a[N][N], x[N], y[N];
int n, m, total;

int findIn(int x, int y, int n) {
    if (n == 9) {
        if (x <= 2 && y <= 2) return 0;
        if (x <= 5 && y <= 2) return 1;
        if (x <= 8 && y <= 2) return 2;
        if (x <= 2 && y <= 5) return 3;
        if (x <= 5 && y <= 5) return 4;
        if (x <= 8 && y <= 5) return 5;
        if (x <= 2 && y <= 8) return 6;
        if (x <= 5 && y <= 8) return 7;
        if (x <= 8 && y <= 8) return 8;
    }
    else
    if (n == 4) {
        if (x <= 1 && y <= 1) return 0;
        if (x <= 3 && y <= 1) return 1;
        if (x <= 1 && y <= 3) return 2;
        if (x <= 3 && y <= 3) return 3;
    }
    else return 0;
}
void init(int n) {
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            id[i][j] = findIn(i, j, n);
}
bool run(int cur, int n) {
    if (cur == total) return true;
    int xx, yy, u, v, nx, ny, k, minNum = INF;
    for (int i=0;i < m;i++) {
        xx = x[i]; yy = y[i];
        if ( a[xx][yy] == 0 ) {
            k = 0;
            for (int j = 0;j < n;j++) {
                if ( !And(row[xx], j) && !And(col[yy], j) && !And(box[id[xx][yy]], j) ) k++;
            }
            if (k < minNum) {
                minNum = k;
                u = xx;
                v = yy;
            }
        }
    }
    nx = u; ny = v;
    bool res;
    for (int j=0;j<n;j++)
        if ( !And(row[nx], j) && !And(col[ny], j) && !And(box[id[nx][ny]], j) ) {
            row[nx]|=(1<<j);
            col[ny]|=(1<<j);
            box[id[nx][ny]]|=(1<<j);
            a[nx][ny] = (j + 1);
            res = run(cur + 1, n);
            if (res) return res;
            row[nx]^=(1<<j);
            col[ny]^=(1<<j);
            box[id[nx][ny]]^=(1<<j);
            a[nx][ny] = 0;
        }
    return false;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, num, caseno = 0;
    bool flag;
    while ( scanf("%d",&n) != EOF ) {
        n*=n;
        init(n);
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++) scanf("%d", &a[i][j]);
        m = -1; total = 0;
        for (int i=0;i<n;i++) row[i] = col[i] = box[i] = 0;
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                if (a[i][j] == 0) {
                    total++;
                    ++m;
                    x[m] = i; y[m] = j;
                }
                else {
                    num = a[i][j] - 1;
                    row[i]|=(1<<num);
                    col[j]|=(1<<num);
                    box[id[i][j]]|=(1<<num);
                }
        m++;
        flag = run( 0, n);
        if ( caseno ) puts("");
        caseno++;
        if (!flag) puts("NO SOLUTION");
        else
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) {
                if (j) printf(" ");
                printf("%d",a[i][j]);
            }
            puts("");
        }
    }
}
