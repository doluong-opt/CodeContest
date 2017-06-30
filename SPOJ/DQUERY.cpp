/***********************************************
* Author - LUONG VAN DO                        *
* DQUERY ->AC
* Algorithm BIT
* Time Limit 2.01s
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
    int ind,x,y;
    query(){}
    query(int id, int xx, int yy){
        ind = id; x = xx; y = yy;
    }
    bool operator < (query D) const{
        return y < D.y;
    }
};
node a[maxN], q[maxN];
query qu[maxQ];
int n, nq;
int tree[maxN];
int rs[maxQ];
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
bool cmp(node c, node d){
    return c.ind < d.ind;
}
void Read_Input(){
    scanf("%d",&n);
    For(i,1,n) {
        scanf("%d",&a[i].x);
        a[i].ind = i;
    }
    stable_sort(a+1,a+1+n);
    q[1].x = 0;
    q[1].ind = 1;
    For(i,2,n) {
        if ( a[i].x==a[i-1].x) q[a[i].ind].x = a[i-1].ind;
        q[a[i].ind].ind = a[i].ind;
    }
    sort(q+1,q+n+1,cmp);
    //For(i,1,n) cout<<q[i].x<<" "<<q[i].ind<<endl;
    scanf("%d",&nq);
    For(i,1,nq) {
        scanf("%d %d",&qu[i].x,&qu[i].y);
        qu[i].ind = i;
    }
    sort(qu+1,qu+1+nq);
}
void Solve(){
    int d;
    d = 1;
    For(i,1,nq) {
        while ( d<=n && q[d].ind<=qu[i].y ) {
            if (q[d].x) update( q[d].x );
            ++d;
        }
        rs[qu[i].ind] = qu[i].y - qu[i].x + 1 - (get( qu[i].y ) - get( qu[i].x - 1) );
    }
}
void Write_Output(){
    For(i,1,nq)
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
