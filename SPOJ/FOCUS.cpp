/***********************************************
* Author LUONG VAN DO                        *
* Problem FOCUS
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
#define N 100010
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
    int num, k, a, b;
    node(){}
    node(int _num, int _k, int _a, int _b) {
        num = _num; k = _k; a = _a; b = _b;
    }
};
int n, m;
node q[2 * N];
int s[6 * N], si, id[6 * N], tree[6 * N];
int binary(int x, int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (id[mid] == x) return mid;
        if (x > id[mid]) l = mid + 1;
        else r = mid - 1;
    }
    return 0;
}
void update(int x, int k) {
    while (x <= m) {
        tree[x]+=k;
        x+=(x&-x);
    }
}
int get(int x) {
    int total = 0;
    while ( x ) {
        total+=tree[x];
        x-=(x&-x);
    }
    return total;
}

int fl(int x, int l, int r) {
    int temp = get(l - 1);
    while (l <= r) {
        int mid = (l + r) >> 1;
        if ( get(mid) - temp >= x )
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    char ch;
    si = m = 0;
    scanf(" %d ", &n);
    for (int i = 1;i <= n;i++) {
        scanf("%c", &ch);
        if (ch == '+') {
            q[i].num = 1;
            scanf(" %d ", &q[i].a);
            s[++si] = q[i].a;
        }
        else
        if (ch == '-') {
            q[i].num = 2;
            scanf(" %d ", &q[i].a);
            s[++si] = q[i].a;
        }
        else
        if (ch == '?') {
            q[i].num = 3;
            scanf(" %d %d %d ", &q[i].k, &q[i].a, &q[i].b);
            s[++si] = q[i].k;
            s[++si] = q[i].a;
            s[++si] = q[i].b;
        }
    }
    sort(s + 1, s + si + 1);
    s[0] = -1;
    for (int i = 1;i <= si;i++)
        if (s[i] > s[i - 1]) id[++m] = s[i];

    for (int i = 1;i <= n;i++) {
        q[i].a = binary(q[i].a, 1, m);
        if (q[i].num == 3)
            q[i].b = binary(q[i].b, 1, m);
    }
    
    for (int i = 0;i <= m;i++) tree[i] = 0;
    
    for (int i = 1;i <= n;i++) {
        if (q[i].num == 1)
            update(q[i].a, 1);
        if (q[i].num == 2)
            update(q[i].a, -1);
            
        if (q[i].num == 3) {
            int temp = get(q[i].b) - get(q[i].a - 1);
            if (temp < q[i].k)
                puts("0");
            else
                printf("%d\n", id[fl(q[i].k, q[i].a, q[i].b)]);
        }
    }
}
