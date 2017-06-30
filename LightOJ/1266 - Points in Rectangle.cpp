/***********************************************
* Author - LUONG VAN DO                        *
* 1266 - Points in Rectangle ->AC
* Algorithm BIT
* Time Limit 0.347s
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
#define maxN 1002

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int tree[maxN][maxN];
int color[maxN][maxN];
void update(int x, int y, int v) {
    while ( x<maxN ) {
        int y1 = y;
        while (y1<maxN) {
            tree[x][y1]+=v;
            y1+=(y1&-y1);
        }
        x+=(x&-x);
    }
}
int get(int x, int y){
    int s = 0;
    while ( x ) {
        int y1 = y;
        while ( y1 ) {
            s+=tree[x][y1];
            y1-=(y1&-y1);
        }
        x-=(x&-x);
    } 
    return s;
}
int main(){
    /*#ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif*/
    int test, x, y, q, c;
    int x1, y1, x2, y2;
    scanf("%d",&test);
    FOR(t, 1, test) {
        REP(i, maxN)
            REP(j, maxN) tree[i][j] = color[i][j] = 0;
        printf("Case %d:\n",t);
        scanf("%d",&q);
        while (q--) {
            scanf("%d",&c);
            if (c == 0) {
                scanf("%d %d",&x,&y);
                ++x; ++y;
                if ( !color[x][y] ) {
                    color[x][y] = 1;
                    update(x, y, 1);
                }
            }
            else {
                scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                x1++; x2++; y1++; y2++;
                printf("%d\n",get(x2, y2) - get(x1-1,y2) - get(x2,y1-1) + get(x1-1,y1-1));
            }
        }
    }
    return 0;
}
