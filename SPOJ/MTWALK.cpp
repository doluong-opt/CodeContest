/***********************************************
* Author - LUONG VAN DO                        *
* MTWALK ->AC
* Algorithm bfs + Chat Nhi Phan
* Time Limit 0.18s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <map>
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
#define maxN 201
using namespace std;
struct node
{
    int x,y;
    bool operator == (node D) const
    {
        return x==D.x && y==D.y;
    }
};
int Max,n;
int a[maxN][maxN];
int color[maxN], Free[maxN][maxN];
int dx[5] = {0,1,0,-1};
int dy[5] = {1,0,-1,0};
void Read_Input(){
    Max = -1;
    scanf("%d",&n);
    For(i,1,n)
        For(j,1,n){
            scanf("%d",&a[i][j]);
            Max = max(Max,a[i][j]);
            color[a[i][j]] = 1;
        }
}
bool IsOk(int u, int v){
    if (u>=1 && v>=1 && u<=n && v<=n) return true;
    return false;
}
bool bfs(int Min, int V){
    node K,Tmp;
    if ( a[1][1] < Min ) return false;
    if ( a[1][1] > Min + V) return false;
    K.x = 1; K.y = 1;
    For(i,1,n)
        For(j,1,n) Free[i][j] = 0;
    Free[1][1] = 1;
    queue <node> Q;
    Q.push( K );
    while ( !Q.empty() )
    {
        K = Q.front(); Q.pop();
        Rep(i,4)
        {
            Tmp.x = K.x + dx[i]; Tmp.y = K.y + dy[i];
            if ( !IsOk(Tmp.x,Tmp.y) ) continue;
            if ( !Free[Tmp.x][Tmp.y] && a[Tmp.x][Tmp.y]>=Min && a[Tmp.x][Tmp.y]<=Min + V)
            {
                Free[Tmp.x][Tmp.y] = 1;
                if ( Free[n][n] ) return true;
                Q.push( Tmp );
            }
        }
    }
    return false;
}
void Solve(){
    int L,R,res,found;
    L = 0; R = Max;
    while ( L<=R )
    {
        int mid = ( L + R) >> 1;
        found = 0;
        for (int i=0;i<=Max && !found;i++)
            if ( color[i] && bfs(i, mid) )
            {
                res = mid;
                found = 1;
            }
        if (found) R = mid - 1;
        else L = mid + 1;
    }
    printf("%d\n",res);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    //Write_Output();
}
