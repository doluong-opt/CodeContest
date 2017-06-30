/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11648 - Divide The Land
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
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 100000

#define eps 1e-6
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
    int cases, caseno = 0;
    double ab, cd, ad, bc;
    double a, b, c, p, s_tri, h, s_tra;
    double dx, dy, h_s, x, y, lo, hi, area, l, xx, yy;
    double alpha, ea, fb;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%lf %lf %lf %lf",&ab,&cd,&ad,&bc);
        a = ad;
        b = bc;
        c = (ab - cd);
        p = (a + b + c) / 2.0;
        s_tri = sqrt(p * (p - a) * (p - b) * (p - c));
        
        h = (2.0 * s_tri) / c;
        
        s_tra = ((ab + cd) * h) / 2.0;
        s_tra/=2.0;
        alpha = h / ad;
        
        lo = cd; hi = ab;
        
        for (int i=0;i<=50;i++) {
            l = (lo + hi) / 2.0;
            h_s = (2.0 * s_tra) / (l + ab);
            ea = (h_s * ad) / h;
            fb = (h_s * bc) / h;
            cout<<ea<<" "<<fb<<endl;
        }
        printf("Land #%d: %.6lf %.6lf\n",++caseno, xx, yy);
    }
}
