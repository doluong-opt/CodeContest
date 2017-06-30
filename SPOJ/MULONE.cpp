/***********************************************
* Author - LUONG VAN DO                        *
* MULONE ->AC
* Algorithm Adhoc
* Time Limit 1.02s
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
#define maxN 50001
using namespace std;
int n;
char rs[2000005];
void Solve(){
    int nm,nho,tm;
    nm = nho = 0;
    for (int i=1;i<n;i++)
    {
        tm = nho + i;
        rs[nm++] = tm % 10 + '0';
        nho = tm / 10;
    }
    for (int i=n;i>=1;i--)
    {
        tm = nho + i;
        rs[nm++] = tm % 10 + '0';
        nho = tm / 10;
    }
    if (nho) printf("%d",nho);
    for (int i=nm-1;i>=0;i--) printf("%c",rs[i]);
    printf("\n");
}
void Read_Input(){
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        Solve();
    }
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
//    Solve();
//    Write_Output();
}
