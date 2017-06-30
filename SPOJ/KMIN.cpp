/***********************************************
* Author LUONG VAN DO                        *
* Problem KMIN
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
#define N 50010

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
    int x, y;
    node(){}
    node(int xx, int yy){
        x = xx; y = yy;
    }
};
int m, n, k, nheap;
int a[N], b[N];
node heap[N];
int64 f(node key) {
    return a[key.x] + b[key.y];
}
void downHeap(int x, int nheap) {
    node key = heap[x];
    int64 y = f(heap[x]);
    while (2 * x <= nheap) {
        int c = 2 * x;
        if (c < nheap && f(heap[c + 1]) < f(heap[c]) ) ++c;
        if (y <= f(heap[c])) break;
        heap[x] = heap[c];
        x = c;
    }
    heap[x] = key;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 1;i <= m;i++) scanf("%d", &a[i]);
    for (int i = 1;i <= n;i++) scanf("%d", &b[i]);
    sort(b + 1, b + n + 1);
    for (int i = 1;i <= m;i++)
        heap[i] = node(i, 1);
    for (int i = m / 2;i >= 1;i--)
        downHeap(i, m);
    nheap = m;
    while ( k ) {
        printf("%lld\n", f(heap[1]));
        if (heap[1].y < n) heap[1].y++;
        else {
            swap(heap[1], heap[nheap]);
            nheap--;
        }
        downHeap(1, nheap);
        k--;
    }
}
