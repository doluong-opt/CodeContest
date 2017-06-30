/***********************************************
* Author - LUONG VAN DO                        *
* MYSTERY ->AC
* Algorithm Dong Du
* Time Limit 0.05s
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
#define INF 20122007
#define maxN 85001
using namespace std;
int n;
int d[maxN];
int64 rs;
void Init(){
    d[0] = 1;
    for (int i=1;i<=84420;i++)
        d[i] = (d[i-1] * 3) % INF;    
}
void Read_Input(){
    Init();
    scanf("%d",&n);    
}
void Solve(){
    int uoc;
    rs = 1;
    for (int i=1;i<=(int)sqrt(n);i++)
    {
        if ( n % i ==0)        
        {
            uoc = n / i;
            rs = ( rs * ( (d[uoc % 84420]) - 1 ) % INF ) % INF;
            if ( uoc != i)
            rs = ( rs * ( (d[i % 84420]) - 1 ) % INF ) % INF;
        }
    }
}
void Write_Output(){
    printf("%lld\n",rs % INF);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}
