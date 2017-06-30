/***********************************************
* Author LUONG VAN DO                        *
* Problem 11610 - Reverse Prime
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
#define N 1000000
#define M 78505
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node{
    int64 x, y;
    node(){}
    node(int64 xx, int64 yy){
        x = xx; y = yy;
    }
} number[M];
vector <int64> primes;
int64 p[N], sz;
int64 treeSum[M], tree[M];
map <int, int> h;
void sieve() {
    for (int i = 1;i < N;i++) p[i] = 1;
    p[1] = 0;
    for (int i = 3;i * i < N;i+=2)
        if (p[i])
            for (int j = i * i;j < N;j+=2 * i) p[j] = 0;
    primes.pb(2);
    for (int i = 3;i < N;i+=2)
        if (p[i]) primes.pb(i);
    sz = primes.size();
}
int64 process(int64 x) {
    int64 y = 0, cnt = 0;
    while ( x ) {
        y = y * 10 + x % 10;
        x/=10;
        cnt++;
    }
    while (cnt < 7) {
        y*=10;
        cnt++;
    }
    return y;
}
bool cmp(node a, node b) {
    return (a.x < b.x);
}
int factor(int64 x){
    int cnt = 0;
    for (int i = 0;primes[i] * (int64)primes[i] <= x;i++)
        while (x % primes[i] == 0) {
            x/=primes[i];
            cnt++;
        }
    if (x > 1) cnt++;
    return cnt;
}
void update(int64 treeSum[], int i, int64 val) {
    while (i <= sz) {
        treeSum[i]+=val;
        i+=(i&-i);
    }
}
int64 getSum(int64 treeSum[], int i) {
    int64 total = 0;
    while ( i ) {
        total+=treeSum[i];
        i-=(i&-i);
    }
    return total;
}
void init() {
    int64 so;
    for (int i = 0;i < sz;i++) {
        so = process(primes[i]);
        number[i] = node(so, factor(so));
        treeSum[i + 1] = tree[i + 1] = 0;
    }
    sort(number, number + sz, cmp);
    for (int i = 0;i < sz;i++) {
        h[number[i].x] = i + 1;
        update(treeSum, i + 1, number[i].y);
        update(tree, i + 1, 1);
    }
}
int binary_sreach(int x, int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (getSum(tree, mid) >= x) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    sieve();
    init();
    char ch;
    int u, x;
    while ( scanf(" %c %d ", &ch, &u) != EOF ) {
        if (ch == 'q') printf("%lld\n", getSum(treeSum, binary_sreach(u + 1, 1, sz)));
        else {
            update(treeSum, h[u], -number[h[u] - 1].y);
            update(tree, h[u], -1);
        }
    }
}
