/***********************************************
* Author - LUONG VAN DO                        *
* Problem 866 - Intersecting Line Segments ->AC
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
struct Point{
    int x, y;
    Point(){}
    Point(int xx, int yy){
        x = xx; y = yy;
    }
};
Point A[M + 1], B[M + 1];
int cross(Point O, Point A, Point B){
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
bool intersection(Point A, Point B, Point C, Point D){
    int s1, s2, s3, s4;
    s1 = cross(A, C, D);
    s2 = cross(B, C, D);
    s3 = cross(C, A, B);
    s4 = cross(D, A, B);
    return (s1 * s2 < 0 && s3 * s4 < 0);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, Ans, n;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        Ans = n;
        FOR(i, 1, n) scanf("%d %d %d %d",&A[i].x,&A[i].y,&B[i].x,&B[i].y);
        FOR(i, 1, n - 1)
            FOR(j, i + 1, n)
                if ( intersection(A[i], B[i], A[j], B[j]) ) Ans+=2;
        if (t > 1) puts("");
        printf("%d\n",Ans);
    }
}
