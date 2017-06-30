/***********************************************
* Author - LUONG VAN DO                        *
* Problem 12599 - Black and White
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
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 100111

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
vector <int> res[N];
char s[N];
int n, i, j, sz;
int mark[N];
ii pos[N];
bool isOk() {
    int x = 0, y = 0;
    rep(i, n)
        if (s[i] == 'B') x++;
    else
        if (s[i] == 'W') y++;
    return (x == n || y == n);
}
bool cmp(ii a, ii b) {
    return (a.ss < b.ss);
}
void solve(int pos, int m) {
    while (pos < n && s[pos] == 'B') {
        res[m].pb(pos);
        pos++;
    }   
    while (pos < n && s[pos] == 'W') {
        res[m].pb(pos);
        pos++;
    }
    j = pos;
}
bool check() {
    int k = 0;
    while (k < n && s[k] == 'B') k++;
    while (k < n && s[k] == 'W') k++;
    return (k == n);
}
int main() {    
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
	scanf(" %d ", &cases);
	while (cases--) {
	    gets(s); n = strlen(s);
	    if ( isOk() || s[0] == 'W' || s[n - 1] == 'B') {
	        printf("IMPOSSIBLE\n");
	        continue;
	    }
	    if ( check() ) {
	        printf("1\n");
	        printf("%d", n);
	        printf(" 1");
	        for (int i = 1;i < n;i++)
                printf(" %d", i + 1);
            puts("");
            continue;
	    }
	    res[0].clear(); res[1].clear();
	    int b = 0, w = 0, cnt1 = 0, cnt2 = 0;
	    for (int i = 0;i < n;i++) {
	        mark[i] = 0;
	        if (s[i] == 'W') w++;
	        else b++;
	    }
        for (int i = 0;i < n;i++)
            if (s[i] == 'B') {
                mark[i] = 1;
                res[0].pb(i + 1);
                for (int j = i + 1;j < n;j++)
                    if ( s[j] == 'W' && cnt1 < w - 1) {
                        res[0].pb(j + 1);
                        mark[j] = 1;
                        cnt1++;
                    }
                break;
            }
        for (int i = 0;i < n;i++)
            if ( !mark[i] ) res[1].pb(i + 1);
        printf("2\n");
        rep(i, 2) {
            printf("%d", res[i].size());
            rep(j, res[i].size()) printf(" %d", res[i][j]);
            printf("\n");
	    }
	}
	return 0;
}
