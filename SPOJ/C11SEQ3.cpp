/***********************************************
* Author - LUONG VAN DO *
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
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 101000
 
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
int f[N], n;
int solve(int x) {
    int a[N], m = 0;
    while ( x ) {
        a[m++] = (x % 10);
        x/=10;
    }
    reverse(a, a + m);
    sort(a, a + m);
    int v = 0;
    rep(i, m)
        v = v * 10 + a[i];
    return v;
}
int main() {
    //freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
    f[1] = 1;
    for (int i = 2;i <= 24;i++) {
        f[i] = f[i - 1] * 2;
        f[i] = solve(f[i]);
    }
    scanf("%d", &n);
    if (n <= 24) {
        printf("%d\n", f[n]);
        return 0;
    }
    if (n == 25) {
        printf("48889\n");
        return 0;
    }
    if (n == 26) {
        printf("77789\n");
        return 0;
    }
    if (n == 27) {
        printf("155578\n");
        return 0;
    }
    if (n == 28) {
        printf("111356\n");
        return 0;
    }
    if (n == 29) {
        printf("122227\n");
        return 0;
    }
    if (n == 30) {
        printf("244445\n");
        return 0;
    }
    if ((n - 25) % 6 == 0) {
        printf("48889\n");
        return 0;
    }
    if ((n - 26) % 6 == 0) {
        printf("77789\n");
        return 0;
    }
    if ((n - 27) % 6 == 0) {
        printf("155578\n");
        return 0;
    }
    if ((n - 28) % 6 == 0) {
        printf("111356\n");
        return 0;
    }
    if ((n - 29) % 6 == 0) {
        printf("122227\n");
        return 0;
    }
    if ((n - 30) % 6 == 0) {
        printf("244445\n");
        return 0;
    }
}
