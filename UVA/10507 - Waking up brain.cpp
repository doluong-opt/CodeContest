/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10507 - Waking up brain ->AC
* Algorithm adhoc
* Time Limit 0.02s
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
#define N 100000

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

int n, mark[N];
vector <int> adj[N];
int cnt[N];
bool wakingall() {
    int s = 0;
    for (int i=0;i<26;i++) {
        cnt[i] = 0;
        if ( mark[i] ) s++;
    }
    return (s == n);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int m, a, b, c, ans, flag, u, v;
    int x, y, z;
    char s[N];
    while ( scanf(" %d ",&n) != EOF) {
        scanf(" %d ",&m);
        gets(s);
        
        for (int i=0;i<26;i++) {
            adj[i].clear();
            mark[i] = 0;
            cnt[i] = 0;
        }
        
        a = s[0] - 'A'; b = s[1] - 'A'; c = s[2] - 'A';
        
        mark[a] = mark[b] = mark[c] = 1;
        for (int i=0;i<m;i++) {
            scanf(" %s ",s);
            u = s[0] - 'A'; v = s[1] - 'A';
            adj[u].pb(v);
            adj[v].pb(u);
        }
        flag = 0;
        for (int i=0;i<=26;i++) {
            if ( wakingall() ) {
                flag = 1;
                ans = i;
            }
            if ( flag ) break;
            for (int j=0;j<26;j++)
                if ( mark[j] )
                    for (int k=0;k<adj[j].size();k++)
                        if ( !mark[ adj[j][k] ] ) cnt[ adj[j][k] ]++;
            for (int k=0;k<26;k++)
                if ( cnt[k] >= 3 ) mark[k] = 1;
        }
        if ( flag ) printf("WAKE UP IN, %d, YEARS\n", ans);
        else puts("THIS BRAIN NEVER WAKES UP");
    }
}
