/***********************************************
* Author - LUONG VAN DO                        *
* MEDIAN ->AC
* Algorithm BIT
* Time Limit 3.69s
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
#define maxN 250001
#define maxVal 65537
using namespace std;
int seed, mul, add, n, k;
int64 a[maxN];
int tree[maxVal];
int64 rs;
void update(int i, int val){
    while (i<=maxVal){
        tree[i]+=val;
        i+=(i&-i);
    }
}
int Get(int i){
    int sum = 0;
    while ( i ){
        sum+=tree[i];
        i-=(i&-i);
    }
    return sum;
}
int bs(int x, int l, int r){
    int s = Get(l - 1);
    while (l<=r){
        int mid = (l + r) >> 1;
        int temp = Get(mid) - s ;
        if (temp>=x) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
void Read_Input(){
    int t,Count = 0;
    scanf("%d",&t);
    while (t--){
        rs = 0;
        memset(tree, 0, sizeof(tree));
        scanf("%d %d %d %d %d",&seed,&mul,&add,&n,&k);
        int kk = (k + 1) >> 1;
        a[1] = seed + 1;
        For(i,2,n)
            a[i] = ((a[i-1] - 1) * mul + add) % 65536 + 1;
        for (int i=1;i<=k;i++) update(a[i], 1);
        rs+=bs(kk, 1, maxVal) - 1;
        for (int i=k+1;i<=n;i++) {
            update(a[i-k], -1);
            update(a[i], 1);
            rs+=bs(kk, 1, maxVal) - 1;
        }
        printf("Case #%d: %lld\n",++Count,rs);
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
