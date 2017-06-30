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
#define N 100000
int sz = 36;
struct Matrix{
    uint a[40][40];
    Matrix(){
        rep(i, sz) rep(j, sz)
            a[i][j] = 0;
    }
    Matrix multi(Matrix m){
        Matrix res;
        rep(i, sz) rep(j, sz) rep(k, sz)
            res.a[i][j] += a[i][k] * m.a[k][j];
        return res;
    }
};
int n;
uint ans;
bool isOk(int x, int y) {
    return abs(x - y) >= 2;
}
void build(Matrix &base, Matrix &res) {
    vii sta;
    int x1, y1, x2, y2;
    rep(i, sz) rep(j, sz)
        res.a[i][j] = (i == j ? 1 : 0);
    
    rep(i, 10) fr(j, i + 1, 9)
        if (isOk(i, j)) sta.pb(ii(i, j));
        
    rep(i, sta.size()) rep(j, sta.size()) {
        x1 = sta[i].ff; x2 = sta[j].ff;
        y1 = sta[i].ss; y2 = sta[j].ss;
        if (isOk(x1, x2) && isOk(x1, y2) && isOk(y1, x2) && isOk(y1, y2)) base.a[i][j] = 1;
        else base.a[i][j] = 0;
    }
}
int main(){
	//freopen("exam.inp","r",stdin);
	//freopen("exam.out","w",stdout);
	int cases, caseno = 0;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        if (n == 1) {
            printf("Case %d: 36\n", ++caseno);
            continue;
        }
        Matrix base, res;
        build(base, res);
        n--;
        while ( n ) {
            if (n & 1) res = res.multi(base);
            n>>=1;
            base = base.multi(base);
        }
        ans = 0;
        rep(i, sz) rep(j, sz)
            ans += res.a[i][j];
        printf("Case %d: %u\n", ++caseno, ans);
    }
}
