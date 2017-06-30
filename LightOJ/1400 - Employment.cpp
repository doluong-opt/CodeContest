// =============================================================================
// Author LUONG VAN DO
// Problem
// Algorithm
// Time Limit
// =============================================================================
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
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint unsigned int

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 111222333
#define N 222
int priWo[N][N];
int Cx[N], pos[N], n;
vector <int> adj[N];
void solve() {
    int cnt = 0, i, v;
    fill(pos, 0);
    fr(i, 1, 2 * n) Cx[i] = -1;
    while (cnt < n) {
        i = 1;
        while (i <= n && Cx[i] != -1) i++;
        if (i > n) break;
        v = adj[i][pos[i]++];
        if (Cx[v] == -1) {
            Cx[i] = v;
            Cx[v] = i;
            cnt++;
        }
        else
        if (priWo[v][Cx[v]] > priWo[v][i]) {
            Cx[Cx[v]] = -1;
            Cx[i] = v;
            Cx[v] = i;
        }
    }
}
int main(){
	freopen("exam.inp","r",stdin);
	freopen("exam.out","w",stdout);
	int cases, caseno = 0, x;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        fr(i, 1, 2 * n) adj[i].clear();
        fr(i, 1, n)
            fr(j, 1, n) {
                scanf("%d", &x);
                adj[i].pb(x);
            }
        fr(i, 1, n)
            fr(j, 1, n) {
                scanf("%d", &x);
                priWo[i + n][x] = j;
            }
        solve();
        printf("Case %d:", ++caseno);
        fr(i, 1, n)
            printf(" (%d %d)", i, Cx[i]);
        puts("");
    }
}

