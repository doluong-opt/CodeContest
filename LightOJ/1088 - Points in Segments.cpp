/***********************************************
* Author - LUONG VAN DO                        *
* 1088 - Points in Segments ->AC
* Algorithm BIT
* Time Limit 0.322s
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
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 300005
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct point{
    int x,ind;
    point(){}
    point(int xx, int in){
        x = xx; ind = in;
    }
};
point a[maxN];
int n,q,m;
int b[maxN];
int tree[maxN];
void update(int i){
    while (i<=m) {
        tree[i]++;
        i+=(i&-i);
    }
}
int Get(int i){
    int res = 0;
    while ( i ) {
        res+=tree[i];
        i-=(i&-i);
    }
    return res;
}
bool cmp(point a, point b){
    if (a.x!=b.x) return a.x < b.x;
    return false;
}
void Read_Input() {
    int test,u,v;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d %d",&n,&q);
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i].x);
            a[i].ind = i;
        }
        for (int i=1;i<=q;i++) {
            scanf("%d %d",&u,&v);
            ++n;
            a[n].x = u; a[n].ind = n;
            ++n;
            a[n].x = v; a[n].ind = n;
        }
        sort(a+1,a+n+1,cmp); m = 0;
        a[0].x = a[0].x - 1;
        for (int i=1;i<=n;i++) {
            if ( a[i].x > a[i-1].x ) ++m;
            b[ a[i].ind ] = m;
            tree[i] = 0;
        }
        for (int i=1;i<=n-2*q;i++) update( b[i] );
        printf("Case %d:\n",t);
        for (int i=n-2*q+1;i<n;i+=2)
            printf("%d\n",Get(b[i+1]) - Get(b[i] - 1) );
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}
