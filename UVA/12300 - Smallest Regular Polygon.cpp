/***********************************************
* Author - LUONG VAN DO                        *
* Problem 12300 - Smallest Regular Polygon ->AC
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
struct point{
    int x, y;
    point(){}
    point(int xx, int yy){
        x = xx; y = yy;
    }
};
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    point A, B;
    int n;
    double a, b, r, d;
    while ( scanf("%d %d %d %d %d",&A.x,&A.y,&B.x,&B.y,&n) ) {
        if (( A.x + B.x + A.y + B.y + n ) == 0) break;
        if (n & 1) {
            a = 2.0 * PI / (double)n;
            int m = n / 2;
            b = (double)(m * a * 0.5);
            d = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y)) * 0.5;
            r = d / sin(b);
            printf("%.6lf\n",(double)n * r * r * sin(a) * 0.5);
        }
        else {
            a = 2.0 * PI / (double)n;
            r = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y)) * 0.5;
            printf("%.6lf\n",(double)n * r * r * sin(a) * 0.5);
        }
    }
}
