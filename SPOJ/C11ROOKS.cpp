// =============================================================================
// Author LUONG VAN DO
// Problem
// Algorithm
// Time Limit
// =============================================================================
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
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint unsigned int
 
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
 
#define INF 111222333
#define N 310
int n, m;
int a[N][N], row[N], col[N];
ii d[N];
bool cmp(ii a, ii b) {
return (a.ff > b.ff);
}
int main(){
    //freopen("exam.inp","r",stdin);
    //freopen("exam.out","w",stdout);
    scanf("%d", &n);
    for (int i = 1;i <= n;i++) row[i] = col[i] = 0;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++) {
            scanf("%d", &a[i][j]);
            row[i] += a[i][j];
            col[j] += a[i][j];
        }
        int res = 0, c1, c2, r1, r2, sum, k;
        fr(x1, 1, n) fr(x2, x1, n) {
            int mx1 = 0, mx2 = 0;
            fr(j, 1, n) {
                if (x1 == x2) sum = col[j] - a[x1][j];
                else sum = col[j] - a[x1][j] - a[x2][j];
                d[j] = ii(sum, j);
            }
            sort(d + 1, d + n + 1, cmp);
            c1 = d[1].ss; mx1 = d[1].ff;
            c2 = d[2].ss; mx2 = d[2].ff;
            if (x1 != x2) {
                r1 = mx1 + mx2 + row[x1] + row[x2] - a[x1][c1] - a[x2][c2];
                //r2 = mx1 + mx2 + row[x1] + row[x2] - a[x1][c2] - a[x2][c1];
            }   
            else {
                r1 = mx1 + mx2 + row[x1] - a[x1][c1] - a[x2][c2];
                //r2 = mx1 + mx2 + row[x1] - a[x1][c2] - a[x2][c1];
            }
            res = max(res, max(r1, r2));
            k = 3;
            while (k <= n && d[k].ff == d[2].ff) {
                c1 = d[1].ss; mx1 = d[1].ff;
                c2 = d[k].ss; mx2 = d[k].ff;
                if (x1 != x2) {
                    r1 = mx1 + mx2 + row[x1] + row[x2] - a[x1][c1] - a[x2][c2];
                    //r2 = mx1 + mx2 + row[x1] + row[x2] - a[x1][c2] - a[x2][c1];
                }   
                else {
                    r1 = mx1 + mx2 + row[x1] - a[x1][c1] - a[x2][c2];
                    //r2 = mx1 + mx2 + row[x1] - a[x1][c2] - a[x2][c1];
                }
                res = max(res, max(r1, r2));
                k++;
            }
        }
        printf("%d\n", res);
}
