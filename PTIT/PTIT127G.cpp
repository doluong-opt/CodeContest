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
int n, m, sz, id;
string ans[N], str;
char s[N];
bool cmp(string x, string y) {
    int nx = x.size(), ny = y.size();
    if (nx < ny) return true;
    if (nx > ny) return false;
    int id = 0;
    while (id < nx && x[id] == y[id]) id++;
    if (id == nx) return true;
    return (x[id] < y[id]);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf(" %d ", &n);
	sz = 0;
	rep(i, n) {
	    gets(s); m = strlen(s); id = 0;
	    while (id < m) {
	        str = "";
	        while (id < m && s[id] >= '0' && s[id] <= '9') str += s[id++];
	        while (str.size() > 1 && str[0] == '0') str.replace(0, 1,"");
	        if (str.size() > 0) ans[sz++] = str;
	        while (id < m && (s[id] < '0' || s[id] > '9')) id++;
	    }
	}
	sort(ans, ans + sz, cmp);
	rep(i, sz) cout<<ans[i]<<endl;
	return 0;
}
