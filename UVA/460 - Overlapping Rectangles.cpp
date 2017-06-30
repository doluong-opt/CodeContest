/***********************************************
* Author - LUONG VAN DO                        *
* Problem 460 - Overlapping Rectangles ->AC
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
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, max1, max2, min1, min2;
    int x1l, y1l, x1r, y1r;
    int x2l, y2l, x2r, y2r;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d %d %d",&x1l,&y1l,&x1r,&y1r);
        scanf("%d %d %d %d",&x2l,&y2l,&x2r,&y2r);
        max1 = max(x1l, x2l);
        max2 = max(y1l, y2l);
        min1 = min(x1r, x2r);
        min2 = min(y1r, y2r);
        if (t > 1) puts("");
        if (max1>=min1 || max2>=min2) puts("No Overlap");
        else printf("%d %d %d %d\n",max1,max2,min1,min2);
    }
}
