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
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i = b;i >= a;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define pb push_back
#define ff first
#define ss second
#define fill(arr, val) memset(arr, val, sizeof(arr))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint32 unsigned int
#define INF 1000000000
#define N 100100

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
int n, q, x, y;
int numberofZero, numberofNeg, numberofPos;
int pos[N], neg[N], zero[N], a[N];
char c;
void update(int tree[], int x, int val) {
    while (x <= n) {
        tree[x] += val;
        x += (x & -x);
    }
}
int get(int tree[], int x) {
    int total = 0;
    while ( x ) {
        total += tree[x];
        x -= (x & -x);
    }
    return total;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while ( scanf(" %d %d ", &n, &q) != EOF) {
	    fr(i, 1, n) {
	        scanf(" %d ", &a[i]);
            pos[i] = neg[i] = zero[i] = 0;
	    }
	    fr(i, 1, n)
            if (a[i] > 0) update(pos, i, 1);
        else 
            if (a[i] < 0) update(neg, i, 1);
        else update(zero, i, 1);
        fr(i, 1, q) {
            scanf(" %c %d %d ", &c, &x, &y);
            if (c == 'C') {
                if (a[x] < 0) update(neg, x, -1);
                else
                if (a[x] > 0) update(pos, x, -1);
                else update(zero, x, -1);
                a[x] = y;
                if (y < 0) update(neg, x, 1);
                else
                if (y > 0) update(pos, x, 1);
                else update(zero, x, 1);
            }
            else {
                numberofZero = get(zero, y) - get(zero, x - 1);
                numberofPos = get(pos, y) - get(pos, x - 1);
                numberofNeg = get(neg, y) - get(neg, x - 1);
                if (numberofZero > 0) printf("0");
                else 
                if (numberofNeg & 1) printf("-");
                else printf("+");
            }
        }
        puts("");
	}
	return 0;
}
