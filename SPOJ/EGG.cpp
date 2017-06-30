/***********************************************
* Author - LUONG VAN DO                        *
* EGG ->AC
* Algorithm dp
* Time Limit 0.41s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <map>
#include <set>
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
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 1001
using namespace std;
int n,m;
int f[maxN][maxN];
int Init(){
    for (int i=1;i<=1000;i++)
        f[i][1] = 1;
    for (int i=1;i<=1000;i++)
        f[1][i] = i;
    for (int i=2;i<=1000;i++)
        for (int j=2;j<=1000;j++) {
            f[i][j] = INF;
            if (i>=10) f[i][j] = (int)log2(j) + 1;
            else
            for (int k=1;k<=j;k++)
                if ( f[i][j] > 1 + max(f[i-1][k-1], f[i][j-k]) ) f[i][j] = 1 + max(f[i-1][k-1],f[i][j-k]);
        }
}
void Read_Input(){
    int t;
    scanf("%d",&t);
    Init();
    while (t--){
        scanf("%d %d",&n,&m);
        printf("%d\n",f[n][m]);
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    //Write_Output();
}
