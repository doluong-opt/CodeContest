/***********************************************
* Author - LUONG VAN DO                        *
* 1012 - Guilty Prince ->AC
* Algorithm dfs
* Time Limit 0.003s
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
#define maxN 101

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int r,c,ans;
char s[maxN][maxN];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
bool Ok(int u, int v){
    return (u>=0 && v>=0 && u<r && v<c);
}
void dfs(int x, int y){
    int u,v;
    if ( s[x][y] == '#' ) return;
    s[x][y] = '#';
    ans++;
    for (int k=0;k<4;k++) {
        u = x + dx[k]; v = y + dy[k];
        if ( Ok(u,v) && s[u][v] == '.' ) dfs(u,v);
    }
}
void Read(){
    int test,ok,x,y;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        ok = 0; ans = 0;
        scanf("%d %d ",&c,&r);
        for (int i=0;i<r;i++) gets(s[i]);
        for (int i=0;i<r && !ok;i++)
            for (int j=0;j<c && !ok;j++)
                if (s[i][j]=='@') {
                    x = i;
                    y = j;
                    ok = 1;
                }
        dfs(x,y);
        printf("Case %d: %d\n",t,ans);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
