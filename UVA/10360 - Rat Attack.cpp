/***********************************************
* Author - LUONG VAN DO                        *
* 10360 - Rat Attack ->AC
* Algorithm Adhoc
* Time Limit 0.136s
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
#define maxN 1050

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n,d;
int m[maxN][maxN];
int xmax, ymax;
void reset(){
    for (int i=0;i<maxN;i++)
        for (int j=0;j<maxN;j++) m[i][j] = 0;
    ymax = xmax = 0;
}
void Read() {
    int test,x,y,cost;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d %d",&d,&n);
        reset();
        for (int i=1;i<=n;i++) {
            scanf("%d %d %d",&x,&y,&cost);
            m[++x][++y] = cost;
            xmax = max(xmax, x);
            ymax = max(ymax, y);
        }
        xmax++; ymax++;
        for (int i=1;i<ymax;i++) m[1][i]+=m[1][i-1];
        
        for (int i=2;i<xmax;i++) {
            
            for (int j=1;j<ymax;j++)
                m[i][j]+= m[i][j-1];
            
            for (int j=1;j<ymax;j++)
                m[i][j]+= m[i-1][j];
        }
        int r1,r2,ans;
        int x1,x2,y1,y2;
        ans = 0;
        for (int i=1;i<xmax;i++)
            for (int j=1;j<ymax;j++) {
                x1 = max(i - d, 1); y1 = max(j - d, 1);
                x2 = min(i + d, xmax-1); y2 = min(j + d, ymax-1);
                int sum = m[x2][y2] - m[x1-1][y2] - m[x2][y1-1] + m[x1-1][y1-1];
                if (sum > ans) ans = sum, r1 = i, r2 = j;
            }
        printf("%d %d %d\n",r1-1,r2-1,ans);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
