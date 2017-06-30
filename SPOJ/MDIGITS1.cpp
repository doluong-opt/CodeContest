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
int n, m, num, digit, flag, first, last;
int amount[11], res[N][2], mark[N], q[N + N], pre[N];
int bfs(int x, int y, int n, int flag) {
    int num, r, ok, ndigit, u;
    rep(i, n) mark[i] = 0; ok = 0;
    if (x != 0) {
        first = last = 0; q[0] = 0; pre[0] = -1;
    }
    else {
        first = last = 0; q[0] = y; pre[0] = -1;
    }
    while (first <= last) {
        num = q[first++];
        if ( mark[num] ) continue;
        mark[num] = 1;
        r = (num * 10 + x) % n;
        q[++last] = r;
        pre[last] = first - 1;
        if (!r) {
            ok = 1;
            break;
        }
        
        r = (num * 10 + y) % n;
        q[++last] = r;
        pre[last] = first - 1;
        
        if (!r) {
            ok = 1;
            break;
        }
    }
    if (!ok) return -1;
    ndigit = 0;
    for (u = last; pre[u] != -1;u = pre[u]) {
        if (u & 1) res[ndigit++][flag] = x;
        else res[ndigit++][flag] = y;
    }
    if (!x) res[ndigit++][flag] = y;
    return ndigit;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	while ( scanf("%d", &n) && n) {
	    if (n == 1) {
	        printf("1\n");
	        continue;
	    }
	    amount[0] = n; digit = 0;
	    for (int i = 1;i <= 9;i++) {
	        amount[i] = 1; num = 0;
	        while ( amount[i] < n ) {
	            num = (num * 10 + i) % n;
	            if (!num) break;
	            amount[i]++;
	        }
	        if (amount[i] < amount[digit]) digit = i;
	    }
	    if ( digit ) {
            rep(i, amount[digit]) printf("%d", digit);
            puts("");
            continue;
	    }
	    digit = n; flag = 0;
	    fr(i, 0, 9)
            fr(j, i + 1, 9) {
                m = bfs(i, j, n, flag);
                if (m != -1 && m < digit) {
                    flag ^= 1;
                    digit = m;
                }
                else
                if (m == digit) {
                    repr(k, digit)
                        if ( res[k][flag] < res[k][flag ^ 1] ) {
                            flag ^= 1;
                            break;
                        }
                        else if ( res[k][flag] > res[k][flag ^ 1] ) break;
                }
            }
        repr(i, digit) printf("%d", res[i][flag ^ 1]);
        puts("");
	}
	return 0;
}
