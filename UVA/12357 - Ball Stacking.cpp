/***********************************************
* Author - LUONG VAN DO                        *
* 12357 - Ball Stacking ->AC
* Algorithm dp
* Time Limit 0.128s
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
#define maxN 1005
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int dp[maxN][maxN];
int n;
int max(int a, int b){
    return a > b ? a : b;
}
void Read_Input(){
    while (scanf("%d",&n) && n){
        for (int i=1;i<=n;i++)
            for (int j=1;j<=i;j++) {
                scanf("%d",&dp[i][j]);
                dp[i][j]+=dp[i-1][j];
            }
        for (int i=1;i<=n;i++){
            
            for (int j=i;j<=n;j++)
                dp[j][i]+=dp[j-1][i-1];
            for (int j=n-1;j>=i;j--)
                dp[j][i] = max(dp[j][i], dp[j+1][i]);
                
        }
        int ans = 0;
        for (int i=1;i<=n;i++)
            ans = max(ans, dp[i][i]);
        printf("%d\n",ans);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}
