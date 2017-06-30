/***********************************************
* Author - LUONG VAN DO                        *
* Problem 12086 - Potentiometers ->AC
* Algorithm BIT
* Time Limit 0.444s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
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
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define frr(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i=n - 1; i>=0; i--)
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 200010

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask & (~(1 << bit)); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int a[N];
int tree[N], n;
void update(int i, int x) {
    while (i<=n) {
        tree[i]+=x;
        i+=(i&-i);
    }
}
int get(int i) {
    int sum = 0;
    while ( i ) {
        sum+=tree[i];
        i-=(i&-i);
    }
    return sum;
}
int main(){
    /*#ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif*/
    char type[10];
    int caseno = 0, x, y, ans;
    while ( scanf(" %d ",&n) && n) { 
        for (int i=1;i<=n;i++) tree[i] = 0;
        for (int i=1;i<=n;i++) {
            scanf(" %d ",&a[i]);
            update(i, a[i]);
        }
        if ( caseno ) puts("");
        printf("Case %d:\n",++caseno);
        while ( scanf(" %s ",&type) ) {
            if (type[0] == 'E') break;
            scanf(" %d %d ",&x, &y);
            if (type[0] == 'S') {
                update(x, -a[x]);
                update(x, y);
                a[x] = y;
            }
            else printf("%d\n",get(y) - get(x - 1));
        }
    }
}
