/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1421 - Wavio Sequence ->AC
* Algorithm dp
* Time Limit 0.326s
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
#define M 100005

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int rs1[M + 1], rs2[M + 1];
int a[M + 1], b[M + 1];
void Cal(int a[], int n, int cur[]) {
    int u, v, m;
    int t[M + 1];
    t[1] = m = cur[1] = 1;
    for (int i=2;i<=n;i++) {
        if (a[i] > a[t[m]]) {
            t[++m] = i;
            cur[i] = m;
            continue;
        }
        
        for (u = 1, v = m; u < v;) {
            int c = (u + v) >> 1;
            if (a[i] > a[t[c]]) u = c + 1;
            else v = c;
        }
        
        if (a[i] < a[t[u]]) {
            t[u] = i;
            cur[i] = u;
        }
        else cur[i] = m;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, Ans, n;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        FOR(i, 1, n) {
            scanf("%d",&a[i]);
            b[n-i+1] = a[i];
        }
        Cal(a, n, rs1);
        Cal(b, n, rs2);
        Ans = 1;
        FOR(i, 1, n)
            Ans = max(Ans, min(rs1[i] - 1, rs2[n - i + 1] - 1) * 2 + 1);
        printf("Case %d: %d\n",t,Ans);
    }
}
