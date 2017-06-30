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
#define MOD 1000000007

int sz = 35;

struct Matrix{
    int64 a[35][35];
    Matrix(){
        rep(i, sz) rep(j, sz)
            a[i][j] = 0;
    }
    Matrix multi(Matrix m){
        Matrix res;
        rep(i, sz) rep(j, sz) rep(k, sz) {
            res.a[i][j] += a[i][k] * (int64)m.a[k][j];
            res.a[i][j] %= MOD;
        }
        return res;
    }
};

int n;
vector <vi> sta;
int64 ans;
Matrix x, y;

bool isOk(vi a, vi b) {
    bool flag;
    do{
        flag = true;
        rep(i, 4)
            if (abs(a[i] - b[i]) != 1) {
                flag = false;
                break;
            }
        if (flag) return true;
    }while (next_permutation(all(b)));
    return false;
}
void init() {
    rep(i, 7) fr(j, i + 1, 6) fr(k, j + 1, 6) fr(l, k + 1, 6) {
        vi tm;
        tm.pb(i); tm.pb(j); tm.pb(k); tm.pb(l);
        sta.pb(tm);
    }
    rep(i, sta.size()) rep(j, sta.size())
        if ( isOk(sta[i], sta[j]) ) x.a[i][j] = 1;
        else x.a[i][j] = 0;
    rep(i, sz) rep(j, sz)
        y.a[i][j] = (i == j ? 1 : 0);
}
void build(Matrix &base, Matrix &res) {
    rep(i, sz) rep(j, sz) {
        base.a[i][j] = x.a[i][j];
        res.a[i][j] = y.a[i][j];
    }
}
int main(){
	freopen("exam.inp","r",stdin);
	freopen("exam.out","w",stdout);
	int cases, caseno = 0, pos;
	init();
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);        
        vi p;
        rep(i, 7) {
            scanf("%d", &pos);
            if (pos) p.pb(i);
        }
        if (n == 1) {
            printf("Case %d: 1\n", ++caseno);
            continue;
        }
        rep(i, sta.size()) 
            if (sta[i] == p) {
                pos = i;
                break;
            }
        n--;
        cout << pos << endl;
        Matrix base, res;
        build(base, res);        
        while ( n ) {
            if (n & 1) res = res.multi(base);
            n>>=1;
            base = base.multi(base);
        }
        ans = 0;
        rep(i, sz) {
            ans += res.a[pos][i];
            ans %= MOD;
        }
        printf("Case %d: %lld\n", ++caseno, ans);
    }
}
