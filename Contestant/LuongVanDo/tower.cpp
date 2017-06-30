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
#define N 1000100

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
    int x, y;
    node(){}
    node(int xx, int yy){
        x = xx; y = yy;
    }
};
node a[N];
int n, m, f[N], tree[N], maxCur;
bool cmp(node r1, node r2) {
    if (r1.x != r2.x) return r1.x < r2.x;
    return r1.y < r2.y;
}
void update(int pos, int val) {
    while (pos <= m) {
        f[pos] = max(f[pos], val);
        pos += (pos & -pos);
    }
}

int get(int pos) {
    int res = 0;
    while ( pos ) {
        res = max(res, f[pos]);
        pos -= (pos & -pos);
    }
    return res;
}
int main() {
	freopen("tower.inp","r", stdin); freopen("tower.out","w", stdout);
    scanf("%d", &n); m = 0;
    for (int i = 0;i < n;i++) {
        scanf("%d %d", &a[i].x, &a[i].y);
        if (a[i].y < a[i].x) swap(a[i].x, a[i].y);
        m = max(m, a[i].y);
    }
    sort(a, a + n, cmp);
    //for (int i = 0;i < n;i++) cout<<a[i].x<<" "<<a[i].y<<endl;
    for (int i = 0;i < n;i++) {
        maxCur = get( a[i].y );
        //cout<<maxCur<<endl;
        update(a[i].y, maxCur + 1);
    }
    printf("%d\n", get(m));
	return 0;
}
