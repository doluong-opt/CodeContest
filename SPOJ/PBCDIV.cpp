/***********************************************
* Author - LUONG VAN DO                        *
* PBCDIV ->AC
* Algorithm Adhoc
* Time Limit 
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
int64 A,B;
void Read_Input(){
    int t;
    scanf("%d",&t);
    int64 a,b,c,d,e,f,rs;
    while (t--)
    {
        scanf("%lld %lld",&A,&B);
        a = (A - 1) / 12; b = B / 12;
        a = b - a;
        c = (A - 1) / 30; d = B / 30;
        c = d - c;
        e = (A - 1) / 60; f = B / 60;
        e = f - e;        
        rs = ( a + c ) - 2 * e;
        printf("%lld\n",rs);
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
