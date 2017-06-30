/***********************************************
* Author - LUONG VAN DO                        *
* Problem 356 - Square Pegs And Round Holes ->AC
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
int cal(int x, int n){
    double r = double(n) - 0.5;
    int a = (int)floor(sqrt(r * r - double(x * x)));
    return 4 * a;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, r1, r2, blank = 0;
    while ( scanf("%d",&n) != EOF){
        r1 = 8 * n - 4; r2 = 0;
        if (!n) r1 = 0;
        for (int i=1;i<n;i++)
            r2+= cal(i, n);
        if ( blank ) puts("");
        blank = 1;
        printf("In the case n = %d, %d cells contain segments of the circle.\n",n, r1);
        printf("There are %d cells completely contained in the circle.\n",r2);
    }
}
