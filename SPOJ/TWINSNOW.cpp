/***********************************************
* Author - LUONG VAN DO                        *
* TWINSNOW ->AC
* Algorithm sort
* Time Limit 7.44s
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
struct node{
    int a[7];
    node(){}
    bool operator < (node D) const{
        for (int i=1;i<=6;i++)
            if (a[i] < D.a[i] ) return true;
            else
            if (a[i] > D.a[i] ) return false;
            return false;
    }
    bool operator == (node D) const{
        for (int i=1;i<=6;i++)
            if (a[i]!=D.a[i]) return false;
            return true;
    }
};
node a[maxN], temp;
void Read_Input(){
    int n, found = 0, t;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=6;j++)
            scanf("%d",&a[i].a[j]);
        temp=a[i];
        for (int j=1;j<6;j++)
        {
            t=a[i].a[1];
            for (int k=1;k<6;k++)
                a[i].a[k]=a[i].a[k+1];
            a[i].a[6]=t;
            if (a[i]<temp)temp=a[i];
        }
        for (int j=1;j<4;j++)
            swap(a[i].a[j],a[i].a[6-j+1]);
        for (int j=1;j<6;j++)
        {
            t=a[i].a[1];
            for (int k=1;k<6;k++)
                a[i].a[k]=a[i].a[k+1];
            a[i].a[6]=t;
            if (a[i]<temp)temp=a[i];
        }
        a[i]=temp;
    }
    sort(a,a+n);
    for (int i=1;i<n && !found;i++)
        if (a[i]==a[i+1]) found = 1;
    if (found) puts("Twin snowflakes found.");
    else puts("No two snowflakes are alike.");
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    //Write_Output();
}
