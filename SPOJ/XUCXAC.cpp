/***********************************************
* Author - LUONG VAN DO                        *
* XUCXAC
* Algorithm
* Time Limit
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
#define INF 10000000000000000LL
#define maxN 55
using namespace std;
struct node{
    int pre, up, right;
};
int a[maxN][maxN];
int n,m;
int s1,s2,t1,t2;
int s,t;
int64 d[5005];
void Read_Input(){
    scanf("%d %d",&m,&n);
    For(i,1,m) 
        For(j,1,n) scanf("%d",&a[i][j]);
    scanf("%d %d %d %d",&s1,&s2,&t1,&t2);
    s = s1 * 10 + s2;
    t = t1 * 10 + t2;
}
void Solve(){
    For(i,1,m*10+n) d[i] = INF;
    d[s] = a[s1][s2] * 5;
    
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}
