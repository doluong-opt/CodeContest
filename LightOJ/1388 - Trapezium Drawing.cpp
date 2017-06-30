/***********************************************
* Author - LUONG VAN DO                        *
* Problem 
* Algorithm
* Time Limit
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
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 100111

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
double ax, ay, bx, by, aa, bb, cc;
double b, c, d, dis, x, y, cx, cy, dx, dy;
double p, s, h, tempX;
double calpha, salpha;
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, caseno = 0;
	scanf("%d", &cases);
	while (cases--) {
	    scanf("%lf %lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &b, &c, &d);
	    x = bx - ax; y = by - ay;
	    dis = sqrt(x * x + y * y);
	    calpha = x / dis; salpha = y / dis;
	    aa = b; bb = d; cc = dis - c;
	    p = (aa + bb + cc) * 0.5;
	    s = sqrt(p * (p - aa) * (p - bb) * (p - cc));
	    h = (2 * s) / cc;	    
	    tempX = sqrt(bb * bb - h * h);	    
	    if (aa * aa > bb * bb + cc * cc) tempX = -tempX; // goc tu DAB
	    tempX += c;
	    cx = tempX * calpha - h * salpha;
	    cy = tempX * salpha + h * calpha;
	    tempX -= c;
	    dx = tempX * calpha - h * salpha;
	    dy = tempX * salpha + h * calpha;
	    printf("Case %d:\n", ++caseno);
        printf("%.10lf %.10lf %.10lf %.10lf\n", cx + ax, cy + ay, dx + ax, dy + ay);
	}
	return 0;
}
