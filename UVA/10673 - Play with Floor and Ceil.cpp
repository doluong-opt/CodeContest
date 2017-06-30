/***********************************************
* Author - LUONG VAN DO                        *
* 10673 - Play with Floor ans Ceil ->AC
* Algorithm extended
* Time Limit 0.008s
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
int64 x, y, d;
void extended(int64 a, int64 b){
    if (b == 0) {
        x = 1; y = 0; d = a;
        return;
    }
    extended(b, a % b);
    int64 x1 = y;
    int64 y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    int64 xx, k, aa, bb;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%lld %lld",&xx,&k);
        aa = xx % k;
        if (!aa) {
            printf("0 %d\n",k);
            continue;
        }
        else {
            aa = xx / k;
            extended(aa, aa + 1);
            printf("%lld %lld\n",xx * x, xx * y);
        }
    }
    return 0;
}
