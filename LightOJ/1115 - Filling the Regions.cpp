/***********************************************
* Author - LUONG VAN DO                        *
* 1115 - Filling the Regions ->AC
* Algorithm dfs
* Time Limit 0.03s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
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
#define N 55
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int r, c;
char s[N][N];
int dx[] = {0, 1, 0, -1, -1, 1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
int color[N][N];
int found;
int ok(int u, int v){
    return (u>=0 && u<r && v>=0 && v<c);
}
void dfs(int x, int y, int f, char ch) {
    if (x == 0 || x == r - 1 || y == 0 || y == c - 1) {
        found = 1;
        return;
    }
    if ( color[x][y] == f ) return;
    color[x][y] = f;
    for (int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!ok(nx, ny)) continue;
        if (s[nx][ny] != ch && color[nx][ny] != f) dfs(nx, ny, f, ch);
    }
}
void Fill(int x, int y, int f, char ch) {
    if (color[x][y] == f + 1) return;
    color[x][y] = f + 1;
    s[x][y] = ch;
    for (int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!ok(nx, ny)) continue;
        if (s[nx][ny] != ch && color[nx][ny] == f) Fill(nx, ny, f, ch);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, f;
    char ch;
    scanf("%d",&cases);
    while (cases--) {
        scanf(" %d %d ",&r,&c);
        for (int i=0;i<r;i++) gets(s[i]);
        for (int i=0;i<r;i++)
            for (int j=0;j<c;j++) color[i][j] = 0;
            
        f = 0;
        for (int i=1;i<r;i++) {
            for (int j=1;j<c;j++)
                if (isalpha(s[i-1][j]) && s[i-1][j] == s[i][j-1] && s[i][j] != s[i-1][j]) {
                    ch = s[i-1][j];
                    found = 0;
                    dfs(i, j, ++f, ch);
                    if ( !found ) Fill(i, j, f, ch);
                }
            }
        
        printf("Case %d:\n",++caseno);
        for (int i=0;i<r;i++) {
            cout<<s[i];
            cout<<endl;
        }
    }
}
