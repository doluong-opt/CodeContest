/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1377 - Blade and Sword ->AC
* Algorithm bfs
* Time Limit 0.087s
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
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 210
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
struct node {
    int x, y, c;
    node(){}
    node(int xx, int yy, int cc){
        x = xx; y = yy; c = cc;
    }
} a ;
int r, c;
vector <ii> tele;
vector <node> t1, t2;
ii P, D;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char s[N][N];
int d[N][N][3];
bool inside(int i, int j) {
    return (i>=0 && j>=0 && i<r && j<c);
}
int bfs(int x, int y, int index) {
    d[x][y][index] = 0;
    queue <ii> q; q.push(ii(x, y));
    ii a;
    while ( !q.empty() ) {
        a = q.front(); q.pop();
        for (int i=0;i<4;i++) {
            int nx = a.ff + dx[i];
            int ny = a.ss + dy[i];
            if ( !inside(nx, ny) || s[nx][ny] == '#') continue;
            if ( d[nx][ny][index] > d[a.ff][a.ss][index] + 1) {
                d[nx][ny][index] = d[a.ff][a.ss][index] + 1;
                if ( s[nx][ny] != '*') q.push(ii(nx, ny));
            }
        }
    }
}
bool cmp1(node a, node b) {
    return (a.x < b.x);
}
bool cmp2(node a, node b) {
    return (a.y < b.y);
}
int solve(int x1, int y1, int x2, int y2) {
    int ans;
        for (int i=0;i<r;i++)
            for (int j=0;j<c;j++)
                for (int k=0;k<2;k++) d[i][j][k] = INF;
    bfs(x1, y1, 0); bfs(x2, y2, 1);
    if (tele.size() <= 1) return d[x2][y2][0];
    ans = d[x2][y2][0];
    t1.clear(); t2.clear();
    for (int i=0;i<tele.size();i++) {
        int nx = tele[i].ff;
        int ny = tele[i].ss;
        int d1 = d[nx][ny][0];
        int d2 = d[nx][ny][1];
        t1.pb(node(d1, d2, i));
        t2.pb(node(d1, d2, i));
    }
    for (int i=0;i<tele.size();i++) ans = min(ans, t1[i].x + t1[i].y + 2);
    
    sort(t1.begin(), t1.end(), cmp1);
    sort(t2.begin(), t2.end(), cmp2);
    int found;
    found = 0;
    for (int i=0;i<tele.size() && !found;i++) {
        for (int j=0;j<tele.size();j++) {
            if (t1[i].c == t2[j].c) continue;
            ans = min(ans, t1[i].x + t2[j].y + 1);
            found = 1;
            break;
        }
    }
    found = 0;
    for (int i=0;i<tele.size() && !found;i++) {
        for (int j=0;j<tele.size();j++) {
            if (t2[i].c == t1[j].c) continue;
            ans = min(ans, t2[i].y + t1[j].x + 1);
            found = 1;
            break;
        }
    }
    
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, x, y, ans, caseno = 0;
    int xx, yy;
    scanf(" %d ",&cases);
    while (cases--) {
        scanf(" %d %d ",&r,&c); tele.clear();
        for (int i=0;i<r;i++) {
            gets(s[i]);
            for (int j=0;j<c;j++) {
                if (s[i][j] == '*') tele.pb(ii(i, j));
                else
                if (s[i][j] == 'P') P = ii(i, j);
                else
                if (s[i][j] == 'D') D = ii(i, j);
            }
        }
        printf("Case %d: ",++caseno);
        ans = solve(P.ff, P.ss, D.ff, D.ss);
        if ( ans != INF ) printf("%d\n",ans);
        else puts("impossible");
    }
}
