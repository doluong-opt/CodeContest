/***********************************************
* Author - LUONG VAN DO                        *
* 1234 - Harmonic Number  ->AC
* Algorithm math
* Time Limit 0.011s
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
#define maxN 10001
#define EM 0.5772156649015328606065120900824
using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
double ans[maxN];
void init() {
    ans[1] = 1.0;
    for (int i=2;i<=10000;i++)
        ans[i] = (ans[i-1] + 1 / double(i));
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, n;
    init();
    double res;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        if (n<=10000) {
            printf("Case %d: %.10lf\n",t,ans[n]);
            continue;
        }
        res = log(n) + EM + double(1.0 / (double)(2*n + 1));
        printf("Case %d: %.10lf\n",t,res);
    }
    return 0;
}
