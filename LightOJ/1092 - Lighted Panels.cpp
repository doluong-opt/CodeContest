/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1092 - Lighted Panels ->AC
* Algorithm dp
* Time Limit 2.204s
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
#define M 100000

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
int m, n;
int dx[] = {0, -1, 0, 1, 1, 1, 0, -1, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
int init[10][10], cur[10][10];
int ok(int x, int y) {
    return (x>=0 && x<m && y>=0 && y<n);
}
void flip(int x, int y) {
    for (int i=0;i<9;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (ok(nx, ny))
            cur[nx][ny]^=1;
    }
}
int cal() {
    int s = 0;
    for (int i=1;i<m;i++)
        for (int j=1;j<n;j++)
            if (cur[i-1][j-1] == 0) {
                flip(i, j);
                s++;
            }
    for (int i=0;i<m;i++)
        for (int j=0;j<n;j++)
            if (cur[i][j] == 0) return INF;
    return s;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    int lim, Ans, cnt;
    char s[10][10];
    scanf("%d",&cases);
    while (cases--) {
        scanf(" %d %d ",&m,&n);
        for (int i=0;i<m;i++) gets(s[i]);
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                init[i][j] = (s[i][j] == '*');
        lim = (1 << (n + m)) - 1; Ans = INF;
        for (int mask=0;mask<lim;mask++) {
            
            for (int j=0;j<m;j++)
                for (int k=0;k<n;k++)
                    cur[j][k] = init[j][k];
            
            cnt = 0;
            for (int i=0;i<m;i++)
                if ( And(mask, i) ) {
                    flip(i, 0);
                    cnt++;
                }
            
            for (int i=1;i<n;i++)
                if ( And(mask, m + i) ) {
                    flip(0, i);
                    cnt++;
                }
            cnt+=cal();
            if (cnt < Ans) Ans = cnt;
        }
        if (Ans != INF) printf("Case %d: %d\n",++caseno, Ans);
        else printf("Case %d: impossible\n",++caseno);
    }
}
