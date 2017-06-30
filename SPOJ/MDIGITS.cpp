/***********************************************
* Author - LUONG VAN DO                        *
* MDIGITS ->AC
* Algorithm Adhoc
* Time Limit 0.03s
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
#define maxN 50001
using namespace std;
int64 x,y,xx,yy;
int64 rs[10];
int64 scs[10];
int64 mu10[10];
int64 a[10], b[10];
int64 c[10], d[10];
void Init(){
    mu10[1] = 1;
    scs[1] = 9;
    For(i,2,9) {
        mu10[i] = mu10[i-1] * 10;
        scs[i] = scs[i-1] * 10;
    }
    For(i,2,9) scs[i] = scs[i] * i;
}
void Solve() {
    Ford(i,9,1) {
        a[i] = x % 10;
        b[i] = y % 10;
        x/=10; y/=10;
    }
    
}
int Calc(int id, int val) {
    memcpy(c, a, sizeof(a));
    memcpy(d, b, sizeof(b));
    if ( c[id] != val ) {
        c[id] = val;
        for (int i=id+1;i<=9;i++) c[i] = 9;
        if ( c[id] > a[id] ) c[id-1]--;
    }
    if ( d[id]!= val ) {
        d[id] = val;
        for (int i=id+1;i<=9;i++) d[i] = 0;
        if ( d[id] < b[id] ) d[id-1]++;
    }
    int s1 = 0, s2 = 0;
    for (int i=1;i<=9;i++) {
        if ( i!=id ) {
            s1 = s1 * 10 + c[i];
            s2 = s2 * 10 + d[i];
        }
    }
    if (s1 < s2) return 0;
    return (s1 - s2 + 1);
}
int Countscs(int64 xx){
    char s[15];
    sprintf(s,"%lld",xx);
    int len = strlen(s);
    int sum = 0;
    For(i,1,len-1) sum+=scs[i];
    sum+=(xx - mu10[len] + 1) * len;
    return sum;
}
void Read_Input(){
    Init();
    while ( scanf("%lld %lld",&x, &y) && (x + y) ) {
        memset(rs,0,sizeof(rs));
        if (x < y) swap(x,y);
        yy = x; xx = y;
        Solve();
        For(i,1,9)
            For(j,2,9)
                rs[i]+= Calc(j,i);
        int sum = 0;
        /*for (int i = 1;i <= 9;i++)
            cout<<i<<" "<<rs[i]<<endl;*/
        For(i,1,9) sum+=rs[i];
        rs[0] = Countscs(yy) - Countscs(xx - 1) - sum;
        for (int i=0;i<=9;i++) {
            if (i > 0) printf(" ");
            printf("%d",rs[i]);
        }
        printf("\n");
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
