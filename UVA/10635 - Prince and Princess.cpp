/***********************************************
* Author LUONG VAN DO                        *
* Problem 10635 - Prince and Princess
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
#define N 255

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

int a[N * N], b[N * N];
int _index[N * N], ans[N * N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, x, y, caseno = 0;
    int lo, hi, m;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d %d", &n, &x, &y);
        x++; y++;
        fill(_index, 0);
        fill(ans, 0);
        fr(i, 1, x) scanf("%d", &a[i]);
        fr(i, 1, y) scanf("%d", &b[i]);
        fr(i, 1, x) _index[a[i]] = i;
        m = 0;
        fr(i, 1, y) {
            if ( !_index[b[i]] ) continue;
            if ( _index[b[i]] > ans[m] ) ans[++m] = _index[b[i]];
            else {
                lo = 1; hi = m;
                while (lo <= hi) {
                    int mid = (lo + hi) >> 1;
                    if ( ans[mid] > _index[b[i]] ) hi = mid - 1;
                    else lo = mid + 1;
                }
                ans[hi + 1] = _index[b[i]];
            }
        }
        printf("Case %d: %d\n", ++caseno, m);
    }
}
