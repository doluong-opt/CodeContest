/***********************************************
* Author - LUONG VAN DO                        *
* 1143 - Knights in FEN ->AC
* Algorithm IDA*
* Time Limit 0.336s
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
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 50001

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
char r[6][6] = {{'1','1','1','1','1'},{'0','1','1','1','1'},{'0','0',' ','1','1'},{'0','0','0','0','1'},{'0','0','0','0','0'}};
char s[6][6];
int ans, mark[6][6][6][6];
int dx[] = {-1,1,2,2,1,-1,-2,-2};
int dy[] = {2,2,1,-1,-2,-2,-1,1};
int f(char s[6][6]){
    int d = 0;
    rep(i, 5)
        rep(j, 5)
            if (r[i][j] != s[i][j] && s[i][j] != ' ') d++;
    return d;
}
bool dfs(int g, char start[6][6], int depth) {
    int d, i, j;
    d = f(start);
    if (d == 0) return true;
    if (g + d > depth) return false;
    int x, y;
    char temp[6][6];
    rep(i, 5) rep(j, 5)
        if (start[i][j] == ' ') {
            x = i; y = j;
            break;
        }
    rep(i, 8) {
        int xx, yy;
        xx = x + dx[i]; yy = y + dy[i];
        if ( xx >=5 || yy >=5 || xx < 0 || yy < 0) continue;
        if ( !mark[x][y][xx][yy] ) {
            mark[x][y][xx][yy] = 1;            
            rep(i1, 5) rep(i2, 5) temp[i1][i2] = start[i1][i2];            
            swap(temp[x][y], temp[xx][yy]);
            if ( dfs(g + 1, temp, depth) ) return true;
            mark[x][y][xx][yy] = 0;
        }
    }
    return false;
}
int main(){
    freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
    int cases, caseno = 0;
    scanf(" %d ",&cases); 
    while (cases--) {
        rep(i, 5) gets(s[i]);
        rep(i, 5) rep(j, 5) rep(k, 5) rep(l, 5) mark[i][j][k][l] = 0;
        ans = 0;
        while ( !dfs(0, s, ans) && ans <= 15) ans++;
        if (ans >= 16) printf("Case %d: Unsolvable in less than 16 move(s).\n", ++caseno);
        else printf("Case %d: Solvable in %d move(s).\n", ++caseno, ans);
    }
    return 0;
}
