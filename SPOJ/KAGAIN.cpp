/***********************************************
* Author - LUONG VAN DO                        *
* KAGAIN ->AC
* Algorithm Left, Right
* Time Limit 0.38s
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
#define maxN 30005
using namespace std;
int64 a[maxN], n;
int64 Left[maxN], Right[maxN];
void Solve(){
    memset(Left, 0, sizeof(Left));
    memset(Right, 0 ,sizeof(Right));
    for (int i=1;i<=n;i++) {
        Left[i] = i - 1;
        Right[n - i + 1] = n - i + 2;
        while ( a[i] <= a[ Left[i] ] ) Left[i] = Left[ Left[i] ];
        while ( a[n - i + 1] <= a[ Right[n - i + 1] ] )  Right[n - i + 1] = Right[ Right[n - i + 1] ];
    }
    /*for (int i=n;i>=1;i--) {
        Right[i] = i + 1;
        while ( a[i] <= a[ Right[i] ] ) Right[i] = Right[ Right[i] ];
    }*/
    for (int i = 1;i <= n;i++)
    cout<<Left[i]<<" ";
    cout<<endl;
    for (int i = 1;i <= n;i++)
    cout<<Right[i]<<" ";
    cout<<endl;
    int64 r1,r2,rs;
    rs = 0;
    for (int i=1;i<=n;i++) {
        if (rs < a[i] * (Right[i] - Left[i] - 1) ) {
            rs = a[i] * (Right[i] - Left[i] - 1);
            r1 = Left[i] + 1;
            r2 = Right[i] - 1;
        }
    }
    printf("%lld %lld %lld\n",rs,r1,r2);
}
void Read_Input(){
    int t;
    scanf("%d",&t);
    while (t--){
        scanf("%lld",&n);
        For(i,1,n)
            scanf("%lld",&a[i]);
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
