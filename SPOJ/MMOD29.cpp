/***********************************************
* Author - LUONG VAN DO                        *
* MMOD29 ->AC
* Algorithm Dong Du
* Time Limit 0.00s
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
#define INF 29
#define maxN 50001
using namespace std;
uint64 X;
uint64 d2[39];
uint64 d3[39];
uint64 d167[16];
void Init(){
    d2[0] = 1;
    for (int i=1;i<=28;i++)
        d2[i] = (d2[i-1] * 2) % INF;
    d3[0] = 1;
    for (int i=1;i<=28;i++)
        d3[i] = (d3[i-1] * 3) % INF;
    d167[0] = 1;
    for (int i=1;i<=14;i++)
        d167[i] = (d167[i-1] * 167) % INF;
}
void Solve(){
    uint64 hai,ba,a167;
    uint64 a,b,c,rs;
    hai = (2 * X + 1) % 28;
    ba = (X + 1) % 28;
    a167 = (X + 1) % 14;
    a = (d2[hai] % INF - 1) % INF;
    b = (d3[ba] % INF - 1) % INF;
    c = (d167[a167] % INF - 1) % INF;
    rs = (a * b * c) % INF;
    printf("%lld\n",(rs*9) % INF);
}
void Read_Input(){
    Init();
    while ( scanf("%lld",&X) && X)
    {
        Solve();
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
