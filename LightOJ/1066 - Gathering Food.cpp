/***********************************************
* Author - LUONG VAN DO                        *
* 1066 - Gathering Food ->AC
* Algorithm bfs
* Time Limit 0.002s
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
#define maxN 50001

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node{
    int x, y, c;
    node(){}
    node(int xx, int yy, int cc){
        x = xx; y = yy; c = cc;
    }
} a ;
int n;
char s[20][20];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int x[30], y[30];
int color[20][20];
bool ok(int u, int v){
    return (u>=0 && u<n && v>=0 && v<n);
}
int bfs(int sx, int sy, int Now) {
    queue <node> Q;
    REP(i, n)
        REP(j, n) color[i][j] = 0;
    Q.push(node(sx, sy, 0));
    color[sx][sy] = 1;
    while ( !Q.empty() ) {
        a = Q.front(); Q.pop();
        REP(k, 4) {
            int nx = a.x + dx[k];
            int ny = a.y + dy[k];
            if ( !ok(nx, ny) || s[nx][ny] == '#' || color[nx][ny] ) continue;
            if (s[nx][ny] - 'A' == Now || s[nx][ny] == '.') {
                color[nx][ny] = 1;
                if ( s[nx][ny] - 'A' == Now ) return a.c + 1;
                Q.push(node(nx, ny, a.c + 1));
            }
        }        
    }
    return INF;
}
void Read() {
    int test, ans, d, Size, cnt, found;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d ",&n);
        REP(i, n) gets(s[i]);
        ans = Size = cnt = 0;
        found = 1;
        REP(i, n)
            REP(j, n)
                if ( isalpha(s[i][j]) ) {
                    x[s[i][j]-'A'] = i;
                    y[s[i][j]-'A'] = j;
                    Size = max(Size, s[i][j]-'A');
                    cnt++;
                }
        if (cnt == 1) {
            printf("Case %d: 0\n",t);
            continue;
        }
        REP(i, Size) {
            s[x[i]][y[i]] = '.';
            d = bfs(x[i], y[i], i + 1);
            cout<<d<<endl;
            if (d!=INF) ans+=d;
            else {
                found = 0;
                break;
            }
        }
        if ( !found ) printf("Case %d: Impossible\n",t);
        else printf("Case %d: %d\n",t,ans);
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
