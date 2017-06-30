/***********************************************
* Author - LUONG VAN DO                        *
* 11242 - Tour de France ->AC
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
#define maxN 101
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int ff[maxN], rr[maxN];
double d[maxN * maxN];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int f, r, l;
    double ans;
    while ( scanf("%d",&f) && f){
        scanf("%d",&r);
        REP(i, f) scanf("%d",&ff[i]);
        REP(i, r) scanf("%d",&rr[i]);
        l = 0;
        REP(i, f)
            REP(j, r)
                d[l++] = double(rr[j]) / double(ff[i]);
        sort(d, d + l);
        ans = -1.0;
        REP(i, l - 1)
            ans = max(ans, d[i+1] / d[i]);
        printf("%.2lf\n",ans);
    }
    return 0;
}
