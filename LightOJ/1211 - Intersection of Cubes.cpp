/***********************************************
* Author - LUONG VAN DO                        *
* 1211 - Intersection of Cubes ->AC 
* Algorithm math
* Time Limit 0.007s
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

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int a[maxN][7];
int X1,Y1,Z1;
int X2,Y2,Z2;
void Read() {
    int test,A,B,C,n;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=6;j++)
                scanf("%d",&a[i][j]);
        X1 = Y1 = Z1 = -INF;
        X2 = Y2 = Z2 = INF;
        for (int i=1;i<=n;i++) {
            X1 = max(X1, a[i][1] );
            Y1 = max(Y1, a[i][2] );
            Z1 = max(Z1, a[i][3] );
            X2 = min(X2, a[i][4] );
            Y2 = min(Y2, a[i][5] );
            Z2 = min(Z2, a[i][6] );
        }
        A = X2 - X1; B = Y2 - Y1; C = Z2 - Z1;
        int ans = A * B * C;
        if ( ans <= 0 ) printf("Case %d: 0\n",t);
        else printf("Case %d: %d\n",t, ans);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
