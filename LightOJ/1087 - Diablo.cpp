/***********************************************
* Author LUONG VAN DO                        *
* Problem 1087 - Diablo 
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

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 111222333
#define N 200000

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
int tree[N], a[N], n, m;

void updateBIT(int i, int val) {
    while (i < N) {
        tree[i] += val;
        i += (i&-i);
    }
}

int getBIT(int i) {
    int result = 0;
    while ( i ) {
        result += tree[i];
        i -= (i&-i);
    }
    return result;
}
int findPos(int x, int l, int r) {
    while ( l <= r ) {
        int mid = (l + r) >> 1;
        if ( getBIT(mid) >= x ) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, d, x;
    char c;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d",&n, &m);
        fill(tree, 0);
        fr(i, 1, n) {
            scanf(" %d ", &a[i]);
            updateBIT(i, 1);
        }
        printf("Case %d:\n",++caseno);
        while (m--) {
            scanf(" %c %d ",&c, &d);
            if (c == 'c') {
                x = findPos(d, 1, n);
                if (getBIT(x) != d) puts("none");
                else {
                    printf("%d\n", a[x]);
                    updateBIT(x, -1);
                }
            }
            else {
                a[++n] = d;
                updateBIT(n, 1);
            }
        }
    }
}
