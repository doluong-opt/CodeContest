/***********************************************
* Author - LUONG VAN DO                        *
* 1038 - Race to 1 Again ->AC
* Algorithm Probility
* Time Limit 0.022s
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
double dp[100010];
int Num[100010], n;
void initial(){
    int j, k;
    double x, y;
    FOR(i, 1, 100000) {
        j = i; k = 1;
        while (j * k <= 100000 ) {
            Num[j * k]++;
            ++k;
        }
    }
    dp[1] = 0.0;
    FOR(i, 2, 100000) dp[i] = 1.0 / Num[i];
    FOR(i, 2, 100000) {
        j = i; k = 2;
        x = 1.0 / Num[i];
        y = (Num[i] - 1.0) / Num[i];
        dp[i]+=x;
        dp[i]/=y;
        while ((int64)j * (int64)k <= 100000 ) {
            x = 1.0 / Num[j * k];
            y = 1.0 + dp[j];
            dp[j * k]+=(x * y);
            ++k;
        }        
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    initial();
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        printf("Case %d: %.10lf\n",t,dp[n]);
    }
    return 0;
}
