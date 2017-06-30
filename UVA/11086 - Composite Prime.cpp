/***********************************************
* Author - LUONG VAN DO                        *
* 11086 - Composite Prime ->AC
* Algorithm prime
* Time Limit 0.324s
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
#define maxN 1048577
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int color[maxN];
int idx[maxN + 5];
void sieve() {
    for (int i=1;i<maxN;i++) color[i] = 1;
    color[1] = 0; color[0] = 0;
    for (int i=4;i<maxN;i+=2) color[i] = 0;
    for (int i=3;i*i<maxN;i+=2)
        if (color[i])
            for (int j=i*i;j<maxN;j+=2*i) color[j] = 0;
}
void init() {
    int64 j, k;
    FOR(i, 1, maxN - 1) idx[i] = 0;
    for (int i=2;i<maxN;i++) {
        j = i; k = 1;
        while (j * k <= 1048576) {
            if (color[j] && color[k]) idx[j * k] = 1;
            ++k;
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    sieve();
    init();
    int n, ans, x;
    while ( scanf("%d",&n)!=EOF) {
        ans = 0;
        REP(i, n) {
            scanf("%d",&x);
            if ( idx[x] ) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
