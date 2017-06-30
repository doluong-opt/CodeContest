
/***********************************************
* Author - LUONG VAN DO                        *
* 1083 - Histogram ->AC
* Algorithm left - right
* Time Limit 0.075s
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
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 30005
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, a[maxN];
int Left[maxN], Right[maxN];
int solve(){
    int res = -INF;
    REP(i, n + 1) Left[i] = Right[i] = 0;
    FOR(i, 1, n) {
        Left[i] = i - 1;
        while (Left[i]>=1 && a[i] <= a[ Left[i] ] ) Left[i] = Left[ Left[i] ];
    }
    FORD(i, n, 1) {
        Right[i] = i + 1;
        while (Right[i]<=n && a[i] <= a[ Right[i] ] ) Right[i] = Right[ Right[i] ];
    }
    
    FOR(i, 1, n)
        res = max(res, (Right[i] - Left[i] - 1) * a[i]);
    return res;
}
void Read_Input(){
    int test;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d",&n);
        FOR(i, 1, n) scanf("%d",&a[i]);
        printf("Case %d: %d\n",t,solve());
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}
