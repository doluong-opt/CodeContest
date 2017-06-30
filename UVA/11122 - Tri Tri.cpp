/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11122 - Tri Tri
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
    int64 x, y;
    point(){}
    point(int64 xx, int64 yy){
        x = xx; y = yy;
    }
};
int64 area(point a, point b, point c){
    int64 s = (int64)(a.x - b.x) * (int64)(a.y + b.y);
    s += (int64)(b.x - c.x) * (int64)(b.y + c.y);
    s += (int64)(c.x - a.x) * (int64)(c.y + a.y);
    return (s > 0) ? s : -s;
}
bool check(point x, point a, point b, point c){
    int64 s0 = area(a, b, c);
    int64 d1 = area(x, a, b);
    int64 d2 = area(x, b, c);
    int64 d3 = area(x, c, a);
    return (s0 == (d1 + d2 + d3));
}
int64 cross(point o, point a, point b){
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
bool inter(point a, point b, point c, point d){
    int64 s1 = cross(a, c, d);
    int64 s2 = cross(b, c, d);
    int64 s3 = cross(c, a, b);
    int64 s4 = cross(d, a, b);
    return (s1 * s2 < 0 && s3 * s4 < 0);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases;
    point A, B, C, D, E, F;
    scanf("%d",&cases);
    for (int i=1;i<=cases;i++) {
        scanf("%lld %lld %lld %lld %lld %lld",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
        scanf("%lld %lld %lld %lld %lld %lld",&D.x,&D.y,&E.x,&E.y,&F.x,&F.y);
        printf("pair %d: ",i);
        if ( check(A, D, E, F) && check(B, D, E, F) && check(C, D, E, F) ) puts("yes");
        else
        if ( check(D, A, B, C) && check(E, A, B, C) && check(F, A, B, C) ) puts("yes");
        else
        if ( inter(A, B, D, E) ) puts("yes");
        else
        if ( inter(A, B, E, F) ) puts("yes");
        else
        if ( inter(A, B, F, D) ) puts("yes");
        else
        if ( inter(B, C, D, E) ) puts("yes");
        else
        if ( inter(B, C, E, F) ) puts("yes");
        else
        if ( inter(B, C, F, D) ) puts("yes");
        else
        if ( inter(C, A, D, E) ) puts("yes");
        else
        if ( inter(C, A, E, F) ) puts("yes");
        else
        if ( inter(C, A, F, D) ) puts("yes");
        else
        if ( !cross(A, D, E) && (!cross(B, E, F) || !cross(B, F, D)) ) puts("yes");
        else
        if ( !cross(A, E, F) && (!cross(B, D, E) || !cross(B, F, D)) ) puts("yes");
        else
        if ( !cross(A, F, D) && (!cross(B, D, E) || !cross(B, E, F)) ) puts("yes");
        else
        if ( !cross(A, D, E) && (!cross(C, E, F) || !cross(C, F, D)) ) puts("yes");
        else
        if ( !cross(A, E, F) && (!cross(C, D, E) || !cross(C, F, D)) ) puts("yes");
        else
        if ( !cross(A, F, D) && (!cross(C, D, E) || !cross(C, E, F)) ) puts("yes");
        else
        if ( !cross(B, D, E) && (!cross(A, E, F) || !cross(A, F, D)) ) puts("yes");
        else
        if ( !cross(B, E, F) && (!cross(A, D, E) || !cross(A, F, D)) ) puts("yes");
        else
        if ( !cross(B, F, D) && (!cross(A, D, E) || !cross(A, E, F)) ) puts("yes");
        else
        if ( !cross(B, D, E) && (!cross(C, E, F) || !cross(C, F, D)) ) puts("yes");
        else
        if ( !cross(B, E, F) && (!cross(C, D, E) || !cross(C, F, D)) ) puts("yes");
        else
        if ( !cross(B, F, D) && (!cross(C, D, E) || !cross(C, E, F)) ) puts("yes");
        else
        if ( !cross(C, D, E) && (!cross(B, E, F) || !cross(B, F, D)) ) puts("yes");
        else
        if ( !cross(C, E, F) && (!cross(B, D, E) || !cross(B, F, D)) ) puts("yes");
        else
        if ( !cross(C, F, D) && (!cross(B, D, E) || !cross(B, E, F)) ) puts("yes");
        else
        if ( !cross(C, D, E) && (!cross(A, E, F) || !cross(A, F, D)) ) puts("yes");
        else
        if ( !cross(C, E, F) && (!cross(A, D, E) || !cross(A, F, D)) ) puts("yes");
        else
        if ( !cross(C, F, D) && (!cross(A, D, E) || !cross(A, E, F)) ) puts("yes");
        
        else
        if ( !cross(D, A, B) && (!cross(E, B, C) || !cross(E, C, A)) ) puts("yes");
        else
        if ( !cross(D, B, C) && (!cross(E, A, B) || !cross(E, C, A)) ) puts("yes");
        else
        if ( !cross(D, C, A) && (!cross(E, A, B) || !cross(E, B, C)) ) puts("yes");
        else
        if ( !cross(D, A, B) && (!cross(F, B, C) || !cross(F, C, A)) ) puts("yes");
        else
        if ( !cross(D, B, C) && (!cross(F, A, B) || !cross(F, C, A)) ) puts("yes");
        else
        if ( !cross(D, C, A) && (!cross(F, A, B) || !cross(F, B, C)) ) puts("yes");
        else
        if ( !cross(E, A, B) && (!cross(D, B, C) || !cross(D, C, A)) ) puts("yes");
        else
        if ( !cross(E, B, C) && (!cross(D, A, B) || !cross(D, C, A)) ) puts("yes");
        else
        if ( !cross(E, C, A) && (!cross(D, A, B) || !cross(D, B, C)) ) puts("yes");
        else
        if ( !cross(E, A, B) && (!cross(F, B, C) || !cross(F, C, A)) ) puts("yes");
        else
        if ( !cross(E, B, C) && (!cross(F, A, B) || !cross(F, C, A)) ) puts("yes");
        else
        if ( !cross(E, C, A) && (!cross(F, A, B) || !cross(F, B, C)) ) puts("yes");
        else
        if ( !cross(F, A, B) && (!cross(D, B, C) || !cross(D, C, A)) ) puts("yes");
        else
        if ( !cross(F, B, C) && (!cross(D, A, B) || !cross(D, C, A)) ) puts("yes");
        else
        if ( !cross(F, C, A) && (!cross(D, A, B) || !cross(D, B, C)) ) puts("yes");
        else
        if ( !cross(F, A, B) && (!cross(E, B, C) || !cross(E, C, A)) ) puts("yes");
        else
        if ( !cross(F, B, C) && (!cross(E, A, B) || !cross(E, C, A)) ) puts("yes");
        else
        if ( !cross(F, C, A) && (!cross(E, A, B) || !cross(E, B, C)) ) puts("yes");
        else puts("no");
    }
}
