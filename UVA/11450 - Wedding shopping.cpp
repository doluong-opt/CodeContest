/***********************************************
* Author - LUONG VAN DO                        *
* 11450 - Wedding shopping ->AC
* Algorithm dp
* Time Limit 0.012s
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
#define For(i, a, b) for (int i=a; i<=b; i++)
#define Ford(i,a,b) for (int i=a;i>=b;i--)
#define Rep(i, n) for (int i=0; i<n; i++)
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
vector<int> vi[maxN];
int money, garment, ans;
bool visit[maxN][205];
void dp(int i, int sum){
    if (sum > money) return;
    if (i == garment)
    if (sum > ans) {
        ans = sum;
        return;
    }
    if ( visit[i][sum] ) return;
    visit[i][sum] = true;
    for (int j=0;j<vi[i].size();j++)
        dp(i+1, sum + vi[i][j]);
}
void Read_Input(){
    int test,k;
    for ( scanf("%d",&test); test--; ) {
        ans = -INF;
        scanf("%d %d",&money,&garment);
        for (int i=0;i<=garment;i++)
            for (int j=0;j<=200;j++) visit[i][j] = false;
        for (int i=0;i<garment;i++) {
            scanf("%d",&k);
            int v;
            while (k--) {
                scanf("%d",&v);
                vi[i].pb(v);
            }
        }
        dp(0, 0);
        if (ans==-INF) puts("no solution");
        else printf("%d\n",ans);
        for (int i=0;i<garment;i++) vi[i].clear();
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}
