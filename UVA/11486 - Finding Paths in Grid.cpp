/***********************************************
* Author - LUONG VAN DO                        *
* Problem
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
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i = b;i >= a;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define pb push_back
#define ff first
#define ss second
#define fill(arr, val) memset(arr, val, sizeof(arr))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 1000000000
#define N 100100
#define mod 1000000007
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
int sz = 35;
struct Matrix{
    int64 a[36][36];
    Matrix(){
        rep(i, sz) rep(j, sz) a[i][j] = 0;
    }
    Matrix multi(Matrix m) {
        Matrix res;
        rep(i, sz) rep(j, sz) rep(k, sz) {
            res.a[i][j] += a[i][k] * (int64)m.a[k][j];
            res.a[i][j] %= mod;
        }
        return res;
    }
};
int n, pos, ans;
vector <vi> sta;
Matrix x, y;
inline bool isOk(vi a, vi b) {
    bool flag;
    do{
        flag = true;
        rep(i, 4)
            if ( abs(a[i] - b[i]) != 1 ) {
                flag = false;
                break;
            }
        if (flag) return true;
    }while (next_permutation(b.begin(), b.end()));
    return false;
}
inline void init() {
    rep(i, 7) fr(j, i + 1, 6) fr(k, j + 1, 6) fr(t, k + 1, 6) {
        vi temp;
        temp.pb(i); temp.pb(j); temp.pb(k); temp.pb(t);
        sta.pb(temp);
    }
    rep(i, sta.size()) rep(j, sta.size())
        if (isOk( sta[i], sta[j] )) x.a[i][j] = 1;
        else x.a[i][j] = 0;
    rep(i, sz) y.a[i][i] = 1;
}
inline void build(Matrix &base, Matrix &res) {
    rep(i, sz) rep(j, sz) {
        base.a[i][j] = x.a[i][j];
        res.a[i][j] = y.a[i][j];
    }
}
inline void nextint(int &num) {
    char c; num = 0;
    do { c = getchar(); } while (c < '0' || c > '9');
    do { num = num * 10 + c - '0'; c = getchar();
    }while (c >= '0' && c <= '9');
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
	init();
	nextint(cases);
	while (cases--) {
	    nextint(n);
	    vi p;
	    rep(i, 7) {
	        nextint(pos);
	        if (pos) p.pb(i);
	    }
	    if (n == 1) {
	        printf("1\n");
	        continue;
	    }
	    rep(i, sta.size())
            if (sta[i] == p) {
                pos = i;
                break;
            }
        n--;
        Matrix base, res;
        build(base, res);
        while ( n ) {
            if (n & 1) res = res.multi(base);
            n >>= 1;
            base = base.multi(base);
        }
        ans = 0;
        rep(i, sz) {
            ans += res.a[pos][i];
            if (ans > mod) ans -= mod;
        }
        printf("%d\n", ans);
	}
	return 0;
}
