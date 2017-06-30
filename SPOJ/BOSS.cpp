/***********************************************
* Author - LUONG VAN DO                        *
* BOSS
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
struct node
{
    int id, h, l;
    node (){}
    node (int idd, int hh, int ll)
    {
        id = idd;
        h = hh;
        l = ll;
    }
    bool operator < (node D) const
    {
        if (h!=D.h) return h < D.h;
        return l < D.l;
    };
};
void Read_Input(){
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d %d",&n,&q);
        
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
