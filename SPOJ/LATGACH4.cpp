/***********************************************
* Author - LUONG VAN DO                        *
* LATGACH4 ->AC
* Algorithm Adhoc
* Time Limit 0.01s
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
#define INF 111539786
#define maxN 501
using namespace std;
int nm;
int64 n;
int64 m[105][5],d[maxN],s[6];
void Init(){
    m[1][0] = 0;
    m[1][1] = 1;
    m[1][2] = 1;
    m[1][3] = 1;
    For(i,2,32)
    {
        m[i][0] = ((m[i-1][0] * m[i-1][0]) % INF + (m[i-1][1] * m[i-1][2]) % INF) % INF;
        m[i][1] = ((m[i-1][0] * m[i-1][1]) % INF + (m[i-1][1] * m[i-1][3]) % INF) % INF;
        m[i][2] = m[i][1];
        m[i][3] = ((m[i-1][2] * m[i-1][1]) % INF + (m[i-1][3] * m[i-1][3]) % INF) % INF;
    }
}
void BB(){
    nm = 0;
    while ( n )
    {
        d[nm++] = n % 2;
        n = n >> 1;
    }
    Rep(i, nm) cout<<i+1<<" "<<d[i]<<endl;
}
int Find(){
    BB();
    s[0] = 1;
    s[1] = 0;
    s[2] = 0;
    s[3] = 1;
    int temp[6];
    for (int i=0;i<nm;i++)
    {
        if ( d[i] )
        {
            temp[0] = ((m[i+1][0] * s[0]) % INF + (m[i+1][1] * s[2]) % INF) % INF;
            temp[1] = ((m[i+1][0] * s[1]) % INF + (m[i+1][1] * s[3]) % INF) % INF;
            temp[2] = temp[1];
            temp[3] = ((m[i+1][2] * s[1]) % INF + (m[i+1][3] * s[3]) % INF) % INF;
            s[0] = temp[0];
            s[1] = temp[1];
            s[2] = temp[2];
            s[3] = temp[3];
        }
    }
    cout<<s[0]<<" "<<s[1]<<" "<<s[2]<<" "<<s[3]<<endl;
    return ( s[3] ) % INF;
}
void Read_Input(){
    int t;
    Init();
    scanf("%d",&t);
    while (t--)
    {
        scanf("%lld",&n);
        printf("%d\n",Find());
    }
}
main(){
    /*#ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif*/
    Read_Input();
    //Solve();
    //Write_Output();
}
