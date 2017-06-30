/***********************************************
* Author - LUONG VAN DO                        *
* 1198 - Karate Competition ->AC
* Algorithm min bipartite matching
* Time Limit 0.005s
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
int n, start, finish;
int fx[maxN], fy[maxN], Trace[maxN];
int matchx[maxN], matchy[maxN];
int Vx[maxN], Vy[maxN];
int a[3][maxN], c[maxN][maxN];
void reset(){
    FOR(i, 1, n)
        FOR(j, 1, n)
            c[i][j] = -1000;
    FOR(i, 1, n) {
        fx[i] = fy[i] = 0;
        matchx[i] = matchy[i] = 0;
    }
}
int Get(int i, int j){
    return c[i][j] - fx[i] - fy[j];
}
void Findway() {
    int i;
    queue <int> Q;
    Q.push( start );
    FOR(j, 1, n) Trace[j] = 0;
    while ( !Q.empty() ) {
        i = Q.front(); Q.pop();
        FOR(j, 1, n) {
            if ( Trace[j] == 0 && Get(i,j) == 0) {
                Trace[j] = i;
                if ( matchy[j] == 0 ){
                    finish = j;
                    return;
                }
                Q.push( matchy[j] );
            }
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
void SubX_AddY(){
    int xx, yy, delta;
    xx = yy = 0;
    Vx[++xx] = start;
    FOR(j, 1, n)
        if ( Trace[j] ) {
            Vx[++xx] = matchy[j];
            Vy[++yy] = j;
        }
    delta = 2 * INF;
    sort(Vx+1,Vx+xx+1);
    sort(Vy+1,Vy+yy+1);
    FOR(i, 1, n)
        if ( bs( Vx, i, 1, xx) )
            FOR(j, 1, n)
                if ( !bs( Vy, j, 1, yy) && Get(i,j) < delta) delta = Get(i,j);
    FOR(i, 1, n) {
        if ( bs(Vx, i, 1, xx) ) fx[i] = fx[i] + delta;
        if ( bs(Vy, i, 1, yy) ) fy[i] = fy[i] - delta;
    }
}
void Enlarge(){
    int i, Next;
    do {
        i = Trace[finish];
        Next = matchx[i];
        matchx[i] = finish;
        matchy[finish] = i;
        finish = Next;
    } while ( finish!=0 );
}
int solve() {
    int ans = 0;
    FOR(i, 1, n) {
        start = i; finish = 0;
        do {
            Findway();
            if ( finish == 0) SubX_AddY();
        } while ( finish == 0 );
        Enlarge();
    }
    FOR(i, 1, n) {
        int j = matchx[i];
        ans+=c[i][j];
    }
    return abs(ans) - n * 1000;
}
void Read() {
    int test;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        reset();
        FOR(j, 1, n) scanf("%d",&a[1][j]);
        FOR(j, 1, n) scanf("%d",&a[2][j]);
        if ( n == 1 && a[1][1] > a[2][1] ) {
            printf("Case %d: 2\n",t);
            continue;
        }
        else
        if (n == 1 && a[1][1] == a[2][1] ) {
            printf("Case %d: 1\n",t);
            continue;
        }
        else
        if (n == 1 && a[1][1] < a[2][1] ) {
            printf("Case %d: 0\n",t);
            continue;
        }
        FOR(i, 1, n)
            FOR(j, 1, n)
                    if ( a[1][i] > a[2][j] ) c[i][j] = -1002;
                else
                    if ( a[1][i] == a[2][j] ) c[i][j] = -1001;
        printf("Case %d: %d\n",t,solve());
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
