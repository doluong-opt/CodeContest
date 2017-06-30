/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1424 - New Land ->AC
* Algorithm Left - Right
* Time Limit 0.754s
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
#define M 2000

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
char s[M + 1][M + 1];
int a[M + 1][M + 1];
int f[M + 1][M + 1];
int Left[M + 1], Right[M + 1];
int Ans, n, m;
void Cal(int u){
    FOR(i, 1, n) {
        Left[i] = i - 1;
        while (f[u][i] && f[u][i] <= f[u][ Left[i] ]) Left[i] = Left[ Left[i] ];
    }
    FORD(i, n, 1) {
        Right[i] = i + 1;
        while (f[u][i] && f[u][i] <= f[u][ Right[i] ]) Right[i] = Right[ Right[i] ];
    }
    int S = 0, maxS;
    FOR(i, 1, n) {
        maxS = f[u][i] * (Right[i] - Left[i] - 1);
        S = max(S, maxS);
        Left[i] = Right[i] = 0;
    }
    Ans = max(Ans, S);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf(" %d %d ",&m,&n);
        REP(i, m) gets(s[i]);
        REP(i, m)
            REP(j, n) {
                a[i+1][j+1] = 1 - (s[i][j] - '0');
                f[i+1][j+1] = 0;
            }
            
        FOR(i, 1, n)
            FOR(j, 1, m)
                if ( a[j][i] ) f[j][i] = f[j-1][i] + 1;
        Ans = 0;
        FOR(i, 1, m) Cal( i );
        printf("Case %d: %d\n",t,Ans);
    }
}
