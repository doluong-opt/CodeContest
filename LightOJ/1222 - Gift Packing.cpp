/***********************************************
* Author - LUONG VAN DO                        *
* 1222 - Gift Packing ->AC
* Algorithm max bipartite matching
* Time Limit 0.036s
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
#define maxN 55

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, res, start, finish;
int Trace[maxN];
int matchx[maxN], matchy[maxN];
int fx[maxN], fy[maxN];
int Vx[3*maxN], Vy[3*maxN];
int a[maxN][maxN];
void init() {
    FOR(i, 1, n) {
        matchx[i] = matchy[i] = 0;
        fx[i] = fy[i] = 0;
    }
    /*FOR(i, 1, n) {
        fx[i] = 0;
        FOR(j, 1, n)
            fx[i] = max( fx[i], a[i][j]);
    }*/
}
int Get(int i, int j){
    return a[i][j] - fx[i] - fy[j];
}
void Findway() {
    int i;
    queue <int> Q;
    Q.push( start );
    FOR(j, 1, n) Trace[j] = 0;
    while ( !Q.empty() ) {
        i = Q.front(); Q.pop();
        FOR(j, 1, n)
            if (Trace[j] == 0 && Get(i, j) == 0) {
                Trace[j] = i;
                if ( matchy[j] == 0 ) {
                    finish = j;
                    return;
                }
                Q.push( matchy[j] );
            }
    }
}
bool bs(int Vx[], int x, int l, int r){
    while (l<=r) {
        int mid = (l + r) >> 1;
        if ( Vx[mid] == x ) return true;
        if ( Vx[mid] > x ) r = mid - 1;
        else l = mid + 1;
    }
    return false;
}
int SubX_AddY() {
    int delta, xx, yy;
    xx = yy = 0;
    Vx[++xx] = start;
    FOR(j, 1, n) {
        if ( Trace[j] ) {
            Vx[++xx] = matchy[j];
            Vy[++yy] = j;
        }
    }
    delta = INF;
    sort(Vx+1, Vx + xx + 1);
    sort(Vy+1, Vy + yy + 1);
    FOR(i, 1, n) {
        if ( bs(Vx, i, 1, xx) )
            FOR(j, 1, n)
                if ( !bs(Vy, j, 1, yy) && Get(i,j) < delta) delta = Get(i,j);
    }
    FOR(i, 1, n) {
        if ( bs(Vx, i, 1, xx) ) fx[i] = fx[i] + delta;
        if ( bs(Vy, i, 1, yy) ) fy[i] = fy[i] - delta;
    }
}
void Enlarge() {
    int i, Next;
    do {
        i = Trace[finish];
        Next = matchx[i];
        matchx[i] = finish;
        matchy[finish] = i;
        finish = Next;
    } while ( finish!=0 );
}
void solve() {
    FOR(i, 1, n) {
        start = i; finish = 0;
        do {
            Findway();
            if ( finish == 0 ) SubX_AddY();
        } while ( finish == 0 );
        Enlarge();
    }
    res = 0;
    FOR(i, 1, n) {
        int j = matchx[i];
        res+=a[i][j];
    }
}
void Read() {
    int test;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        FOR(i, 1, n)
            FOR(j, 1, n) {
                scanf("%d",&a[i][j]);
                if (a[i][j] > 0 ) a[i][j] = -a[i][j] - 1001;
                else a[i][j] = -1001;
        }
        init();
        solve();
        res = abs(res);
        res-=(n * 1001);
        printf("Case %d: %d\n",t,res);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
