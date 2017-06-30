/***********************************************
* Author - LUONG VAN DO                        *
* 1058 - Parallelogram Counting ->AC
* Algorithm Adhoc
* Time Limit 0.591s
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
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 1000005

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct point{
    int x, y;
    point(){}
    point(int xx, int yy){
        x = xx; y = yy;
    }
    bool operator <(point other) const{
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    bool operator ==(point other) const {
        return (x==other.x && y==other.y);
    }
};

point a[maxN];
point b[maxN];

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, n, nm, x, y;
    int64 res;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        FOR(i, 1, n) {
            scanf("%d %d",&x,&y);
            b[i] = point(x, y);
        }        
        nm = 0;
        FOR(i, 1, n - 1)
            FOR(j, i + 1, n) {
                    int dx = b[i].x + b[j].x;
                    int dy = b[i].y + b[j].y;
                    a[nm++] = point(dx, dy);
            }
        sort(a,a+nm);
        res = 0; x = 0;
        REP(i, nm-1) {
            if (a[i] == a[i+1]) x++;
            else {
                res+=(x * (x - 1)) / 2;
                x = 1;
            }
        }
        printf("Case %d: %lld\n",t,res);
    }
    return 0;
}
