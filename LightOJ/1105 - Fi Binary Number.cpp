/***********************************************
* Author - LUONG VAN DO                        *
* 1105 - Fi Binary Number ->AC
* Algorithm Fibonaci
* Time Limit 0.916s
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
#define maxN 55

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int f[maxN], n;
int bit[maxN];
void init() {
    f[0] = 1; f[1] = 1;
    FOR(i, 2, 44)
        f[i] = f[i-1] + f[i-2];
}
void Call(int len, int n) {
    if (!n) return;
    FORD(i, len, 1)
        if (n>=f[i]) {
            n-=f[i];
            bit[i] = 1;
            Call(i - 2, n);
        }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, len;
    int64 x;
    init();
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        if (n == 1) {
            printf("Case %d: 1\n",t);
            continue;
        }
        len = 0; x = 1;
        while (f[len] <= n) len++;
        len--;
        FOR(i, 1, len) bit[i] = 0;
        Call(len, n);
        printf("Case %d: ",t);
        FORD(i, len, 1)
            printf("%d",bit[i]);
        printf("\n");
    }
    return 0;
}
