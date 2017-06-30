/***********************************************
* Author - LUONG VAN DO                        *
* SHHV ->AC
* Algorithm Adhoc
* Time Limit 0.00s
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
#define maxN 20
using namespace std;
int Num[15] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600};
int k,n;
int a[maxN], color[maxN], t[maxN];
char s[20];
void Read_Input(){
    int i = 0,l;
    gets(s);
    l = strlen( s );
    n = 0;
    Rep(i,l)
    {
        while ( i < l && s[i]==' ') ++i;
        sscanf(s+i,"%d",&a[++n]);
        while ( i < l && s[i]!=' ') ++i;
    }
    scanf("%d",&k);
}
void update(int i){
    while ( i<=n )
    {
        t[i]++;
        i+=(i&-i);
    }
}
int Get(int i){
    int sum = 0;
    while ( i )
    {
        sum+=t[i];
        i-=(i&-i);
    }
    return sum;
}
void Solve(){
    int pos = 0;
    Ford(i,n,1) {
        update( a[i] );
        int ss = Get( a[i] - 1);
        pos+=(ss * Num[n-i]);
    }
    if (pos!=Num[n]) printf("%d\n",pos+1);
    else printf("%d\n",pos);
}
void Write_Output(){
    int i,j;
    for (i=1;i<=n;i++) color[i] = 0;
    for (i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if (!color[j])
            if (k > Num[n-i]) k-=Num[n-i];
            else break;
        }
        a[i] = j;
        color[j] = 1;
    }
    cout<<k<<endl;
    For(i,1,n)
    {
        if (i > 1) printf(" ");
        printf("%d",a[i]);
    }
    printf("\n");
}
main(){
    /*#ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif*/
    Read_Input();
    Solve();
    Write_Output();
    system("pause");
}
