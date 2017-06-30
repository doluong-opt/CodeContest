/***********************************************
* Author LUONG VAN DO                        *
* Problem CAR
* Algorithm
* Time Limit
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

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 111222333
#define N 100000

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
struct node{
    int x, y, ind;
    node(){}
    node(int xx, int yy, int inn){
        x = xx; y = yy; ind = inn;
    }
    bool operator < (const node& other) const{
        if ( y * other.x != x * other.y ) return y * other.x < x * other.y;
        return x < other.x;
    }
};
node p[N];
int n;
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int64 ans, ti;
    scanf("%d",&n);
    fr(i, 1, n) {
        scanf("%d",&p[i].x);
        p[i].ind = i;
    }
    fr(i, 1, n) scanf("%d",&p[i].y);
    sort(p + 1, p + n + 1);
    ans = ti = 0;
    fr(i, 1, n) {
        ti+=p[i].y;
        ans+=ti * p[i].x;
    }
    printf("%lld\n", ans);
    fr(i, 1, n) {
        if (i > 1) printf(" ");
        printf("%d",p[i].ind);
    }
    puts("");
}
