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
#define N 222
int m, n, x, y;
int a[N][N], zero[N][N], one[N][N];
int get(int a[N][N], int r1, int c1, int r2, int c2) {
    return (a[r2][c2] - a[r1 - 1][c2] - a[r2][c1 - 1] + a[r1 - 1][c1 - 1]);
}
int main(){
	freopen("exam.inp","r",stdin);
	freopen("exam.out","w",stdout);
	int cases, best, sl;
	scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d", &m, &n);
        fr(i, 1, m) fr(j, 1, n) scanf("%d", &a[i][j]);
        fill(one, 0); fill(zero, 0);
        x = y = 0; sl = 0;
        best = -INF;
        fr(i, 1, n) {
            one[1][i] = (a[1][i] == 1 ? one[1][i - 1] + 1 : one[1][i - 1]);
            zero[1][i] = (a[1][i] == 0 ? zero[1][i - 1] + 1 : zero[1][i - 1]);
        }
        fr(i, 2, m) {
            fr(j, 1, n) {
                one[i][j] = (a[i][j] == 1 ? one[i][j - 1] + 1 : one[i][j - 1]);
                zero[i][j] = (a[i][j] == 0 ? zero[i][j - 1] + 1 : zero[i][j - 1]);
            }
            fr(j, 1, n) {
                one[i][j] += one[i - 1][j];
                zero[i][j] += zero[i - 1][j];
            }
        }
        fr(i, 1, m) {
            fr(j, 1, n)
                cout<<one[i][j]<<" ";
                cout<<endl;
            }
        cout<<one[m][n]<<" "<<zero[m][n]<<endl;
        fr(r1, 1, m) fr(c1, 1, n)
            fr(r2, r1, m) fr(c2, c1, n) {
                x = get(one, r1, c1, r2, c2);
                y = get(zero, r1, c1, r2, c2);
                if (x - y > best) {
                    best = x - y;
                    sl = 1;
                }
                else
                if (x - y == best) sl++;
            }
        printf("%d %d\n", best, sl);
    }
}

