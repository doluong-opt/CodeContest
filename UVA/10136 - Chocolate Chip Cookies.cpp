/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10136 - Chocolate Chip Cookies ->AC
* Algorithm Adhoc
* Time Limit 0.012s
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
#define M 210

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
}p[M];
bool circle_point2(Point p1, Point p2, double r, Point *c){
    double d = (p1.x - p2.x) * (p1.x - p2.x) + 
               (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c->x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c->y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
}
double dist(Point A, Point B){
    double dx = A.x - B.x;
    double dy = A.y - B.y;
    return sqrt(dx * dx + dy * dy);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, Ans, cnt;
    Point c;
    char s[M];
    scanf(" %d ",&cases);
    for (int t=1;t<=cases;t++) {
        n = 0;
        while ( gets(s) && strlen(s)) {
            sscanf(s," %lf %lf ",&p[n].x,&p[n].y);
            ++n;
        }
        Ans = 1;
        for (int i=0;i<n-1;i++)
            for (int j=i+1;j<n;j++) {
                if ( circle_point2(p[i], p[j], 2.5, &c) ){
                    cnt = 2;
                    for (int k=0;k<n;k++)
                        if ( k!=i && k!=j && dist(p[k],c)<=2.5)
                            cnt++;
                    Ans = max(Ans, cnt);
                }
            }
        if (t > 1) puts("");
        printf("%d\n",Ans);
    }
}
