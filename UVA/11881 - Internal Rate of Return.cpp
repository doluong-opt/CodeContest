/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11881 - Internal Rate of Return ->AC
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

#define eps 1e-5
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
int c[M + 1];
int t;
double cal(double x){
    x = 1.0 + x;
    double k = x;
    double Ans = 0.0;
    for (int i=1;i<=t;i++) {
        Ans+=((double)c[i] / k);
        k*=x;
    }
    return Ans + (double)c[0];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cnt;
    double Left, Right, Ans;
    while ( scanf("%d",&t) && t){
        cnt = 0;
        REP(i, t + 1) {
            scanf("%d",&c[i]);
            if (!c[i]) cnt++;
        }
        if (cnt == t + 1) {
            printf("Too many\n");
            continue;
        }
        Left = -1.0 + eps; Right = INF;
        for (int i=0;i<=1000;i++) {
        //while (Right - Left > eps ){
            double mid = (Left + Right) / 2.0;
            double d = cal(mid);
            if (fabs(d) <= eps) Ans = mid;
            else
            if (d < 0) Right = mid;
            else Left = mid;
        }
        if (fabs(Ans + 1) <= eps) printf("No\n");
        else printf("%.2lf\n",Ans + eps);
    }
}
