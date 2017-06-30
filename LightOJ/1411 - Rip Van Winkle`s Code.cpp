/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1411 - Rip Van Winkle`s Code 
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
#define INF -100010
#define N 250010

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
    int64 no, sum;
};
node tree[8 * N];
int64 value(int st, int nd) {
    if (st > nd ) return 0;
    int64 n = nd - st + 1;
    return (n * (n + 1)) / 2;
}
void build_tree(int pos, int l, int r) {
    tree[pos].no = 0;
    tree[pos].sum = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build_tree(pos<<1, l, mid);
    build_tree((pos<<1) | 1, mid + 1, r);
}
void update1(int pos, int x, int y, int l, int r) {
    if (y < l || x > r) return;
    if (x<=l && r<=y) {
        int nx = l - x + 1;
        int ny = r - x + 1;
        int64 v = value(1, ny) - value(1, nx - 1);
        tree[pos].no += v;
        tree[pos].sum += v;
        return;
    }
    int mid = (l + r) >> 1;
    if (tree[pos].no != 0) {
        int ll = mid - l + 1;
        int rr = r - mid;
        ll = ll - x + 1;
        rr = rr - x + 1;
        tree[pos<<1].sum+=value(1, ll) - value(1, l - 1);
        tree[(pos<<1) | 1].sum+=value(1, rr) - value(1, mid - 1);
        tree[pos].sum = 0;
        tree[pos<<1].no += tree[pos].no;
        tree[(pos<<1)|1].no += tree[pos].no;
        tree[pos].no = 0;
    }
    update1(pos<<1, x, y, l, mid);
    update1((pos<<1) | 1, x, y, mid + 1, r);
    tree[pos].sum = tree[pos<<1].sum + tree[(pos<<1) | 1].sum;
}
void update2(int pos, int x, int y, int l, int r) {
    if (y < l || x > r) return;
    if (x<=l && r<=y) {
        int ny = y - l + 1;
        int nx = y - r + 1;
        int64 v = value(1, ny) - value(1, nx - 1);
        tree[pos].no += v;
        tree[pos].sum += v;
        return;
    }
    int mid = (l + r) >> 1;
    if (tree[pos].no != 0) {
        int ll = mid - l + 1;
        int rr = r - mid;
        ll = y - ll + 1;
        rr = y - rr + 1;
        tree[pos<<1].sum+=value(1, rr) - value(1, l - 1);
        tree[(pos<<1) | 1].sum+=value(1, ll) - value(1, mid - 1);
        tree[pos].sum = 0;
        tree[pos<<1].no += tree[pos].no;
        tree[(pos<<1)|1].no += tree[pos].no;
        tree[pos].no = 0;
    }
    update2(pos<<1, x, y, l, mid);
    update2((pos<<1) | 1, x, y, mid + 1, r);
    tree[pos].sum = tree[pos<<1].sum + tree[(pos<<1) | 1].sum;
}
void update3(int pos, int x, int y, int l, int r, int val) {
    if (y < l || x > r) return;
    if (x<=l && r<=y) {
        tree[pos].no = val;
        tree[pos].sum = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (tree[pos].no != 0) {
        tree[pos<<1].sum = (int64)(mid - l + 1) * tree[pos].no;
        tree[(pos<<1) | 1].sum = (int64)(r - mid) * tree[pos].no;
        tree[pos].sum = 0;
        tree[pos<<1].no = tree[pos].no;
        tree[(pos<<1)|1].no = tree[pos].no;
        tree[pos].no = 0;
    }
    update3(pos<<1, x, y, l, mid, val);
    update3((pos<<1) | 1, x, y, mid + 1, r, val);
    tree[pos].sum = tree[pos<<1].sum + tree[(pos<<1) | 1].sum;
}
int64 get(int pos, int x, int y, int l, int r) {
    if (y < l || x > r) return 0;
    if (x<=l && r<=y) return tree[pos].sum;
    int mid = (l + r) >> 1;
    if (tree[pos].no != 0) {
        tree[pos<<1].no+= tree[pos].no;
        tree[(pos<<1)|1].no+= tree[pos].no;
        tree[pos].no = 0;
    }
    return get(pos<<1, x, y, l, mid) + get((pos<<1) | 1, x, y, mid + 1, r);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, st, nd, x, caseno = 0, q;
    char ques;
    scanf("%d",&cases);
    while (cases--) {
        scanf(" %d ",&q);
        build_tree(1, 1, 10);
        printf("Case %d:\n",++caseno);
        while (q--) {
            scanf("%c",&ques);
            if (ques == 'A' || ques == 'B') {
                scanf(" %d %d ",&st, &nd);
                if (ques == 'A' ) update1(1, st, nd, 1, 10);
                else update2(1, st, nd, 1, 10);
                for (int i=1;i<=25;i++) cout<<tree[i].no<<" ";
                cout<<endl;
                for (int i=1;i<=25;i++) cout<<tree[i].sum<<" ";
                cout<<endl;
                cout<<endl;
            }
            else
            if (ques == 'C') {
                scanf(" %d %d %d ",&st, &nd, &x);
                update3(1, st, nd, 1, 10, x);
            }
            else
            if (ques == 'S') {
                scanf( "%d %d ",&st, &nd);
                printf("%lld\n",get(1, st, nd, 1, 10));
            }
        }
    }
}
