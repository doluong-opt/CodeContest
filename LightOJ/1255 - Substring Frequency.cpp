/***********************************************
* Author - LUONG VAN DO                        *
* 1255 - Substring Frequency ->AC
* Algorithm KMP
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
#define maxN 1000005

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, m;
char T[maxN], P[maxN];
int b[maxN];
void preKmp(){
    int i, j;
    i = 0; j = -1; b[0] = -1;
    while (i < m) {
        while (j>=0 && P[i]!=P[j]) j = b[j];
        ++i; ++j;
        b[i] = j;
    }
}
int Solve(){
    int i, j, res;
    i = j = res = 0;
    while (i < n) {
        while (j>=0 && T[i]!=P[j]) j = b[j];
        ++i; ++j;
        if (j == m) {
            res++;
            j = b[j];
        }
    }
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    scanf("%d ",&test);
    FOR(t, 1, test) {
        gets(T); n = strlen(T);
        gets(P); m = strlen(P);
        preKmp();
        printf("Case %d: %d\n",t,Solve());
    }
    return 0;
}
