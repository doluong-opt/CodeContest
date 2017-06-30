/***********************************************
* Author - LUONG VAN DO                        *
* Problem B. Before an Exam ->AC
* Algorithm Adhoc
* Time Limit 30ms
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
#define M 100010

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
struct point{
    int x, y;
    point(){}
    point(int xx, int yy){
        x = xx; y = yy;
    }
};
point p[M];
int sum[M];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, m, diff;
    int sa, sb;
    sa = sb = 0;
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++) {
        scanf("%d %d",&p[i].x,&p[i].y);
        sa+=p[i].x;
        sb+=p[i].y;
    }
    if (sa<=m && m<=sb) {
        puts("YES");
        diff = m - sa;
        for (int i=1;i<=n;i++) {
            if (p[i].y - p[i].x <= diff) {
                diff-=(p[i].y - p[i].x);
                if (i > 1) printf(" ");
                printf("%d",p[i].y);
            }
            else {
                if (i > 1) printf(" ");
                printf("%d",p[i].x + diff);
                diff = 0;
            }
        }
    }
    else puts("NO");
}
