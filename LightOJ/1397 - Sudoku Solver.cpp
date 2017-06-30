/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1397 - Sudoku Solver ->AC
* Algorithm backtraking
* Time Limit 0.147s
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
#define N 10
#define maxN 110
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
char grid[N][N];
int row[N], col[N], box[N], id[N][N], total, n;
int x[maxN], y[maxN];
int findIn(int x, int y) {
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
void init() {
    for (int i=0;i<9;i++)
        for (int j=0;j<9;j++)
            id[i][j] = findIn(i, j);
}
bool run(int cur) {
    if (cur == total) return true;
    int xx, yy, u, v, nx, ny, k, minNum = INF;
    for (int i=0;i < n;i++) {
        xx = x[i]; yy = y[i];
        if ( grid[xx][yy] == '.' ) {
            k = 0;
            for (int j = 0;j < 9;j++)
                if ( !And(row[xx], j) && !And(col[yy], j) && !And(box[id[xx][yy]], j) ) k++;
            if (k < minNum) {
                minNum = k;
                u = xx;
                v = yy;
            }
        }
    }
    nx = u; ny = v;
    bool res;
    for (int j=0;j<9;j++)
        if ( !And(row[nx], j) && !And(col[ny], j) && !And(box[id[nx][ny]], j) ) {
            row[nx]|=(1<<j);
            col[ny]|=(1<<j);
            box[id[nx][ny]]|=(1<<j);
            grid[nx][ny] = (j + 1) + '0';
            res = run(cur + 1);
            if (res) return res;
            row[nx]^=(1<<j);
            col[ny]^=(1<<j);
            box[id[nx][ny]]^=(1<<j);
            grid[nx][ny] = '.';
        }
    return false;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, num, caseno = 0;
    char s[N];
    scanf(" %d ", &cases);
      cout<<cases<<endl;
    init();
    while (cases--) {
        for (int i=0;i<9;i++) gets(grid[i]);
        n = -1; total = 0;
        for (int i=0;i<9;i++) row[i] = col[i] = box[i] = 0;
        for (int i=0;i<9;i++)
            for (int j=0;j<9;j++)
                if (grid[i][j] == '.') {
                    total++;
                    ++n;
                    x[n] = i; y[n] = j;
                }
                else {
                    num = grid[i][j] - '0' - 1;
                    row[i]|=(1<<num);
                    col[j]|=(1<<num);
                    box[id[i][j]]|=(1<<num);
                }
        n++;
        run( 0 );
        printf("Case %d:\n", ++caseno);
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++)
                printf("%c",grid[i][j]);
                puts("");
        }
        gets(s);
    }
}
