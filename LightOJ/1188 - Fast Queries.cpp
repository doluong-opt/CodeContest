/***********************************************
* Author - LUONG VAN DO                        *
* 1188 - Fast Queries ->AC
* Algorithm BIT
* Time Limit 0.318s
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
#define maxN 100005

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef struct node{
    int x, ind;
    node(){}
    node(int xx, int id){
        x = xx; ind = id;
    }
    bool operator < (const node &other) const{
        return (x < other.x);
    }
};
typedef struct query{
    int ind, x, y;
    query(){}
    query(int in, int xx, int yy){
        ind = in; x = xx; y = yy;
    }
    bool operator < (const query &other) const{
        return (y < other.y);
    }
};
int tree[maxN];
node a[maxN], q[maxN];
query qu[maxN];
int res[maxN], n;
void update(int i){
    while (i <= n) {
        tree[i]++;
        i+=(i&-i);
    }
}
int get(int i){
    int sum = 0;
    while ( i ){
        sum+=tree[i];
        i-=(i&-i);
    }
    return sum;
}
bool cmp(node c, node d){
    return c.ind < d.ind;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, k, d;
    scanf("%d",&test);
    FOR(t, 1, test){
        scanf("%d %d",&n,&k);
        FOR(i, 1, maxN - 1) {
            tree[i] = 0;
            q[i].x = q[i].ind = 0;
        }
        FOR(i, 1, n) {
            scanf("%d",&a[i].x);
            a[i].ind = i;
        }
        stable_sort(a + 1, a + n + 1);
        q[1].x = 0;
        q[1].ind = 1;
        FOR(i, 2, n) {
            if (a[i].x == a[i-1].x) q[ a[i].ind ].x = a[i-1].ind;
            q[ a[i].ind ].ind = a[i].ind;
        }
        FOR(i, 1, k) {
            scanf("%d %d",&qu[i].x,&qu[i].y);
            qu[i].ind = i;
        }
        sort(qu + 1, qu + k + 1);
        d = 1;
        FOR(i, 1, k) {
            while (d <= n && q[d].ind<=qu[i].y) {
                if (q[d].x) update(q[d].x);
                ++d;
            }
            res[ qu[i].ind ] = qu[i].y - qu[i].x + 1 - ( get(qu[i].y) - get(qu[i].x - 1) );
        }
        printf("Case %d:\n",t);
        FOR(i, 1, k)
            printf("%d\n",res[i]);
    }
    return 0;
}
