/***********************************************
* Author - LUONG VAN DO                        *
* LIS ->AC
* Algorithm LIS
* Time Limit 0.26s
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
#define maxN 30001
using namespace std;
int a[maxN],n,m;
void Read_Input(){
    scanf("%d",&n);
    Rep(i,n)
        scanf("%d",&a[i]);
}
void Solve(){
    int b[maxN],u,v;
    m = 0;
    b[m] = 0;
    for (int i=1;i<n;i++)
    {
        if ( a[i] > a[b[m]])
        {
            b[++m] = i;
            continue;
        }
        for (u = 0, v = m; u<v;)
        {
            int c = (u + v) >> 1;
            if ( a[i] > a[b[c]]) u = c + 1;
            else v = c;
        }
        if ( a[i] < a[b[u]])
            b[u] = i;
    }
}
void Write_Output(){
    printf("%d\n",m + 1);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}
