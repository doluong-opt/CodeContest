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
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1000111

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
int n, i1, i2, ans, res, m, l1, l2, p, a[N];
vector <int> pos[N], num;
set <int> st;
set <int> :: iterator it;
int fl(int key, vector <int> a, int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= key) r = mid - 1;
        else l = mid + 1;
    }
    if (l >= a.size()) return 0;
    return a[l];
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
	    scanf("%d", &a[i]);
	    st.insert(a[i]);
	    pos[a[i]].pb(i);
	}
	if (n <= 2) {
	    printf("%d\n", n);
	    return 0;
	}
	for (it = st.begin(); it != st.end(); it++) num.pb(*it);
	ans = 0; m = num.size();
	rep(i, m) if ( ans < pos[num[i]].size() ) ans = pos[num[i]].size();
	if (ans == 1) {
	    printf("2\n");
	    return 0;
	}
	for (int i = 0;i < m;i++)
        for (int j = i + 1;j < m;j++) {
            int x = num[i];
            int y = num[j];
            res = 2;
            if (pos[x][0] > pos[y][0]) swap(x, y);
            i1 = pos[x][0]; l1 = pos[x].size();
            i2 = pos[y][0]; l2 = pos[y].size();
            int turn = 1;
            while ( true ) {
                if ( turn ) {
                    p = fl(i2, pos[x], 0, l1 - 1);
                    if (p <= i2) break;
                    i1 = p;
                    res++;
                }
                else {
                    p = fl(i1, pos[y], 0, l2 - 1);
                    if (p <= i1) break;
                    i2 = p;
                    res++;
                }
                turn ^= 1;
            }
            ans = max(ans, res);
        }
    printf("%d\n", ans);
	return 0;
}
