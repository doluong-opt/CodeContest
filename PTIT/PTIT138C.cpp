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
int n, lf, rt;
int a[N];
char s[N];
int f(char c) {
    if (c == 'A' || c == 'B' || c == 'C') return 2;
    if (c == 'D' || c == 'E' || c == 'F') return 3;
    if (c == 'G' || c == 'H' || c == 'I') return 4;
    if (c == 'J' || c == 'K' || c == 'L') return 5;
    if (c == 'M' || c == 'N' || c == 'O') return 6;
    if (c == 'P' || c == 'Q' || c == 'R' || c == 'S') return 7;
    if (c == 'T' || c == 'U' || c == 'V') return 8;
    if (c == 'W' || c == 'X' || c == 'Y' || c == 'Z') return 9;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
    scanf(" %d ", &cases);
    while (cases--) {
        gets(s); n = strlen(s);
        rep(i, n) a[i] = f(toupper(s[i]));
        lf = 0; rt = n - 1;
        while (lf <= rt && a[lf] == a[rt]) {
            lf++; rt--;
        }
        if (lf > rt) puts("YES");
        else puts("NO");
    }
	return 0;
}
