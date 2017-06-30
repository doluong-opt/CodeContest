/***********************************************
* Author - LUONG VAN DO                        *
* 106 - Fermat vs. Pythagoras ->AC
* Algorithm Adhoc
* Time Limit 0.96s
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
int color[maxN];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, r1, r2;
    int a, b, c;
    while ( scanf("%d",&n)!=EOF ) {
        r1 = r2 = 0;
        for (int i=1;i<=1000000;i++)
            color[i] = 0;
        for (int i=1;i<1000;i++)
            for (int j=i+1;j<1000;j+=2) {
                if ( gcd(i, j) > 1 ) continue;
                c = i * i + j * j;
                if (c > n) break;
                r1++;
                for (int k=0;k<n;k++) {
                    if (c * k > n) break;
                    color[k * (i * i + j * j)] = 1;
                    color[k * (j * j - i * i)] = 1;
                    color[k * (2 * i * j)] = 1;
                }
            }
        FOR(i, 1, n)
            if (color[i]) r2++;
        printf("%d %d\n",r1, n - r2);
    }
    return 0;
}
