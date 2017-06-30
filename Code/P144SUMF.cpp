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
int x, y, n, m, w;
char s[N];
deque <int> q;
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	scanf(" %d ", &x);
	gets(s); n = strlen(s);
	m = w = 0;
	rep(i, n)
        if (s[i] == 'M') q.push_back(1);
        else q.push_back(0);
    while ( !q.empty() ) {
        y = q.front();
        if (y == 1 && abs(m + 1 - w) <= x) {
            m++; q.pop_front();
        }
        else
        if (y == 0 && abs(w + 1 - m) <= x) {
            w++; q.pop_front();
        }
        else {
            q.pop_front();
            int temp = q.front();
            if (temp == 1 && abs(m + 1 - w) <= x) {
                m++; q.pop_front(); q.push_front(y);
            }
            else
            if (temp == 0 && abs(w + 1 - m) <= x) {
                w++; q.pop_front(); q.push_front(y);
            }
            else break;
        }
    }
    printf("%d\n", m + w);
	return 0;
}
