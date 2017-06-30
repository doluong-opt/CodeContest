/***********************************************
* Author - LUONG VAN DO                        *
* 1301 Monitoring Processes ->AC
* Algorithm mutiset
* Time Limit 0.394s
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
#define maxN 50005

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct state{
    int x, y;
    state(){}
    state(int xx, int yy){
        x = xx; y = yy;
    }
};
state RR[maxN];
bool cmp(state a, state b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
int max(int a, int b){
    return (a > b) ? a : b;
}
void Read() {
    int test, L, R, ans, n, si, ti;
    scanf("%d",&test);
    FOR(t, 1, test) {
        ans = 1;
        scanf("%d",&n);
        FOR(i, 1, n) {
            scanf("%d %d",&si,&ti);
            RR[i] = state(si, ti);
        }
        sort(RR+1, RR+n+1,cmp);
        multiset <int> S;
        multiset <int>::iterator it;
        S.insert( RR[1]. y );
        FOR(i, 2, n) {
            it = S.begin();
            if ( RR[i].x <= (*it) ) {
                ans++;
                S.insert( RR[i].y );
            }
            else {
                S.erase( it );
                S.insert( RR[i].y );
            }
        }
        printf("Case %d: %d\n",t,ans);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
