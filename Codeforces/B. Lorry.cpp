/***********************************************
* Author - LUONG VAN DO                        *
* Problem B. Lorry ->AC
* Algorithm adhoc
* Time Limit 140ms
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
#define M 100010

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

struct point{
    int x, y;
    point(){}
    point(int xx, int yy) {
        x = xx; y = yy;
    }
};
int n, m;
point d1[M], d2[M];
vector <int> res;
int c1[M], c2[M];
ii edge[M];
bool cmp(point a, point b) {
    return a.x > b.x;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int ans, p1, p2;
    int n1, n2, x, y;
    scanf("%d %d",&n,&m);
    n1 = n2 = 0;
    memset(c1, 0, sizeof(c1));
    memset(c2, 0, sizeof(c2));
    for (int i=1;i<=n;i++) {
        scanf("%d %d",&x,&y);
        if (x == 1)
            d1[++n1] = point(y, i);
        else
            d2[++n2] = point(y, i);
    }
    sort(d1 + 1, d1 + n1 + 1, cmp);
    sort(d2 + 1, d2 + n2 + 1, cmp);
    c1[0] = c2[0] = 0;
    for (int i=1;i<=n1;i++)
        c1[i] = c1[i-1] + d1[i].x;
    for (int i=1;i<=n2;i++)
        c2[i] = c2[i-1] + d2[i].x;
    ans = p1 = p2 = 0;
    for (int i=0;i<=n1;i++) {
        x = i;
        y = (m - x) / 2;
        y = min(y, n2);
        edge[i] = ii(x, y);
    }
    for (int i=0;i<=n1;i++) {
        if (edge[i].A >=0 && edge[i].B >=0) {
            if (edge[i].A + 2 * edge[i].B <= m) {
                if (edge[i].A<= n1 && edge[i].B <= n2)
                if (ans < c1[edge[i].A] + c2[edge[i].B]) {
                    ans = c1[edge[i].A] + c2[edge[i].B];
                    p1 = edge[i].A;
                    p2 = edge[i].B;
                }
            }
        }
    }
    printf("%d\n",ans);
    for (int i=1;i<=p1;i++)
        res.pb(d1[i].y);
    for (int i=1;i<=p2;i++)
        res.pb(d2[i].y);
    for (int i=0;i<res.size();i++) {
        if (i > 0) printf(" ");
        printf("%d",res[i]);
    }
    printf("\n");
}
