/***********************************************
* Author - LUONG VAN DO                        *
* 1032 - Fast Bit Calculations ->AC
* Algorithm dp
* Time Limit 0.013s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
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
#define maxN 50001
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int64 f[maxN];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0, n, m, len;
    int64 res, temp;
    scanf("%d",&cases);
    f[0] = f[1] = 0;
    for (int i = 2;i < 32;i++) f[i] = (f[i - 1] << 1) + (1LL << (i - 2));
    
    while ( cases--) {
        scanf("%d",&n);
        res = 0;
        for (len = 0, m = n; m > 0; len++, m >>= 1);
        for (; len > 1; len--) {
            if ( n & (1LL << (len - 1) ) ) {
                res+=f[len - 1];
                temp = (1LL << (len - 1)) + (1LL << (len - 2));
                if ( temp <= n ) res+=(n - temp + 1);
                n-=(1LL << (len - 1));
            }
        }
        printf("Case %d: %lld\n", ++caseno, res);
    }
    return 0;
}
