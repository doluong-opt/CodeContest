/***********************************************
* Author - LUONG VAN DO                        *
* NKABD ->AC
* Algorithm Adhoc
* Time Limit 0.2s
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
#define maxN 100001
using namespace std;
int f[maxN], rs, l, r;
void Read_Input(){
    For(i,2,100000) {
        int j = 1;
        while (i*j<=100000) {
            f[i*j]+=j;
            j++;
        }
    }
    rs = 0;
    scanf("%d %d",&l,&r);
    For(i,l,r)
        if (f[i]>i) rs++;
    printf("%d\n",rs);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    //Write_Output();
}
