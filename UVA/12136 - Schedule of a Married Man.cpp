/***********************************************
* Author - LUONG VAN DO                        *
* 12136 - Schedule of a Married Man ->AC
* Algorithm Adhoc
* Time Limit 0.024s
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
#define maxN 50001
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, h1, m1, h2, m2;
    int h11, m11, h22, m22;
    int a[5];
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
        a[0] = h1 * 60 + m1;
        a[1] = h2 * 60 + m2;
        if (a[0] > a[1]) swap(a[0], a[1]);
        scanf("%d:%d %d:%d",&h11,&m11,&h22,&m22);
        a[2] = h11 * 60 + m11;
        a[3] = h22 * 60 + m22;
        if (a[2] > a[3]) swap(a[2], a[3]);
        if (a[2] > a[1] || a[3] < a[0]) printf("Case %d: Hits Meeting\n",t);
        else printf("Case %d: Mrs Meeting\n",t);
    }
    return 0;
}
