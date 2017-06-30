/***********************************************
* Author - LUONG VAN DO                        *
* 906 - Rational Neighbor ->AC
* Algorithm Adhoc
* Time Limit 0.048s
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

#define eps 1e-15
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int64 gcd(int64 a, int64 b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int64 p, q, d, m0, x, y;
    double a, b, n, xx, yy;
    while ( scanf("%lf %lf",&a,&b)!=EOF ){
        scanf("%lf",&n);
        x = y = 1;  xx = a / b;
        while ( true ) {
            yy = double(x) / (double)(y);
            if (yy > xx && yy - xx - n <= eps) break;
            if (yy < xx) x++;
            else
            if (yy > xx) y++;
            else x++;
        }
        printf("%lld %lld\n",x, y);
    }
    return 0;
}
