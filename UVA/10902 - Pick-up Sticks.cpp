/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10902 - Pick-up Sticks ->AC
* Algorithm Adhoc
* Time Limit 0.144s
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
    double x, y;
    Point(){}
    Point(double xx, double yy){
        x = xx; y = yy;
    }
};
struct Sticks{
    int id;
    Point a, b;
};
list <Sticks> L;
list <Sticks> :: iterator it, tmp;
double cross(Point O, Point A, Point B){
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
bool check(Point A, Point B, Point C, Point D) {
    double s1, s2, s3, s4;
    s1 = cross(A, C, D);
    s2 = cross(B, C, D);
    s3 = cross(C, A, B);
    s4 = cross(D, A, B);
    return (s1 * s2 < 0.0 && s3 * s4 < 0.0);
}
bool intersection(Point A, Point B, Point C, Point D) {
    double x1, y1, x2, y2;
    double a1, b1, c1;
    double a2, b2, c2;
    double dx, dy, d;
    x1 = B.x - A.x;
    y1 = B.y - A.y;
    a1 = y1; b1 = -x1; c1 = -y1 * A.x + x1 * A.y;
    
    x2 = D.x - C.x;
    y2 = D.y - C.y;
    a2 = y2; b2 = -x2; c2 = -y2 * C.x + x2 * C.y;
    
    d = a1 * b2 - a2 * b1;
    dx = b1 * c2 - b2 * c1;
    dy = a2 * c1 - a1 * c2;
    return (d!=0 &&  check(A, B, C, D));
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, blank;
    Sticks S;
//    cout<<cross(Point(0,0), Point(0, 2), Point(2, 2))<<endl;
//    cout<<cross(Point(0,0), Point(0, 2), Point(-2, 2))<<endl;
    while ( scanf("%d",&n) && n) {
        L.clear(); blank = 1;
        FOR(i, 1, n) {
            scanf("%lf %lf %lf %lf",&S.a.x,&S.a.y,&S.b.x,&S.b.y);
            S.id = i;
            it = L.begin();
            while (it!=L.end()) {
                if ( intersection(it->a,it->b,S.a,S.b) ) {
                    tmp = it;
                    ++it;
                    L.erase(tmp);
                    continue;
                }
                else it++;
            }
            L.pb( S );
        }
        printf("Top sticks:");
        for (it=L.begin(); it!=L.end(); ++it) {
            if ( blank ) blank = 0;
            else printf(",");
            printf(" %d",it->id);
        }
        printf(".\n");
    }
}
