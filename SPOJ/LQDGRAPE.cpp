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
#define N 501

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
    int x, y, id;
    node(){}
    node(int _x, int _y, int _id){
        x = _x; y = _y; id = _id;
    }
};
int m, n, q, k, u, v;
int a[N][N], minVal[N][N][N], maxVal[N][N][N];
int f[100111][N], tree[100111], res[11111];
node que[11111];
bool cmp(node a, node b) {
    return (a.y < b.y);
}
void update(int x, int val) {
    while ( x ) {
        tree[x] = max(tree[x], val);
        x -= (x & -x);
    }
}
int getMax(int x) {
    int ans = 0;
    while ( x <= 100000 ) {
        ans = max(ans, tree[x]);
        x += (x & -x);
    }
    return ans;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d %d %d", &m, &n, &q); k = min(m, n);
	fr(i, 1, m) fr(j, 1, n) {
	    scanf("%d", &a[i][j]);
	    minVal[1][i][j] = a[i][j];
	    maxVal[1][i][j] = a[i][j];
	}
	fr(t, 2, k) fr(i, 2, m) fr(j, 2, n) {
        minVal[t][i][j] = min(minVal[t - 1][i - 1][j - 1], min(minVal[t - 1][i - 1][j], minVal[t - 1][i][j - 1]));
        maxVal[t][i][j] = max(maxVal[t - 1][i - 1][j - 1], max(maxVal[t - 1][i - 1][j], maxVal[t - 1][i][j - 1]));
	}	
	fill(f, -1); fill(tree, 0);
	for (int i = 1;i <= k;i++)
        for (int j = 1;j <= n;j++)
            for (int h = 1;h <= n;h++) {
                u = minVal[i][j][h];
                v = maxVal[i][j][h];
                f[v][i] = u;
            }
    fr(i, 1, q) {
        scanf("%d %d", &u, &v);
        que[i] = node(u, v, i);
    }
    sort(que + 1, que + q + 1, cmp);
    v = 1;
    //for (int i = 1;i <= q;i++) cout<<que[i].x<<" "<<que[i].y<<endl;
    for (int i = 1;i <= q;i++) {
        cout<<que[i].id<<" "<<v<<" "<<que[i].y<<endl;
        
        for (int x = v;x <= que[i].y; x++)
            for (int j = 1;j <= k;j++) {
                if (f[x][j] != -1 && f[x][j] != 0) {
                    cout<<"DS"<<" "<<f[x][j]<<" "<<x<<" "<<j<<endl;
                    update(f[x][j], j);
                }
            }
        v = que[i].y;
        res[que[i].id] = getMax(que[i].x);
    }
    for (int i = 1;i <= q;i++) printf("%d\n", res[i] * res[i]);
	return 0;
}
