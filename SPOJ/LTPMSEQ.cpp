/***********************************************
* Author - LUONG VAN DO                        *
* LTPMSEQ ->AC
* Algorithm Xor
* Time Limit 0.14s
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
#define maxN 16
using namespace std;
int a[maxN];
int nn,n,l;
char s[maxN];
void Read_Input(){
    nn = -1;
    scanf("%d ",&n);    
    Rep(i,n) {
        gets( s );
        l = strlen(s);
        if (nn<l) nn = l;
        Rep(j,l)
            a[j] =a[j]^s[j];
    }
    int found = 0;
    for (int i=0;i<nn && !found;i++)
        if (a[i]) found = 1;
    if (!found) printf("-1");
    else {
        for (int i=0;i<nn;i++)
            if (a[i]) printf("%c",a[i]);
    }    
    printf("\n");
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    //Write_Output();
}
