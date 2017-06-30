/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1410 - Consistent Verdicts ->AC
* Algorithm Adhoc
* Time Limit 2.481
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
#define M 700

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct point{
    int x, y;
    point(){}
    point(int xx, int yy){
        x = xx; y = yy;
    }
}p[M + 1];
int Num[M * M + 1], m;
int dist(point p1, point p2){
    int dx, dy;
    dx = p1.x - p2.x;
    dy = p1.y - p2.y;
    return dx * dx + dy * dy;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, n, Ans;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        FOR(i, 1, n) scanf("%d %d",&p[i].x,&p[i].y);
        m = 0;
        FOR(i, 1, n - 1)
            FOR(j, i + 1, n)
                Num[++m] = dist(p[i], p[j]);
        sort(Num + 1, Num + m + 1);
        Ans = 0;
        Num[0] = -1;
        FOR(i, 1, m)
            if (Num[i]!=Num[i-1]) Ans++;
        printf("Case %d: %d\n",t,Ans + 1);
    }
}
