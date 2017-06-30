/***********************************************
* Author - LUONG VAN DO                        *
* Problem 
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
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 100111

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
struct node
{
       int data;
       node (){}
       node (int c){data=c;}
};
struct cmp
{
       bool operator ()(const node&a,const node&b){return a.data>=b.data;}
};
int n, ans;
int a[N], pos[N];
multiset <node, cmp> :: iterator it;
multiset <node, cmp> st;
void solve() {
    int u, v, m = 0;
    pos[0] = 1;
    fr(i, 2, n) {        
        if ( a[i] > a[pos[m]] ) {
            pos[++m] = i;
            continue;
        }
        for (u = 0, v = m;u < v;) {
            int c = (u + v) >> 1;
            if ( a[i] > a[pos[c]] ) u = c + 1;
            else v = c;
        }
        if ( a[i] < a[pos[u]]) pos[u] = i;
    }
    printf("%d\n", m + 1);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n);
	fr(i, 1, n) scanf("%d", &a[i]);
	reverse(a + 1, a + n + 1);
	solve();
	return 0;
}
