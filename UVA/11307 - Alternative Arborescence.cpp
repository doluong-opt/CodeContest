/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11307 - Alternative Arborescence
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
#define N 10010

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
int n, ind;
vector <int> adj[N];
int isRoot[N], color[N];
int dp[N][10];
char s[1000000];
int getInt(int m) {
    int v = 0;
    while (ind < m && s[ind] !=' ') {
        if (s[ind] == ':') ++ind;
        else v = v * 10 + s[ind++] - '0';
    }
    ++ind;
    return v;
}

void MVC(int u) {
    
    if (color[u]) return;
    color[u] = 1;
    
    for (int i=1;i<=7;i++)
        dp[u][i] = i;
        
    for (int i=0;i<adj[u].size();i++) {
        int v = adj[u][i];
        if (!color[v]) MVC( v );
    }
    
    for (int j=1;j<=7;j++) {
        int tmp = j;
        for (int h=0;h<adj[u].size();h++) {
            int v = adj[u][h];
                int Min = INF;
                for (int k=1;k<=7;k++) {
                    if (j == k) continue;
                    if (dp[v][k] < Min) Min = dp[v][k];
                }
                tmp+=Min;
        }
        dp[u][j] = tmp;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int u, v, m, ans, pos;
    while ( scanf(" %d ",&n) && n) {
        for (int i=0;i<n;i++) {
            adj[i].clear();
            color[i] = 0;
            isRoot[i] = 1;
        }
        for (int i=0;i<n;i++) {
            
            gets(s); m = strlen(s); ind = 0;
            u = getInt(m);
            while (ind < m) {
                v = getInt(m);
                adj[u].pb(v);
                isRoot[v] = 0;
            }
        }
        gets(s);
        
        for (int i=0;i<n;i++)
            for (int j=1;j<=7;j++) dp[i][j] = 0;
            
        for (int i=0;i<n;i++)
            if (isRoot[i]) {
                pos = i;
                MVC( i );
                break;
            }
        ans = INF;
        for (int i=1;i<=7;i++)
            ans = min(ans, dp[pos][i]);
        printf("%d\n",ans);
    }
}
