/***********************************************
* Author - LUONG VAN DO                        *
* C11BC1 ->AC
* Algorithm dp
* Time Limit 16.16s
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
#define INF 790972
#define maxN 100001
using namespace std;
typedef struct node{
    int a,b;
    node(){}
    node(int aa, int bb){
        a = aa; b = bb;
    }
    bool operator < (node D) const{
        return (b < D.b);
    }
};
int n,k;
int64 f[51][maxN];
int64 s[maxN], rs;
node h[maxN];
void Read_Input(){
    scanf("%d %d",&n,&k);
    For(i,1,n) {
        scanf("%d %d",&h[i].a,&h[i].b);
        s[i] = s[i-1] + h[i].a;
    }
}
int64 dp(int k, int n){
    //cout<<k<<" "<<n<<endl;
    For(i,1,n) {
        f[1][i] = h[i].a;
        f[2][i] = ( (h[i].a * s[i-1]) % INF + f[2][i-1] % INF) % INF;
    }
    for (int j=3;j<=k;j++) {
        for (int i=j;i<=n;i++)
            f[j][i] = ( (h[i].a * f[j-1][i-1]) % INF + f[j][i-1] % INF) % INF;
    }
    return f[k][n];
}
int fr(int x, int l, int r){
    while (l<=r){
        int mid = (l + r) >> 1;
        if (h[mid].b<=x) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
void Solve(){
    rs = dp(k,n);
    cout<<rs<<endl;
    sort(h+1,h+1+n);
    for (int i=1;i<=n;i++) {
        int j = fr(h[i].b,i,n);
        if (j-i+1>=k) {
            for (int u=i;u<=j;u++)
                s[u-i+1] = s[u-i] + h[u].a;
            
            rs-=dp(k,j-i+1);
            if (rs<0) rs+=INF;
        }
        i = j;
    }
}
void Write_Output(){
    printf("%lld\n",rs);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}
