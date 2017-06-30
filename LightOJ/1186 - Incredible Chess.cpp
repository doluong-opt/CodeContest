/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1186 - Incredible Chess ->AC
* Algorithm nim
* Time Limit 0.000s
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
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1010

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
int a[N], b[N];
int id;
char s[N];
int getInt(int m) {
    int v = 0;
    while (id < m && s[id] !=' ') v = v * 10 + s[id++] - '0';
    ++id;
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, nim, caseno = 0, n, m;
    gets(s); id = 0; cases = getInt(strlen(s));
    while (cases--) {
        gets(s); id = 0; n = getInt(strlen(s));
        nim = 0;
        gets(s); id = 0; m = strlen(s);
        for (int i=0;i<n;i++) a[i] = getInt(m);
        gets(s); id = 0; m = strlen(s);
        for (int i=0;i<n;i++) b[i] = getInt(m);
        for (int i=0;i<n;i++)
            nim^=(b[i] - a[i] - 1);
        printf("Case %d: ",++caseno);
        if (nim) puts("white wins");
        else puts("black wins");
    }
}
