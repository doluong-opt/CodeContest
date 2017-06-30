/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11834 - Elevator ->AC
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

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int R1, R2, C, L; 
    double x, y;
    int a[5], flag;
    while ( scanf("%d %d %d %d",&L,&C,&R1,&R2) && (L + C + R1 + R2)) {
        a[0] = 2 * R1;
        a[1] = R1 + R2;
        a[2] = 2 * R2;
        flag = 1;
        for (int i=0;i<3;i++)
            if ( L < a[i] || C < a[i] ) flag = 0;
        if (!flag) puts("N");
        else {
            x = L - a[1]; y = C - a[1];
            if ( x * x + y * y >= a[1] * a[1] ) puts("S");
            else puts("N");
        }
    }
}
