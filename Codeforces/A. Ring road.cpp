/***********************************************
* Author - LUONG VAN DO                        *
* A. Ring road ->AC
* Algorithm Adhoc
* Time Limit 30ms
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
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
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 101
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int rsx,rsy;
int n,u,v,c;
int w[maxN][maxN];
void dfs(int u, int pre){
    if (u==1 && pre!=0) return;
    for (int i=1;i<=n;i++)
        if (w[u][i] && pre!=i) {
            if (w[u][i] > 0) rsx+=w[u][i];
            else rsy-=w[u][i];
            dfs(i, u);
            return;
        }
}
void Read_Input(){
    scanf("%d",&n);
    For(i,1,n) {
        scanf("%d %d %d",&u,&v,&c);
        w[u][v] = c;
        w[v][u] = -c;
    }
    rsx = rsy = 0;
    dfs(1, 0);
    cout<< min(rsx,rsy) <<endl;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}
