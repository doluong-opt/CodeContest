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
#define INF 10000000000000000LL
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
vector <int64> val;
int k, n, m, local;
int a[N], b[N], pos[N];
int64 ans[N], best;
/*bool isOk(int x) {
    if (x == 2 || x == 3) return true;
    for (int j = 2;j * j <= x;j++)
        if (x % j == 0) return false;
    return true;
}*/
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	/*int cnt = 0;
	for (int i = 2;i <= 10000;i++)
        if ( isOk(i)) {
            cnt++;
            cout<<i<<" ";
            if (cnt == 100) break;
        }
        cout<<endl;
    */
    scanf("%d %d", &k, &n);
    for (int i = 0;i < k;i++) scanf("%d", &a[i]);
    sort(a, a + k);
    b[0] = a[0]; m = 1;
    for (int i = 1;i < k;i++) {
        if (a[i] == a[i - 1]) continue;
        b[m++] = a[i];
    }
    ans[0] = 1; fill(pos, 0);
    for (int i = 1;i <= n;i++) {
        best = INF;
        do {
            for (int j = 0;j < m;j++)
                if (b[j] * ans[pos[j]] < best) {
                    best = b[j] * ans[pos[j]];
                    local = j;
                }
            if ( best < INF && best > ans[i - 1] ) break;
            if ( pos[local] > i ) break;
            if ( best <= ans[i - 1] ) best = INF;
            pos[local]++;
        }while ( true );
        ans[i] = best;
        pos[local]++;
    }
    printf("%lld\n", ans[n]);
	return 0;
}
