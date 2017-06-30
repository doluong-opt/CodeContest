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
int n, k, curNum, md, pos, kk;
vector <int> num, ans;
int color[11][11];
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d", &n, &k);
	rep(i, 10) rep(j, 10) color[i][j] = 0;
	md = (n * k) / 10;
	curNum = (n * k) % 10;
	for (int i = 0;i < 1000;i++) {
	    num.pb(curNum);
	    k = (n * curNum) + md;
	    curNum = k % 10;
	    md = k / 10;
	}
	color[num[0]][num[1]] = 1;
	/*rep(i, num.size()) cout<<num[i];
	cout<<endl;*/
	fr(i, 1, num.size() - 1) {
        if ( color[num[i]][num[i + 1]] ) {
            pos = i - 1;
            break;
        }
	}
	fr(i, 0, pos) ans.pb(num[i]);
	reverse(ans.begin(), ans.end());
	if (ans[1] == 0) puts("0");
	else {
	    fr(i, 1, ans.size() - 1) printf("%d", ans[i]);
	    printf("%d\n", ans[0]);
	}
	
	return 0;
}
