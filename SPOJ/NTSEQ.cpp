/***********************************************
* Author - LUONG VAN DO                        *
* NTSEQ ->AC
* Algorithm dp + Nhi Phan
* Time Limit 2.41s
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
#define INF 1000000007
#define maxN 100005
using namespace std;
typedef struct node {
    int val;
    int data, id;
};
int A[maxN], n;
node f[maxN];
int64 g[maxN], rs;
bool cmp(node x, node y){
    if (x.val!=y.val) return (x.val < y.val);
    return (x.id < y.id);
}
void Read_Input() {    
    scanf("%d",&n);
    For(i,1,n) {
        scanf("%d",&A[i]);
        f[i].data = A[i];
        f[i].id = i;
    }
}
int Lis() {
    int b[maxN];
    int m = 1,u,v;
    b[m] = 1; f[1].val = 1;
    For(i,2,n) {
        if ( A[i] > A[b[m]] ) {
            b[++m] = i;
            f[i].val = m;
            continue;
        }
        
        for (u = 1, v = m; u<v;) {
            int c = (u + v) >> 1;
            if ( A[i] > A[b[c]] ) u = c + 1;
            else v = c;
        }
        
        if ( A[i] < A[b[u]] )
            b[u] = i;
            f[i].val = u;
    }
    return m;
}
int fl(int x, int l, int r){
    while (l<=r) {
        int mid = (l + r) >> 1;
        if (f[mid].val>=x) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int fr(int x, int l, int r){
    while (l<=r) {
        int mid = (l + r) >> 1;
        if (f[mid].val<=x) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
int frr(int x, int l, int r){
    while (l<=r) {
        int mid = (l + r) >> 1;
        if (f[mid].id<=x) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}
int frdt(int x, int l, int r){
    while (l<=r) {
        int mid = (l + r) >> 1;
        if (f[mid].data<=x) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
void Solve() {
    int k = Lis();
    int l,r,rr,ll;
    rs = 0;
    sort(f+1,f+1+n,cmp);
    g[0] = 0;
    for (int i=1;i<=n;i++) {
        if (f[i].val==1) g[i] = (g[i-1] + 1) % INF;
        else
        {
            l = fl(f[i].val-1,1,i-1);
            r = fr(f[i].val-1,1,i-1);
            rr = frr(f[i].id,l,r);
            if (l<=rr && rr<=r) {
                ll = frdt(f[i].data-1,l,rr);
                    if ( l<=ll && ll<=rr)
                        g[i] = ( g[i-1] + ( g[rr] - g[ll-1]) ) % INF;
                    else
                        g[i] = (g[i-1] + 1) % INF;
                    if (g[i] < 0) g[i]+=INF;
            }
            else g[i] = (g[i-1] + 1) % INF;
        }
    }
    Ford(i,n,1)
        if (f[i].val==f[n].val) {
            if ( g[i] - g[i-1] > 0)
                rs = (rs + g[i] - g[i-1]) % INF;
            else
                rs = (rs + g[i] - g[i-1] + INF) % INF;
        }
        else break;
}
void Write_Output() {
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
