/***********************************************
* Author - LUONG VAN DO                        *
* LQDDIV ->AC
* Algorithm Phan Tap
* Time Limit 0.82s
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
#define INF 2000000000
#define maxN 33
using namespace std;
int64 sum,sl,rs,t;
int a[maxN];
int n;
int64 x[65539], xi;
int64 y[65539], yi;
void Read_Input(){
    sum = 0;
    scanf("%d",&n);
    For(i,1,n)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
}
void TryA(int i, int64 s){
    for (int j=0;j<=1;j++)
    {
        s+=a[i] * j;
        if (i < n / 2) TryA(i+1,s);
    }
    x[++xi] = s;
}
void TryB(int i, int64 s){
    for (int j=0;j<=1;j++)
    {
        s+=a[i] * j;
        if (i < n) TryB(i+1,s);
    }
    y[++yi] = s;
}
int fl(int64 xx, int l, int r){
    while (l<=r)
    {
        int mid = ( l + r ) >> 1;
        if (xx<=y[mid]) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int fr(int64 xx, int l, int r){
    while (l<=r)
    {
        int mid = ( l + r ) >> 1;
        if (xx>=y[mid]) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
void Solve(){
    int64 temp;
    rs = INF;
    TryA(1,0);
    TryB(n/2+1,0);
    sort(y+1,y+yi+1);
    For(i,1,yi)
        rs = min(rs,abs(sum - 2 * y[i]));
    t = sum / 2 + sum % 2;
    For(i,1,xi)
    {
        rs = min(rs,abs(sum - 2 * x[i]));
        int64 xx = abs(t - x[i]);
        int l = fl(xx,1,yi);
        int r = fr(xx,1,yi);
        if (l>=1 && l<=yi)
            rs = min(rs,abs(sum - 2 * (x[i] + y[l])));
        if (r>=1 && r<=yi)
            rs = min(rs,abs(sum - 2 * (x[i] + y[r])));
    }
    t = (sum - rs) / 2 + rs;
    sl = 0;
    for (int i=1;i<=yi;i++)
        if (t==y[i]) sl++;
    for (int i=1;i<=xi;i++)
    {
        if (x[i]==t) sl++;
        temp = t - x[i];
        if (temp > 0)
        {
            int l = fl(temp,1,yi);
            int r = fr(temp,1,yi);
            if (l<=r) sl+=(r-l+1);
        }
    }
    if (sum%2==0 && t==sum/2) sl/=2;
}
void Write_Output(){
    printf("%lld %lld\n",rs,sl);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}
