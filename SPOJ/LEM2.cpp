/***********************************************
* Author - LUONG VAN DO                        *
* LEM2 ->AC
* Algorithm bfs + bit
* Time Limit 2.28s
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
#define maxN 21
using namespace std;
typedef struct node{
    int st, w;
    node(){}
    node(int ss, int ww){
        st = ss; w = ww;
    }
};
int a[maxN][1];
int n,k,e,s;
int color[1048577];
void Read_Input(){
    int m,u;
    scanf("%d %d",&n,&k);
    e = 1<<(n-k);
    For(i,1,n) {
        s = 0;
        scanf("%d",&m);
        while (m--) {
            scanf("%d",&u);
            s+=(1<<(n-u));
        }
        a[i][0] = s;
    }
    s = 0;
    for (int i=1;i<=n;i++) {
        scanf("%d",&u);
        if (u) s+=(1<<(n-i));
    }
}
int Solve(){
    int x,y;
    node k,tmp;
    k = node(s,0);
    color[s] = 1;
    queue <node> Q;
    Q.push( k );
    while ( !Q.empty() ){
        k = Q.front(); Q.pop();
        if (k.st == e ) return k.w;
        for (int i=1;i<=n;i++) {
            x = a[i][0] & k.st;
            x = x^k.st;
            x = x | (1<<(n-i));
            if ( color[x] ) continue;
            color[x] = 1;
            Q.push(node(x,k.w + 1));
        }
    }
    return -1;
}
void Write_Output(){
    printf("%d\n",Solve());
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    //Solve();
    Write_Output();
}
