/***********************************************
* Author LUONG VAN DO                        *
* Problem 1003 - Drunk 
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
#define N 100
#define M 100010
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
vi adj[M];
int inc[M], color[M], m;
bool check() {
    int cnt, temp;
    fill(color, 0);
    cnt = 0;
    while ( cnt != m ) {
        temp = cnt;
        fr(i, 1, m) {
            if (color[i]) continue;
            if ( !inc[i] ) {
                ++cnt; color[i] = 1;
                rep(j, adj[i].size())
                    inc[adj[i][j]]--;
            }
        }
        if (temp == cnt) break;
    }
    return cnt == m;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, caseno = 0;
    int u, v;
    char s1[N], s2[N];
    scanf("%d",&cases);
    while (cases--) {
        scanf(" %d ",&n);
        fr(i, 1, M - 1) adj[i].clear();
        map <string, int> al; m = 0;
        fill(inc, 0);
        rep(i, n) {
            scanf("%s %s", s1, s2);
            if (!al[s1]) al[s1] = ++m;
            if (!al[s2]) al[s2] = ++m;
            u = al[s1]; v = al[s2];
            adj[u].pb(v);
            inc[v]++;
        }
        printf("Case %d: ",++caseno);
        if ( check() ) puts("Yes");
        else puts("No");
    }
}
