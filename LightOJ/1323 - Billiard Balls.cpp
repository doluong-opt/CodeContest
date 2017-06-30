/***********************************************
* Author - LUONG VAN DO                        *
* 1323 - Billiard Balls ->AC
* Algorithm basic math
* Time Limit 0.048s
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
#define maxN 50001

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int64, int64> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node{
    int64 x, y;
    string d;
};
int64 L, W, n, K;
node balls[maxN];
vector <ii> R;
int64 Posy(int64 y, string di) {
    int64 kk, cnt;
    int64 dy;
    kk = K;
    if (di == "NE" || di == "NW") {
        dy = W - y;
        if (kk >= dy) {
            y = W;
            kk-=dy;
        }
        else {
            y+=kk;
            kk = 0;
        }
        if (!kk) return y;
        cnt = kk / W;
        if ( cnt % 2 != 0) y = 0;
        kk = kk % W;
        if ( cnt % 2 == 0 ) y-=kk;
        if ( cnt % 2 != 0 ) y+=kk;
        return y;
    }
    else
    if (di == "SE" || di == "SW") {
        dy = y;
        if (kk >= dy) {
            y = 0;
            kk-=dy;
        }
        else {
            y-=kk;
            kk = 0;
        }
        if (!kk) return y;
        cnt = kk / W;
        if (cnt % 2 != 0) y = W;
        kk = kk % W;
        if ( cnt % 2 == 0 ) y+=kk;
        if ( cnt % 2 != 0 ) y-=kk;
        return y;
    }
}
int64 Posx(int64 x, string di) {
    int64 kk, cnt;
    int64 dx;
    kk = K;
    if (di == "NE" || di == "SE") {
        dx = L - x;
        if (kk >= dx) {
            x = L;
            kk-=dx;
        }
        else {
            x+=kk;
            kk = 0;
        }
        if (!kk) return x;
        cnt = kk / L;
        if (cnt % 2 != 0) x = 0;
        kk = kk % L;
        if ( cnt % 2 == 0 ) x-=kk;
        if ( cnt % 2 != 0 ) x+=kk;
        return x;
    }
    else
    if (di == "SW" || di == "NW") {
        dx = x;
        if (kk >= dx) {
            x = 0;
            kk-=dx;
        }
        else {
            x-=kk;
            kk = 0;
        }
        if (!kk) return x;
        cnt = kk / L;
        if (cnt % 2 !=0 ) x = L;
        kk = kk % L;
        if ( cnt % 2 == 0 ) x+=kk;
        if ( cnt % 2 != 0 ) x-=kk;
        return x;
    }
}
void find_pos_i(int i) {
    int64 x, y;
    x = Posx(balls[i].x, balls[i].d);
    y = Posy(balls[i].y, balls[i].d);
    R.pb(ii(x, y));
}
void solve() {
    R.clear();
    FOR(i, 1, n)
        find_pos_i( i );
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%lld %lld %lld %lld",&L,&W,&n,&K);        
        FOR(i, 1, n) cin >> balls[i].x >> balls[i].y >> balls[i].d;
        printf("Case %d:\n",t);
        solve();
        sort(R.begin(), R.end());
        REP(i, R.size())
            printf("%lld %lld\n",R[i].A,R[i].B);
    }
    return 0;
}
