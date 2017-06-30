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
int x, y, k, b, a[N];
int64 c[35][35];
int64 calc(int x) {
    int n = 0, temp = k;
    int64 num = 1LL, ans = 0LL;
    while (num <= x) {
        n++;
        num *= b;
    }
    for (int i = 0;i < n;i++) {
        a[i] = x % b;
        x/=b;
    }
    reverse(a, a + n);
    for (int i = 0;i < n;i++) cout << a[i]<<" ";
    cout<<endl;
    for (int i = 0;i < n;i++) {
        if (temp < 0) break;
        if (temp == 0) {
            ans++;
            break;
        }
        if (a[i] == 0) continue;
        if (a[i] == 1) {
            ans += c[n - i - 1][temp];
            temp--;
        }
        else {
            ans += c[n - i][temp];
            break;
        }
    }
    return ans;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	for (int i = 0;i <= 32;i++) c[i][0] = 1;
	for (int i = 1;i <= 32;i++)
        for (int j = 1;j <= i;j++)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	scanf("%d %d %d %d", &x, &y, &k, &b);
	printf("%lld\n", calc(y) - calc(x - 1));
	return 0;
}
