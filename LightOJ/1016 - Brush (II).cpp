/***********************************************
* Author - LUONG VAN DO                        *
* 1016 - Brush (II) ->AC
* Algorithm nhi phan
* Time Limit 0.174s
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
#define maxN 50005

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct point{
    int x,y;
    point(){}
    point(int xx, int yy){
        x = xx; y = yy;
    }
    bool operator < (point D) const{
        return y < D.y;
    }
};
point p[maxN];
int n,w;
int bs(int l, int r){
    int key = l;
    while (l<=r) {
        int mid = (l + r) >> 1;
        if ( p[mid].y - p[key].y<=w ) l = mid + 1;
        else r = mid - 1;
    }
    return r + 1;
}
void Read_Input() {
    int test,x,y,res,l;
    scanf("%d",&test);
    for (int t=1;t<=test;t++) {
        scanf("%d %d",&n,&w);
        for (int i=1;i<=n;i++) {
            scanf("%d %d",&x,&y);
            p[i] = point(x,y);
        }
        sort(p+1,p+n+1);
        l = 1; res = 0;
        while ( true ) {
            x = bs(l,n);
            if (x > n) break;
            ++res;
            l = x;
        }
        printf("Case %d: %d\n",t,res + 1);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}
