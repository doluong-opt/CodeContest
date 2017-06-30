/***********************************************
* Author - LUONG VAN DO                        *
* 1097 - Lucky Number ->AC
* Algorithm IT
* Time Limit 0.122s
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
#define maxN 2100005
#define N 100005
#define EM 0.5772156649015328606065120900824
#define M 714716
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct seg{
    int value, total;
} tree[maxN + 5];
int f[N + 5];

int build(int node, int low, int high){
    if ( low == high ) {
        tree[node].value = (2 * low) - 1;
        return tree[node].total = 1;
    }
    int mid, r1, r2;
    mid = (low + high) >> 1;
    r1 = build(2 * node, low, mid);
    r2 = build(2 * node + 1, mid + 1, high);
    return tree[node].total = r1 + r2;
}
void update(int node, int low, int high, int val) {
    tree[node].total--;
    if (low == high) return;
    int mid = (low + high) >> 1;
    if (tree[2 * node].total >=val) update(2 * node, low, mid, val);
    else update(2 * node + 1, mid + 1, high, val - tree[2 * node].total);
}
int query(int node, int low, int high, int val) {
    if (low == high) return tree[node].value;
    int mid = (low + high) >> 1;
    if (tree[2 * node].total >=val) return query(2 * node, low, mid, val);
    else return query(2 * node + 1, mid + 1, high, val - tree[2 * node].total);
}
void init() {
    int k, val;
    f[1] = 1;
    build(1, 1, M);
    for (int i = 2;i<=100000;i++) {
        f[i] = query(1, 1, M, i);
        k = 1;
        val = f[i] * k;
        if (val > tree[1].total) continue;
        do{
            ++k;
            update(1, 1, M, val);
            val = (f[i] * k) - k + 1;
        }while ( val <= tree[1].total );
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, n;
    init();
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        printf("Case %d: %d\n",t, f[n]);
    }
    return 0;
}
