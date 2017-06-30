/***********************************************
* Author - LUONG VAN DO                        *
* 231 - Testing the CATCHER ->AC
* Algorithm Lis
* Time Limit 0.008s
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
int m;
int a[maxN], c[maxN];
int Lis(){
    int mm = 0, u, v;
    int b[maxN];
    b[mm] = 0;
    for (int i=1;i<m;i++) {
        if ( a[i] > a[ b[mm] ] ) {
            b[++mm] = i;
            continue;
        }
        for (u=0, v=mm; u < v;) {
            int c = (u + v) >> 1;
            if ( a[i] > a[ b[c] ] ) u = c + 1;
            else v = c;
        }
        if (a[i] < a[ b[u] ])
            b[u] = i;
    }
    return mm + 1;
}
void Read_Input(){
    int v,n,test,blank;    
    test = blank = 0;
    while ( scanf("%d",&n) && n!=-1) {
        m = 0;
        c[++m] = n;
        while ( scanf("%d",&v) ) {
            if (v==-1) break;
            c[++m] = v;
        }
        for (int i=1;i<=m;i++) a[i-1] = c[m-i+1];
        if (blank) puts("");
        blank = 1;
        printf("Test #%d:\n",++test);
        printf("  maximum possible interceptions: %d\n",Lis());
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}
