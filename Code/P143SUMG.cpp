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
#define uint32 unsigned int
#define INF 1000000000
#define N 100100

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
struct node{
    string x;
    int cost;
    node(){}
    node(string _x, int _cost){
        x = _x; cost = _cost;
    }
};
char str[N], s[N];
int n, m, sz, cnt;
char a[111][111];
node ans[N];
void init() {
    a[0][0] = 'q'; a[0][1] = 'w'; a[0][2] = 'e'; a[0][3] = 'r'; a[0][4] = 't'; a[0][5] = 'y'; a[0][6] = 'u'; a[0][7] = 'i'; a[0][8] = 'o'; a[0][9] = 'p';
    a[1][0] = 'a'; a[1][1] = 's'; a[1][2] = 'd'; a[1][3] = 'f'; a[1][4] = 'g'; a[1][5] = 'h'; a[1][6] = 'j'; a[1][7] = 'k'; a[1][8] = 'l'; a[1][9] = '@';
    a[2][0] = 'z'; a[2][1] = 'x'; a[2][2] = 'c'; a[2][3] = 'v'; a[2][4] = 'b'; a[2][5] = 'n'; a[2][6] = 'm'; a[2][7] = '@'; a[2][8] = '@'; a[2][9] = '@';
}
int f(char x, char y) {
    ii st, end;
    rep(i, 3) rep(j, 10) {
        if (a[i][j] == x) st = ii(i, j);
        if (a[i][j] == y) end = ii(i, j);
    }
    return abs(st.ff - end.ff) + abs(st.ss - end.ss);
}
bool cmp(node xx, node yy) {
    if (xx.cost != yy.cost) return xx.cost < yy.cost;
    return xx.x < yy.x;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
	init();
	scanf(" %d ", &cases);
	while (cases--) {
	    scanf(" %s %d ", &str, &n);
	    m = strlen(str);
	    sz = 0;
	    rep(i, n) {
	        gets(s);
	        cnt = 0;
	        rep(j, m)
                cnt += f(s[j], str[j]);
            ans[sz++] = node(s, cnt);
	    }
	    sort(ans, ans + sz, cmp);
	    rep(i, sz) cout << ans[i].x<<" "<<ans[i].cost<<endl;
	}
	return 0;
}
