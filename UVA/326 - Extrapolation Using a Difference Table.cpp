/***********************************************
* Author - LUONG VAN DO                        *
* Problem 326 - Extrapolation Using a Difference Table ->AC
* Algorithm Adhoc
* Time Limit 0.008s
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
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define M 100000

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
int n, k, nm;
int Ans[M + 1], a[M + 1];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    while ( scanf("%d",&n) && n){
        REP(i, n) scanf("%d",&a[i]);
        scanf("%d",&k);
        Ans[0] = a[n - 1];
        nm = 1;
        REP(i, n - 1) {
            for (int j=n - 1; j > i;j--)
                a[j] = a[j] - a[j - 1];
            Ans[nm++] = a[n - 1];
        }
        for (int i=0;i<k;i++)
            for (int j=nm-2;j>=0;j--)
                Ans[j] = Ans[j] + Ans[j + 1];
        printf("Term %d of the sequence is %d\n",n + k, Ans[0]);
    }
}
