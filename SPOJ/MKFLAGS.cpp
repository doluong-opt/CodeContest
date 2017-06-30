/***********************************************
* Author - LUONG VAN DO                        *
* MKFLAGS ->AC
* Algorithm Adhoc
* Time Limit 0.02s
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
int n;
int a[maxN][maxN];
void Read_Input(){
    scanf("%d",&n);
}
void Solve(){
    int k = 0,m = 0;
    int c,r;
    while ( true )
    {
        ++k;
        m+=k;
        if ( m + k + 1 > n) break;
    }
    c = k;
    printf("%d\n",c+1);
    for (int i=1;i<=c;i++) a[1][i] = i;
    for (int i=2;i<=c+1;i++) a[i][1] = i - 1;
    m = c;
    for (int i=2;i<=c;i++)
    {
        int m1 = m;
        for (int j=i;j<=c;j++)
            a[i][j] = ++m;
        for (int j=i+1;j<=c+1;j++)
            a[j][i] = ++m1;
        m = m1;
    }
    for (int i=1;i<=c+1;i++) {
        for (int j=1;j<=c;j++) {
            if ( j > 1) printf(" ");
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
}
main(){
    /*#ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif*/
    Read_Input();
    Solve();
    //Write_Output();
}
