/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1374 - Confusion in the Problemset ->AC
* Algorithm adhoc
* Time Limit 0.008s
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
int mark[N], x, id;
char s[10 * N];
int getInt(int n) {
    int v = 0;
    while (id < n && s[id] !=' ') v = v * 10 + s[id++] - '0';
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, valid, x, n, caseno = 0, l;
    gets(s); id = 0; cases = getInt(strlen(s));
    while (cases--) {
        gets(s); id = 0; n = getInt(strlen(s));
        valid = 1;
        for (int i=0;i<n;i++) mark[i] = 0;
        gets(s); l = strlen(s); id = 0;
        for (int i=0;i<n;i++) {
            x = getInt(l); ++id;
            if (!valid) break;
            if (x >= n) valid = 0;
            mark[x]++;
        }
        printf("Case %d: ",++caseno);
        if (!valid) puts("no");
        else {
                for (int i=0;i<n/2 && valid;i++)
                    if (mark[i] || mark[n-i-1]) continue;
                else
                    valid = 0;
                for (int i=0;i<n && valid;i++)
                    if (mark[i] >= 3) valid = 0;
                
                for (int i=0;i<n && valid;i++)
                    if (mark[i] == 2 && mark[n-i-1] > 0) valid = 0;
                
                if (n % 2 != 0 && !mark[n/2]) valid = 0;
                
                if (valid) puts("yes");
                else puts("no");
        }
    }
}
