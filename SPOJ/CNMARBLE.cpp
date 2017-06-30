/***********************************************
* Author - LUONG VAN DO                        *
* CNMARBLE ->AC
* Algorithm Adhoc
* Time Limit 1.73s
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
#define maxN 500005
using namespace std;
int n,m,sl,hop;
int a[maxN];
int f[maxN];
void Read_Input(){
    sl = 0;
    scanf("%d %d",&n,&m);
    For(i,1,n)
    {
        scanf("%d",&a[i]);
        sl+=a[i];
    }
}
void Solve(){
    int vt = 1;
    For(i,1,sl)
    {
        if ( !a[vt] ) vt++;
        if ( vt > n) break;
        a[vt]--;
        f[i] = vt;
    }
    hop = sl / m;
}
void Write_Output(){
    For(i,1,hop)
    {
        for (int j=i;j<=sl;j+=hop)
        {
            if ( j > i) printf(" ");
            printf("%d",f[j]);
        }
        printf("\n");
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}
