/***********************************************
* Author - LUONG VAN DO                        *
* 1199 - Partitioning Game ->AC
* Algorithm Sprague - Grundy
* Time Limit 0.102s
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
#define maxN 50001

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int id;
char s[10000];
int f[10010], mark[10010];
int getInt(int m) {
    int v = 0;
    while (id < m && s[id] !=' ') v = v * 10 + s[id++] - '0';
    ++id;
    return v;
}
int cal(int x) {
    int y = x;
    x>>=1;
    memset(mark, 0, sizeof(mark));
    for (int i=1;i<=x;i++)
        if (i * 2 != y) mark[f[i]^f[y-i]] = 1;
    for (int i=0;;++i)
        if (!mark[i]) return i;
}
void build() {
    f[1] = f[2] = 0;
    for (int i=3;i<=10000;i++)
        f[i] = cal(i);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, nim, m, x;
    int caseno = 0;
    gets(s); id = 0; cases = getInt(strlen(s));
    build();
    while (cases--) {
        gets(s); id = 0; n = getInt(strlen(s));
        gets(s); id = 0; m = strlen(s);
        nim = 0;
        while (n--) {
            x = getInt(m);
            nim^=f[x];
        }
        if (nim) printf("Case %d: Alice\n",++caseno);
        else printf("Case %d: Bob\n",++caseno);
    }
}
