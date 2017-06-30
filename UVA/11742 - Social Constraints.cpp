/***********************************************
* Author - LUONG VAN DO                        *
* 11742 - Social Constraints ->AC
* Algorithm Adhoc
* Time Limit 0.124s
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
#define maxN 102
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int x[maxN], y[maxN], c[maxN];
int a[maxN], n, m;
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int ans, xmin, xmax;
    while ( scanf("%d %d",&n,&m) && (n + m)){
        REP(i, n) a[i] = i;
        REP(i, m) {
            scanf("%d %d %d",&x[i], &y[i], &c[i]);
            xmin = min(x[i], y[i]);
            xmax = max(x[i], y[i]);
            x[i] = xmin; y[i] = xmax;
        }
        ans = 0;
        do{
            bool found = true;
            REP(i, n)
                FOR(j, i, n - 1) {
                    int nx, ny;
                    nx = a[i];
                    ny = a[j];
                    if (nx > ny) swap(nx, ny);
                    REP(k, m)
                        if (nx == x[k] && ny == y[k]) {
                            if ( c[k] < 0 ) {
                                if ( -c[k] > j - i) found = false;
                            }
                            else
                                if ( c[k] < j - i) found = false;
                        }
                }
            if (found) ans++;
        } while ( next_permutation(a, a + n) );
        printf("%d\n",ans);
    }
    return 0;
}
