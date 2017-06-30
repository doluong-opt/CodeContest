/***********************************************
* Author LUONG VAN DO                        *
* Problem 10309 - Turn the Lights Off
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
#define N 12
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
char s[N], ss[N][N];
int a[N][N], b[N][N], ans, lim;
int dx[] = {0, 0, 1, 0, -1};
int dy[] = {0, 1, 0, -1, 0};
int isOk(int u, int v) {
    return (u >= 0 && u < 10 && v>=0 && v < 10);
}
void flip(int x, int y) {
    for (int i = 0;i < 5;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if ( isOk(nx, ny) )
            b[nx][ny]^=1;
    }
}
void solve() {
    fill(a, 0);
    rep(i, 10)
        rep(j, 10)
            a[i][j] = (ss[i][j] == 'O');
    int cnt, ans;
    ans = INF; lim = (1<<10);
    for (int mask = 0;mask < lim;mask++) {
        
        for (int i = 0;i < 10;i++)
            for (int j = 0;j < 10;j++) b[i][j] = a[i][j];
        
        cnt = 0;
        for (int i = 0;i < 10;i++)
            if ( And(mask, i) ) {
                flip(0, i);
                cnt++;
            }
        
        for (int i = 1;i < 10;i++)
            for (int j = 0;j < 10;j++)
                if ( b[i - 1][j] == 1 ) {
                    cnt++;
                    flip(i, j);
                }
        bool on = true;
            for (int i = 0;i < 10;i++)
                if ( b[9][i] ) on = false;
        //cout<<on<<" "<<cnt<<endl;
        if (on && cnt < ans) ans = cnt;
        if (ans != INF && ans > 100) break;
    }
    if (ans == INF || ans > 100) puts(" -1");
    else printf(" %d\n", ans);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    while ( gets(s) && strcmp(s, "end")) {
        rep(i, 10) gets(ss[i]);
        cout << s;
        solve();
    }
}
