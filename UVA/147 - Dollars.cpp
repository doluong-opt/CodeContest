/***********************************************
* Author - LUONG VAN DO                        *
* Problem 147 - Dollars ->AC
* Algorithm dp
* Time Limit 0.016s
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
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 30010

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
int a[12];
uint64 dp[N];
void init() {
    a[0] = 5; a[1] = 10; a[2] = 20; a[3] = 50;
    a[4] = 100; a[5] = 200; a[6] = 500; a[7] = 1000;
    a[8] = 2000; a[9] = 5000; a[10] = 10000;
    for (int i=0;i<N;i++) dp[i] = 0;
    dp[0] = 1;
    for (int i=0;i<11;i++)
        for (int j=a[i];j<N;j++)
            dp[j]+=dp[j-a[i]];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int m, a, b;
    init();
    while (scanf("%d.%d",&a,&b) && (a||b)) {
        m = a * 100 + b;
        printf("%3d.%.2d%17lld\n",a,b,dp[m]);
    }
}
