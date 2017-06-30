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
int64 sz, p, cur, x, y, add, first, last, cnt;
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while (scanf("%lld %lld", &sz, &p) && (sz + p)) {
	    if (p == 1) {
	        printf("Line = %lld, column = %lld.\n", sz / 2 + 1, sz / 2 + 1);
	        continue;
	    }
	    for (int i = 1;i <= sz - 2;i += 2)
	        if ( i * i <= p && p <= (i + 2) * (i + 2) ) {
	            cur = i + 2;
	            break;
	        }
        if (cur * cur == p) {
            printf("Line = %lld, column = %lld.\n", sz / 2 + (cur / 2) + 1, (sz / 2) + (cur / 2) + 1);
            continue;
        }
        
        first = (cur - 2) * (cur - 2) + 1; cur = cur / 2 + 1; add = 2 * cur - 3; last = first + add;
        x = sz / 2 + cur; y = x - 1; cnt = 0;
        while ( true ) {
            if ( first <= p && p <= last ) break;
            first = last + 1; last = first + add; cnt++;            
            if (cnt == 1) {
                y -= add;
                x--;
            }
            if (cnt == 2) {
                x -= add;
                y++;
            }
            if (cnt == 3) {
                y += add;
                x++;
            }
        }
        for (int i = first;i <= last;i++)
            if (p != i) {
                if (cnt == 0) y--;
                if (cnt == 1) x--;
                if (cnt == 2) y++;
                if (cnt == 3) x++;
            }
            else break;
        printf("Line = %lld, column = %lld.\n", x, y);
	}
	return 0;
}
