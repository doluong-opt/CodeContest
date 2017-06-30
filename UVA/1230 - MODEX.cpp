/***********************************************
* Author - LUONG VAN DO                        *
* 1230 - MODEX ->AC
* Algorithm Mod
* Time Limit 0.008s
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
int64 MOD(int64 x, int64 y, int64 n){
    int64 res = 1;
    while ( y ) {
        if (y & 1) res = (res * x) % n;
        y>>=1;
        x = (x * x) % n;
    }
    return res;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases;
    int64 ans, x, y, n;
    scanf("%d",&cases);
    while (cases--) {
        scanf("%lld %lld %lld",&x,&y,&n);
        ans = MOD(x, y, n);
        printf("%lld\n",ans);
    }
}
