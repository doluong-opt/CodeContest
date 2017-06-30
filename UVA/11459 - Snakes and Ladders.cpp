/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11459 - Snakes and Ladders ->AC
* Algorithm Adhoc
* Time Limit 0.224s
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
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define M 1000010
#define N 110
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
int pos[M];
int next[N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, m, r;
    scanf("%d",&cases);
    while ( cases--) {
        scanf("%d %d %d",&n,&m,&r);
        for (int i=0;i<n;i++) pos[i] = 1;
        for (int i=0;i<N;i++) next[i] = -1;
        for (int i=0, a, b;i<m;i++) {
            scanf("%d %d",&a,&b);
            next[a] = b;
        }
        bool over = false;
        for (int i=0, x, id = -1;i<r;i++) {
            scanf("%d",&x);
            id = (id + 1) % n;
            if (over) continue;
            pos[id] = min(pos[id] + x, 100);
            if (next[ pos[id] ] != -1) pos[id] = next[pos[id]];
            over|=(pos[id] == 100);
        }
        for (int i=0;i<n;i++)
            printf("Position of player %d is %d.\n",i + 1, pos[i]);
    }
}
