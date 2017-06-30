/***********************************************
* Author LUONG VAN DO                        *
* Problem DTTUI1
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
#define N 45
#define M 1048580
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
struct box{
    int64  x, y;
    box(){}
    box(int64 xx, int64 yy){
        x = xx; y = yy;
    }
    bool operator < (const box& other) const{
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};
vector <box> A;
vector <box> :: iterator it;
box B[M], C[M];
int n, m, nb, nc;
box a[N];
int64 ans;
void TryA(int i, int64 weight, int64 cost) {
    if (i == n / 2) {
        if (weight <= m) {
            A.pb(box(weight, cost));
            if (cost > ans) ans = cost;
        }
        return;
    }
    for (int j = 0;j <= 1;j++) {
        weight+=j * a[i].x;
        cost+=j * a[i].y;
        TryA(i + 1, weight, cost);
    }
}
void TryB(int i, int64 weight, int64 cost) {
    if (i == n) {
        if (weight <= m) {
            B[nb++] = box(weight, cost);
            if (cost > ans) ans = cost;
        }
        return;
    }
    for (int j = 0;j <= 1;j++) {
        weight+=j * a[i].x;
        cost+=j * a[i].y;
        TryB(i + 1, weight, cost);
    }
}
int binary(int64 key, int l, int r) {
    int pos = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (key + C[mid].x <= m) {
            pos = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return pos;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    scanf("%d %d", &n, &m);
    rep(i, n)
        scanf("%lld %lld", &a[i].x, &a[i].y);
    ans = 0;
    TryA(0,0,0);
    TryB(n / 2, 0, 0);
    sort(B, B + nb);
    C[0].y = -1; nc = 0;
    rep(i, nb)
        if (B[i].y > C[nc].y) C[++nc] = B[i];
    for (it = A.begin(); it != A.end(); it++) {
        int pos = binary(it->x, 1, nc);
        if (pos != -1 && (it->y + C[pos].y > ans)) ans = it->y + C[pos].y;
    }
    printf("%lld\n", ans);
}
