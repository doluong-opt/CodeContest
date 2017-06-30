/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10167 - Birthday Cake ->AC
* Algorithm Adhoc
* Time Limit 0.108s
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
#define M 105

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
}P[M + 1];
int n;
bool check(int A, int B) {
    int diff;
    diff = 0;
    for (int i=0;i<(n<<1);i++) {
        int sign = P[i].x * A + P[i].y * B;
        if (sign > 0) diff--;
        else
        if (sign < 0) diff++;
        else return false;
    }
    return (diff == 0);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    bool found;
    while ( scanf("%d",&n) && n){
        for (int i=0;i<(n<<1);i++)
            scanf("%d %d",&P[i].x,&P[i].y);
            found = true;
        for (int i=-500;i<=500 && found;i++)
            for (int j=-500;j<=500;j++)
                if ( check(i, j) ) {
                    printf("%d %d\n",i,j);
                    found = false;
                    break;
                }
    }
}
