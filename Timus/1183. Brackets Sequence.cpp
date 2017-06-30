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
#define N 111

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
char s[N];
int n, best, dp[N][N];
int solve(int l, int r) {
    if (l > r) return 0;
    int &res = dp[l][r];
    if (res != -1) return res;
    res = 1 + solve(l + 1, r);
    if (s[l] == '(' || s[l] == '[') {
        for (int i = l + 1;i <= r;i++)
            if ( (s[l] == '(' && s[i] == ')') || (s[l] == '[' && s[i] == ']') )
                res = min(res, solve(l + 1, i - 1) + solve(i + 1, r));
    }
    return res;
}
void findAnswer(int l, int r) {
    if (l > r) return;
    int res = solve(l, r);
    if (res == 1 + solve(l + 1, r)) {
        if (s[l] == '(' || s[l] == ')') {
            printf("(");
            printf(")");
        }
        else {
            printf("[");
            printf("]");            
        }
        findAnswer(l + 1, r);
        return;
    }
    for (int i = l + 1;i <= r;i++)
        if (((s[l] == '(' && s[i] == ')' ) || (s[l] == '[' && s[i] == ']')) && res == solve(l + 1, i - 1) + solve(i + 1, r) ) {
            if (s[l] == '(') {
                printf("(");
                findAnswer(l + 1, i - 1);
                printf(")");
                findAnswer(i + 1, r);
            }
            else {
                printf("[");
                findAnswer(l + 1, i - 1);
                printf("]");
                findAnswer(i + 1, r);
            }
            return;
        }
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	gets(s); n = strlen(s);
	fill(dp, -1);
	best = solve(0, n - 1);
	findAnswer(0, n - 1);
	puts("");
	return 0;
}
