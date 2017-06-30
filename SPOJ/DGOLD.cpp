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
#define N 600000

using namespace std;

inline int64 max(int64 a, int64 b) { return a > b ? a : b; }
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
    node(int _x, int _y){
        x = _x; y = _y;
    }
};
int n, pos, ans, a[25];
vector <node> A, B, AA, BB;
void recurA(int cur, int s1, int s2) {
    if (cur == n / 2 + 1) {
        A.pb(node(abs(s1 - s2), max(s1, s2)));
        return;
    }
    recurA(cur + 1, s1 + a[cur], s2);
    recurA(cur + 1, s1, s2 + a[cur]);
    recurA(cur + 1, s1, s2);
}
void recurB(int cur, int s1, int s2) {
    if (cur == n + 1) {
        B.pb(node(abs(s1 - s2), max(s1, s2)));
        return;
    }
    recurB(cur + 1, s1 + a[cur], s2);
    recurB(cur + 1, s1, s2 + a[cur]);
    recurB(cur + 1, s1, s2);
}
bool cmp(node a, node b) {
    if (a.x != b.x) return (a.x < b.x);
    return a.y > b.y;
}
int findPos(int key, int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if ( BB[mid].x == key ) return mid;
        if ( BB[mid].x > key ) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf("%d", &n);
    fr(i, 1, n) scanf("%d", &a[i]);
	recurA(1, 0, 0);
	recurB(n / 2 + 1, 0, 0);
	//cout<<A.size()<<" "<<B.size()<<endl;
	sort(A.begin(), A.end(), cmp);
	AA.pb(A[0]);
	for (int i = 1;i < A.size();i++) {
        if (A[i].x == A[i - 1].x) continue;
        AA.pb(A[i]);
	}
	sort(B.begin(), B.end(), cmp);
	BB.pb(B[0]);
	for (int i = 1;i < B.size();i++) {
	    if (B[i].x == B[i - 1].x) continue;
	    BB.pb(B[i]);
	}
	ans = 0;
	for (int i = 0;i < AA.size();i++) {
	    pos = findPos(AA[i].x, 0, BB.size() - 1);
	    if (pos != -1) ans = max(ans, AA[i].y + BB[pos].y - AA[i].x);
	}
    printf("%d\n", ans);
	return 0;
}
