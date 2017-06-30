/***********************************************
* Author - LUONG VAN DO                        *
* 1112 - Curious Robin Hood ->AC
* Algorithm BIT
* Time Limit 0.280s
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

int n, q;
int64 a[maxN];
int64 tree[maxN];
void update(int i, int x) {
    while (i<=n) {
        tree[i]+=x;
        i+=(i&-i);
    }
}
int64 get(int i) {
    int64 s = 0;
    while ( i ) {
        s+=tree[i];
        i-=(i&-i);
    }
    return s;
}
void Read() {
    int test, query, x, y;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&n,&q);
        FOR(i, 1, n) tree[i] = 0;
        FOR(i, 1, n) {
            scanf("%lld",&a[i]);
            update(i, a[i]);
        }
        printf("Case %d:\n",t);
        while (q--) {
            scanf("%d",&query);
            if (query == 1) {
                scanf("%d",&x);
                ++x;
                printf("%lld\n",a[x]);
                update(x, -a[x]);
                a[x] = 0;
            }
            else
            if (query == 2) {
                scanf("%d %d",&x,&y);
                ++x;
                update(x, y);
                a[x]+=y;
            }
            else
            if (query == 3) {
                scanf("%d %d",&x,&y);
                x++; y++;
                printf("%lld\n",get(y) - get(x-1));
            }
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read();
    return 0;
}
