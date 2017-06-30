/***********************************************
* Author - LUONG VAN DO                        *
* MNERED ->AC
* Algorithm Adhoc
* Time Limit 0.06s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <map>
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
#define maxN 101
using namespace std;
int g[maxN][maxN];
int rs,n,k;
void Read_Input(){
    scanf("%d %d",&n,&k);
    For(i,1,k)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        g[u-1][v-1] = 1;
    }    
}
int get(int l, int r, int k){
    int s = 0;
    for (int i=l;i<r;i++) s+=g[i][k];
    return s;
}
void Solve(){
    rs = n * n;
    for (int i=0;i<n;i++)
        for (int j=i+1;j<=n;j++)
        {
            if (k % ( j - i ) ) continue;
            int s,sum = 0;
            s = k / ( j - i );
            
            if ( s > n) continue;
            
            for (int h=0;h<s;h++) sum+=get(i,j,h);
            
            for (int q=s;q<=n;q++)
            {
                if ( rs > k - sum ) rs = k - sum;
                sum-=get(i,j,q - s);
                sum+=get(i,j,q);
            }
        }
}
void Write_Output(){
    printf("%d\n",rs);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}
