/***********************************************
* Author - LUONG VAN DO                        *
* 1256 - Word Puzzle ->AC
* Algorithm Euler
* Time Limit 0.197s
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
#define N 2010
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
string name[N];
char s[N];
int deg[N], deg_in[N], deg_out[N];
int a[N][N], n;
int mark[N], path[N], sz;
bool isEuler(){
    int x, d = 0;
    for (int i=0;i<26;i++) {
        x = abs(deg_in[i] - deg_out[i]);
        if (x == 0) continue;
        if (x == 1) d++;
        if (x > 1) return false;
    }
    return (d <= 2);
}
bool isConect() {
    int node = 0;
    for (int i=0;i<26;i++) {
        if ( deg_in[i] == 0 && deg_out[i] == 0) continue;
        if ( deg_in[i] >= deg_out[i] ) {
            node = i;
            if ( deg_in[i] > deg_out[i] ) break;
        }
    }
    for (int i=0;i<26;i++) mark[i] = 0;
    stack <int> s;
    s.push(node); mark[node] = 1;
    while ( !s.empty() ) {
        node = s.top(); s.pop();
        for (int i=0;i<26;i++)
            if ( a[node][i] && !mark[i] ) {
                mark[i] = 1;
                s.push(i);
            }
    }
    for (int i=0;i<26;i++)
        if (deg_in[i] && !mark[i]) return false;
    return true;
}
void dfs(int u) {
    for (int i=0;i<n;i++) {
        string x = name[i];
        if (x[0] - 'a' == u && !mark[i]) {
            mark[i] = 1;
            dfs(x[x.size()-1] - 'a');
            path[sz++] = i;
        }
    }
}
void Printf() {
    int node = 0;
    for (int i=0;i<26;i++) {
        if ( deg_in[i] == 0 && deg_out[i] == 0) continue;
        if ( deg_in[i] >= deg_out[i] ) {
            node = i;
            if ( deg_in[i] > deg_out[i] ) break;
        }
    }
    for (int i=0;i<n;i++) mark[i] = 0;
    sz = 0;
    dfs(node);
    string ans = "";
    ans+=name[ path[sz - 1] ];
    for (int i=sz - 2;i>=0;i--) {
        ans+=" ";
        ans+=name[ path[i] ];
    }
    puts("Yes");
    cout<< ans <<endl;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, m;
    int u, v;
    scanf("%d",&cases);
    while (cases--) {
        scanf(" %d ",&n);
        for (int i=0;i<=n;i++) path[i] = 0;
        for (int i=0;i<26;i++) {
            deg_in[i] = deg_out[i] = deg[i] = 0;
            for (int j=0;j<26;j++)
                a[i][j] = 0;
        }
        for (int i=0;i<n;i++) {
            gets(s); m = strlen(s);
            u = s[0] - 'a'; v = s[m - 1] - 'a';
            a[u][v]++; a[v][u]++;
            deg_in[u]++; deg_out[v]++;
            deg[u]++; deg[v]++;
            name[i] = s;
        }
        printf("Case %d: ",++caseno);
        if (!isEuler() || !isConect() ) {
            puts("No");
            continue;
        }
        Printf();
    }
}
