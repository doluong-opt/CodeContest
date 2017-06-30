/***********************************************
* Author - LUONG VAN DO                        *
* 1369 - Answering Queries ->AC
* Algorithm BIT
* Time Limit 0.264s
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
#define N 1000005
using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n, q;
int64 a[maxN];
int64 tree[N], S, P;
void reset(){
    REP(i, N) tree[i] = 0;
    S = P = 0;
}
void update(int i, int val) {
    while (i<=N) {
        tree[i]+=val;
        i+=(i&-i);
    }
}
int64 get(int i){
    int64 s = 0;
    while ( i ) {
        s+=tree[i];
        i-=(i&-i);
    }
    return s;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, c;
    int64 x, v;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d %d",&n,&q);
        reset();
        FOR(i, 1, n) {
            scanf("%lld",&a[i]);
            update(i, a[i]);
            S+=(n - i) * a[i];
        }
        FOR(i, 2, n)
            P+=(get(n) - get(i - 1));
        printf("Case %d:\n",t);
        while (q--) {
            scanf("%d",&c);
            if (c) printf("%lld\n",S - P);
            else {
                scanf("%lld %lld",&x,&v);
                ++x;
                S = S - (n - x) * a[x];
                P = P - (x - 1) * a[x];
                a[x] = v;
                S = S + (n - x) * a[x];
                P = P + (x - 1) * a[x];
            }
        }
    }
    return 0;
}
