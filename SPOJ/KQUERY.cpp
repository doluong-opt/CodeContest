/***********************************************
* Author - LUONG VAN DO                        *
* KQUERY ->AC
* Algorithm BIT
* Time Limit 3.16s
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
#define maxQ 200005
using namespace std;
typedef struct node{
    int ind,x;
    node(){}
    node(int id, int xx){
        ind = id; x = xx;
    }
    bool operator < (node D) const{
        return x < D.x;
    }
};
typedef struct query{
    int ind,x,y,k;
    query(){}
    query(int id, int xx, int yy, int kk){
        ind = id; x = xx; y = yy; k = kk;
    }
    bool operator < (query D) const{
        return k < D.k;
    }
};
int n, p;
node a[maxN];
query qu[maxQ];
int id[maxN + maxQ], f[maxN + maxQ];
int rs[maxQ], nm;
int tree[maxN];
void Read_Input(){
    scanf("%d",&n);
    int m = nm = 0;
    For(i,1,n) {
        scanf("%d",&a[i].x);
        a[i].ind = i;
        id[++m] = a[i].x;
    }
    scanf("%d",&p);
    For(i,1,p) {
        scanf("%d %d %d",&qu[i].x,&qu[i].y,&qu[i].k);
        qu[i].ind = i;
        id[++m] = qu[i].k;
    }
    sort(id+1,id+1+m);
    id[0] = id[1] - 1;
    For(i,1,m)
        if (id[i] > id[i-1]) f[++nm] = id[i];
}
int bs(int x, int l, int r){
    while (l<=r){
        int mid = (l + r) >> 1;
        if (f[mid]==x) return mid;
        if (f[mid] > x) r = mid - 1;
        else l = mid + 1;
    }
}
void update(int i){
    while (i<=n){
        tree[i]++;
        i+=(i&-i);
    }
}
int get(int i){
    int sum = 0;
    while ( i ){
        sum+=tree[i];
        i-=(i&-i);    
    }
    return sum;
}
void Solve(){
    int d;
    For(i,1,n)
        a[i].x = bs(a[i].x, 1, nm);
    For(i,1,p)
        qu[i].k = bs(qu[i].k, 1, nm);
    sort(a+1,a+1+n);
    sort(qu+1,qu+1+p);
    d = n;
    Ford(i,p,1) {
        while (d>=1 && a[d].x > qu[i].k)
            update( a[d--].ind );
        rs[qu[i].ind] = get( qu[i].y ) - get(qu[i].x - 1);
    }
    //For(i,1,n) cout<<a[i].ind<<" "<<a[i].x<<endl;
    //cout<<endl;
    //For(i,1,p) cout<<qu[i].x<<" "<<qu[i].y<<" "<<qu[i].k<<endl;
}
void Write_Output(){
    For(i,1,p)
        printf("%d\n",rs[i]);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}
