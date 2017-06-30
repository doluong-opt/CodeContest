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
#define N 100111
#define MAX_LOG 20
#define md (1000000000 + 7)
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
int n;
int64 sum[N], maxval, x, total, y, a[N];
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
    scanf("%d", &n);
    sum[0] = maxval = 0;
    for (int i = 1;i <= n;i++) {
        scanf("%lld", &a[i]);
        if (maxval < a[i]) maxval = a[i];
    }
    sort(a + 1, a + 1 + n);
    reverse(a + 1, a + n + 1);
    //for (int i = 1;i <= n;i++)
    //cout<<a[i]<<endl;
    for (int i = 1;i <= n;i++) {
        sum[i] = sum[i - 1] + a[i];
        sum[i] %= md;
    }
    
    total = 0;
    for (int i = 1;i <= n;i++) {
        x = (sum[n] - sum[i]) % md;
        y = ((n - i) * a[i]) - x;
        y %= md;
        total += y; 
        total %= md;
    }
    
    total = ((total % md) * (maxval % md)); total %= md;
    printf("%lld\n", total);
	return 0;
}
