/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1434 - Patch Quilt ->AC
* Algorithm bfs
* Time Limit 0.075s
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
struct node {
    int x, y;
    string z;
    node(){}
    node(int xx, int yy, string zz) {
        x = xx; y = yy; z = zz;
    }
};
vector <ii> adj[30];
char s[35][35];
char ch[25];
int r, c, n;
int dx[] = {0, -1, 0, 1, 1, 1, 0, -1, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1, 0};
string ans;
bool valid(int i, int j) {
    return (i>=0 && j>=0 && i<r && j<c);
}
string cal(int u) {
    if (u == 0) return "*";
    if (u == 1) return "LD";
    if (u == 2) return "L";
    if (u == 3) return "LU";
    if (u == 4) return "U";
    if (u == 5) return "RU";
    if (u == 6) return "R";
    if (u == 7) return "RD";
    if (u == 8) return "D";
}
bool bfs(int &x, int &y) {
    int k;
    queue <node> Q, P;
    Q.push(node(x, y," ,"));
    string zz = ""; k = 0;
    while ( true ) {
        ++k;
        if (k >= n) return false;
        while ( !Q.empty() ) {
            node u = Q.front(); Q.pop();
            for (int i=0;i<9;i++) {
                int nx = u.x + dx[i];
                int ny = u.y + dy[i];
                if ( !valid(nx, ny) ) continue;
                if (ch[k] == s[nx][ny] ) {
                    x = nx; y = ny;
                    zz = u.z + cal(i);
                        if (k == n - 1) {
                            ans = zz;
                            return true;
                        }
                    P.push(node(nx, ny, zz + " ,"));
                }
            }
        }
        if (P.empty()) return false;
        while ( !P.empty() ) {
            Q.push(P.front()); P.pop();
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    int x, y, m, q, flag;
    string name;
    scanf("%d",&cases);
    while (cases--) {
        for (int i=0;i<30;i++) adj[i].clear();
        scanf(" %d %d ",&r,&c);
        for (int i=0;i<r;i++) gets(s[i]);
        for (int i=0;i<r;i++)
            for (int j=0;j<c;j++)
                adj[s[i][j] - 'A'].pb(ii(i, j));
        printf("Case %d:\n",++caseno);
        scanf(" %d ",&q);
        while (q--) {
            gets(ch); n = strlen(ch); flag = 0;
            name = ch;
            for (int i=0;i<n/2;i++) swap(ch[i], ch[n-i-1]);
            m = ch[0] - 'A'; ans = "";
            for (int i=0;i<adj[m].size() && !flag;i++) {
                x = adj[m][i].ff;
                y = adj[m][i].ss;
                if ( bfs(x, y) ) flag = 1;
            }
            cout<<name;
            if (!flag) printf(" not found\n");
            else {
                printf(" found:");
                printf(" (%d,%d)",x + 1,y + 1);
                printf(", ");
                for (int i=ans.size()-1;i>=2;i--) cout<<ans[i];
                cout<<endl;
            }
        }
    }
}
