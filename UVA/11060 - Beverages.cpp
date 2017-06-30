/***********************************************
* Author - LUONG VAN DO                        *
* 11060 - Beverages ->AC
* Algorithm sort Topo
* Time Limit 0.016s
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
#define maxN 105
using namespace std;
string idx[maxN];
map <string, int> Name;
string x,y;
int adj[maxN][maxN];
int id[maxN], mark[maxN];
int n,m,ind;
void Solve(int Case){
    int ok = 0;
    printf("Case #%d: Dilbert should drink beverages in this order:",Case);
    while (!ok) {
        ok = 1;
        For(i,1,n)
            if (!mark[i] && !id[i]) {
                ok = 0;
                mark[i] = 1;
                cout<<" "<<idx[i];
                For(j,1,n)
                    if (adj[i][j]) id[j]--;
                    i = 0;
            }        
    }
    puts(".");
    puts("");
}
void Read_Input(){
    int u,v,Case = 0;
    while (scanf("%d",&n)!=EOF){
        Name.clear();
        For(i,1,n) {
            mark[i] = id[i] = 0;
            For(j,1,n) adj[i][j] = 0;
        }
        For(i,1,n) {
            cin >> x;
            Name[x] = i;
            idx[i] = x;
        }
        scanf("%d",&m);
        For(i,1,m) {
            cin >> x >> y;
            u = Name[x]; v = Name[y];
            if (!adj[u][v]) {
                adj[u][v] = 1;
                id[v]++;
            }
        }
        Solve(++Case);
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
