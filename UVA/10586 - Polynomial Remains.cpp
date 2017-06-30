/***********************************************
* Author - LUONG VAN DO                        *
* 10586 - Polynomial Remains ->AC
* Algorithm Adhoc + math
* Time Limit 0.144s
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
#define maxN 10001
using namespace std;
int n,k;
int a[maxN];
void Write_Output(){
    int blank = 0;
    For(i,0,n) {
        if (a[i]) {
            if (blank) printf(" ");
            blank = 1;
            printf("%d",a[i]);
        }
    }
    puts("");
}
void Solve(){
    if (k > n) {
        Write_Output();
        return;
    }        
    if (n==0 && k!=0) {
        printf("%d\n",a[0]);
        return;
    }
    if (n==0 && k==0) {
        puts("0");
        return;
    }
    if (k==0) {
        puts("0");
        return;
    }
    while ( true ){
        int i,pow;
        for (i=n;i>=0;i--)
            if (i>=k && a[i]) {
                pow = i;
                break;
            }
        if (i==-1) break;        
        a[pow-k]-=a[pow];
        a[pow] = 0;
    }
    Write_Output();
}
void Read_Input(){
    while (scanf("%d %d",&n,&k)) {
        if (n==-1 && k==-1) break;
        For(i,0,n) scanf("%d",&a[i]);
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
