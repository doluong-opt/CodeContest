/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11926 - Multitasking ->AC
* Algorithm adhoc
* Time Limit 0.056s
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
#define N 1000010

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
int mark[N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, m, u, v, f, k;
    int x, y;
    while ( scanf("%d %d",&n,&m) && (n + m)){
        f = 1;
        for (int i=0;i<=1000000;i++) mark[i] = 0;
        for (int i=0;i<n;i++) {
            scanf("%d %d",&u,&v);
            if (u > v) swap(u, v);
            if (u != v) v--;
            for (int j=u;j<=v && f;j++)
                if ( !mark[j] ) mark[j] = 1;
                else f = 0;
        }
        for (int i=0;i<m;i++) {
            scanf("%d %d %d",&u,&v,&k);
            if (u > v) swap(u, v);
            x = u;
            y = v;
            if (!f) continue;
            if (u != v) v--;
            for (int j=u;j<=v;j++)
                if ( !mark[j] ) mark[j] = 1;
                else f = 0;
            while ( f ) {
                x +=k;
                y +=k;
                if ( x > 1000000 ) break;
                if (x != y) y--;
                for (int j=x;j<=min(y, 1000000);j++)
                    if ( !mark[j] ) mark[j] = 1;
                    else f = 0;
                y++;
            }
        }
        if (f) puts("NO CONFLICT");
        else puts("CONFLICT");
    }
}
