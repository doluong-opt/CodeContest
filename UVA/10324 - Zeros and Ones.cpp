/***********************************************
* Author - LUONG VAN DO                        *
* 10324 - Zeros and Ones ->AC
* Algorithm Adhoc
* Time Limit 0.036s
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
#define maxN 1000005
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    char s[maxN];
    int x, y, n, Case = 0;
    int sum[maxN], q, d;
    while ( gets(s) ) {
        n = strlen(s);
        sum[1] = s[0] - '0';
        FOR(i, 1, n - 1)
            sum[i + 1] = sum[i] + s[i] - '0';
        printf("Case %d:\n",++Case);
        scanf(" %d ",&q);
        REP(i, q) {
            scanf(" %d %d ",&x,&y);
            ++x; ++y;
            if (x > y) swap(x, y);
            d = sum[y] - sum[x - 1];
            if (d == 0 || d == y - x + 1) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
