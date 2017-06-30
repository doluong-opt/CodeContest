/***********************************************
* Author - LUONG VAN DO                        *
* 11503 - Virtual Friends ->AC
* Algorithm Union
* Time Limit 2.632s
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
#define maxN 100005
using namespace std;

int Lab[maxN];
map <string, int> idx;
string x,y;
int Get(int v){
    if ( Lab[v] < 0) return v;
    else return Lab[v] = Get( Lab[v] );
}
void Read_Input(){
    int test, m, u,v, cnt;
    cin >> test;
    for (int i=1;i<=test;i++){
        cin >> m; cnt = 1;
        idx.clear();
        for (int j=1;j<=maxN;j++) Lab[j] = -1;
        for (int k=1;k<=m;k++) {
            cin >> x >> y;
            if (!idx[x]) idx[x] = cnt++;
            if (!idx[y]) idx[y] = cnt++;
            u = Get( idx[x] ); v = Get( idx[y] );
                if (u == v ) {
                    printf("%d\n",Lab[u] * -1);
                    continue;
                }
                
                if ( Lab[u] < Lab[v] ) {
                    Lab[u] += Lab[v];
                    Lab[v] = u;
                    printf("%d\n",Lab[u] * -1);
                }
                else {
                    Lab[v] += Lab[u];
                    Lab[u] = v;
                    printf("%d\n",Lab[v] * -1);
                }
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}
