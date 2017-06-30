/***********************************************
* Author LUONG VAN DO                        *
* Problem 166 - Making Change
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
#define N 1010

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
int coins[] = {5, 10, 20, 50, 100, 200};
int a[6], d[N];
int run(int sum, int cur) {
    if (cur == 6) return INF;
    if (sum <= 0) return d[abs(sum)];
    if ( !a[cur] ) return run(sum, cur + 1);
    a[cur]--;
    int r1 = run(sum - coins[cur], cur);
    a[cur]++;
    int r2 = run(sum, cur + 1);
    return min(r1 + 1, r2);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int x, y, z;
    for (int i = 0;i < N;i++) d[i] = INF;
    d[0] = 0;
    for (int i = 0;i < 6;i++)
        for (int j = coins[i];j < N;j++)
            d[j] = min(d[j], d[j - coins[i]] + 1);
    while ( scanf("%d %d %d %d %d %d",&a[0], &a[1], &a[2], &a[3], &a[4], &a[5]) && (a[0] + a[1] + a[2] + a[3] + a[4] + a[5])) {
        scanf("%d.%d", &x, &y);
        z = x * 100 + y;
        printf("%3d\n",run(z, 0));
    }
}
