/***********************************************
* Author - LUONG VAN DO                        *
* 793 - Network Connections ->AC
* Algorithm Union
* Time Limit 0.088s
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

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int test,n,rs1,rs2;
int Lab[maxN];
char s[maxN];
int Get(int v){
    if (Lab[v] < 0) return v;
    else return Lab[v] = Get( Lab[v] );
}
void Union(int r1, int r2){
    int x = Lab[r1] + Lab[r2];
    if ( Lab[r1] > Lab[r2] ) {
        Lab[r2] = x;
        Lab[r1] = r2;
    }
    else {
        Lab[r1] = x;
        Lab[r2] = r1;
    }    
}
void Read_Input(){
    char c[5];
    int u,v,x,y,blank = 0;
    scanf("%d",&test);
    for (int i=1;i<=test;i++) {
        scanf("%d ",&n);
        rs1 = rs2 = 0;
        For(i,1,n) Lab[i] = -1;
        while ( gets(s) && strlen(s) ) {            
            sscanf(s,"%s %d %d ",c,&u,&v);
            x = Get( u ); y = Get( v );
                if ( !strcmp(c,"q") )
                    if (x!=y) rs2++;
                    else rs1++;
            else
                if (x!=y) Union(x, y);
        }
        if (blank) puts("");
        blank = 1;
        printf("%d,%d\n",rs1,rs2);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}
