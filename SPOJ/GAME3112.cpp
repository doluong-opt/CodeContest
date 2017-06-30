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
int day[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int f[33][13], cnt[N], d, m;
void solve(int m, int d) {
    rep(i, 100) cnt[i] = 0;
    for (int i = d + 1;i <= day[m];i++)
        cnt[f[i][m]]++;
    for (int i = m + 1;i <= 12;i++)
        if (d <= day[i]) cnt[f[d][i]]++;
    int k = 0;
    while (k < 100 && cnt[k]) k++;
    f[d][m] = k;
}
void init() {
    fill(f, -1);
    f[31][12] = f[30][12] = f[29][11] = f[31][10] = 0;
    for (int i = 12;i >= 1;i--)
        for (int j = day[i];j >= 1;j--)
            if (f[j][i] == -1) solve(i, j);
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	init();
	scanf("%d %d", &d, &m);
	if ( f[d][m] == 0 ) puts("LOSS");
	else {
	    int flag = 0;
	    for (int i = d + 1;i <= day[m];i++)
            if ( f[i][m] == 0 ) {
                flag = 1;
                d = i;
                break;
            }
        if (flag) {
            printf("%d %d\n", d, m);
            return 0;
        }
        for (int i = m + 1;i <= 12;i++)
            if ( f[d][i] == 0 ) {
                flag = 1;
                m = i;
                break;
            }
        if (flag) printf("%d %d\n", d, m);
	}
	return 0;
}
