/***********************************************
* Author - LUONG VAN DO                        *
* Problem 488 - Triangle Wave ->AC
* Algorithm Adhoc
* Time Limit 0.4s
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

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, m, cases, blank = 0;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%d %d",&n,&m);
        for (int i=0;i<m;i++) {
            if ( blank ) puts("");
            blank = 1;
            for (int i=1;i<=n;i++) {
                for (int j=1;j<=i;j++)
                    printf("%d",i);
                    printf("\n");
            }
            for (int i=n-1;i>=1;i--) {
                for (int j=1;j<=i;j++)
                    printf("%d",i);
                    printf("\n");
            }
        }
    }
}
