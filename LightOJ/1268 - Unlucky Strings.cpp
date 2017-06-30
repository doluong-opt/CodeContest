/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1268 - Unlucky Strings ->AC
* Algorithm KMP + matrix
* Time Limit 0.833s
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
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 55
#define uint unsigned int
#define MOD 4294967296LL

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int masK, int bit) { return masK & (1 << bit); }
inline int Or(int masK, int bit) { return masK | (1 << bit); }
inline int Xor(int masK, int bit) { return masK & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int sz;
struct Matrix{
    uint64 a[55][55];
    Matrix(){
        rep(i, sz) rep(j, sz)
            a[i][j] = 0;
    }
    Matrix multi(Matrix m){
        Matrix res;
        rep(i, sz) rep(j, sz) rep(k, sz) {
            res.a[i][j] += a[i][k] * m.a[k][j];
            res.a[i][j] %= MOD;
        }
        return res;
    }
};

int m, n, k;
char p[N], s[N];
int next[N];

void preKmp() {
    int i, j;
    i = 0; j = next[0] = -1;
    while (i <= n) {
        while (j >=0 && s[i] != s[j]) j = next[j];
        ++i; ++j;
        next[i] = j;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases;
    scanf("%d",&cases);
    fr(i, 1, cases) {
        scanf(" %d ",&k);
        gets(p); m = strlen(p);
        gets(s); n = strlen(s); sz = n + 1;
        strcat(s, "@");        
        preKmp();
        Matrix base, res;
        fr(i, 0, n)
            fr(j, 0, n)
                res.a[i][j] = (i == j ? 1 : 0);
        base.a[0][0] = m; base.a[0][n - 1]--; if ( base.a[0][n-1] < 0) base.a[0][n-1]+=MOD;
        fr(i, 1, n - 1)
            base.a[i][i - 1] = 1;
            
        for (int i = next[n]; i > 0; i = next[i]) {
            base.a[i][n - 1]--;
            if (base.a[i][n - 1] < 0) base.a[i][n - 1]+=MOD;
        }

        while ( k ) {
            if (k & 1) res = res.multi(base);
            k>>=1;
            base = base.multi(base);
        }
        printf("Case %d: %lld\n",i, res.a[0][0] % MOD);
    }
}
