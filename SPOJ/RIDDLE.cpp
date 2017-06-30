/***********************************************
* Author - LUONG VAN DO                        *
* RIDDLE ->AC
* Algorithm Adhoc
* Time Limit 0.64s
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
int a[maxN];
int n,k;
bool Check(int l, int r){
    int s = 0;
    int tmp[maxN];
    for (int i=l;i<=r;i++) tmp[i] = a[i];
    sort(tmp+1,tmp+1+r);
    for (int i=l;i<=r;i++)
        if (tmp[i] > s + 1) return false;
        else {
            s+=(tmp[i]);
            if ( s>=k ) return true;
        }
    return false;
}
int Solve(){
    int l,r;
    l = 1; r = n;
    int rs = -1;
    while (l<=r) {
        int mid = (l + r) >> 1;
        if ( Check(1, mid) ) rs = mid, r = mid - 1;
        else l = mid + 1;
    }
    return rs;
}
void Read_Input(){
    int t;
    scanf("%d",&t);
    while (t--){
        scanf("%d %d",&n,&k);
        For(i,1,n) scanf("%d",&a[i]);
        printf("%d\n",Solve());
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
