/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10112 - Myacm Triangles ->AC
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
    char labels;
    int x, y;
    point(){}
    point(char la, int xx, int yy){
        labels = la; x = xx; y = yy;
    }
};
point p[16];
int area(point o, point a, point b){
    int s = (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
    return abs(s);
}
bool inside(point x, point a, point b, point c){
    int s0 = area(a, b, c);
    int s1 = area(x, a, b);
    int s2 = area(x, b, c);
    int s3 = area(x, c, a);
    return (s0 == (s1 + s2 +s3));
}
bool check(int n, int i, int j, int k){
    for (int i1=0;i1<n;i1++)
        if (i!=i1 && j!=i1 && k!=i1 && inside(p[i1], p[i], p[j], p[k])) return false;
    return true;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, s;
    char a, b, c;
    while ( scanf(" %d ",&n) && n) {
        s = -INF;
        for (int i=0;i<n;i++) scanf(" %c %d %d ",&p[i].labels,&p[i].x,&p[i].y);
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)
                for (int k=j+1;k<n;k++) {
                    int s0 = area(p[i], p[j], p[k]);
                    if ( s0 > s && check(n, i, j, k) ) {
                        s = s0;
                        a = p[i].labels;
                        b = p[j].labels;
                        c = p[k].labels;
                    }
                }
        printf("%c%c%c\n",a,b,c);
    }
}
