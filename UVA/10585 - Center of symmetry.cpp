/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10585 - Center of symmetry ->AC
* Algorithm Adhoc
* Time Limit 0.124s
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
}p[M];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, x, y;
    Point pivot;
    scanf("%d",&cases);
    for (int t=1;t<=cases;t++) {
        scanf("%d",&n);
        pivot = Point(0, 0);
        for (int i=0;i<n;i++) {
            scanf("%d %d",&p[i].x,&p[i].y);
            pivot.x+=p[i].x;
            pivot.y+=p[i].y;
        }
        if (n == 1) puts("yes");
        else
        if (pivot.x % n || pivot.y % n) puts("no");
        else {
            pivot.x/=n; pivot.y/=n;
            bool found = true;
            for (int i=0;i<n;i++) {
                x = 2 * pivot.x - p[i].x;
                y = 2 * pivot.y - p[i].y;
                found = true;
                for (int j=0;j<n;j++)
                    if (x == p[j].x && y == p[j].y) {
                        found = false;
                        break;
                    }
                if ( found ) {
                    puts("no");
                    break;
                }
            }
            if ( !found ) puts("yes");
        }
    }
}
