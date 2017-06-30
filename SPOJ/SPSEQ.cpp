/***********************************************
* Author - LUONG VAN DO                        *
* SPSEQ ->AC
* Algorithm Lis
* Time Limit 1.41s
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
#define maxN 100001
using namespace std;
int a[maxN] , b[maxN], n ,rs;
int rs1[maxN], rs2[maxN];
void Read_Input(){
    scanf("%d",&n);
    For(i,1,n)
    {
        scanf("%d",&a[i]);
        b[n-i+1] = a[i];
    }
}
void Lis(int a[], int n, int tmp[]){
    int m = 1,u,v;
    int t[maxN];
    t[1] = 1; tmp[1] = 1;
    For(i,2,n)
    {
        if ( a[i] > a[t[m]])
        {
            t[++m] = i;
            tmp[i] = m;
            continue;
        }
        for (u = 1, v = m; u < v;){
            int c = (u + v) / 2;
            if ( a[i] > a[t[c]] ) u = c + 1;
            else v = c;
        }
        if ( a[i] < a[t[u]])
        {
            t[u] = i;
            tmp[i] = u;
        }
    }
}
void Solve(){
    rs = 1;
    Lis( a , n, rs1);
    Lis( b , n, rs2);
    For(i,1,n)
        rs = max(rs,min(rs1[i]-1,rs2[n-i+1]-1) * 2 + 1);
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
