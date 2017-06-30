/***********************************************
* Author LUONG VAN DO                        *
* Problem 1237	Expert Enough?
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
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
struct node{
    int x, y, id;
    node(){}
    node(int xx, int yy, int idd){
        x = xx; y = yy; id = idd;
    }
};
node P[N];
string Name[N];
bool cmp(node a, node b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, q, X, cnt, pos, caseno = 0;
    char s[N];
    scanf("%d",&cases);
    while (cases--) {
        scanf(" %d ", &n);
        rep(i, n) {
            scanf(" %s %d %d ", s, &P[i].x, &P[i].y);
            P[i].id = i;
            Name[i] = s;
        }
        sort(P, P + n, cmp);
        if ( caseno ) puts("");
        caseno++;
        scanf("%d", &q);
        while (q--) {
            scanf("%d", &X);
            cnt = 0;
            for (int i = 0;i < n;i++) {
                if (X < P[i].x || cnt > 1) break;
                if (X >= P[i].x && X <= P[i].y) {
                    pos = i;
                    cnt++;
                }
            }
            if (cnt == 1) cout << Name[P[pos].id] << endl;
            else cout << "UNDETERMINED" <<endl;
        }
    }
}
