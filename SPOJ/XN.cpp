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
#define N 2222
#define M 11

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
struct node{
    int t, b[11];
};
node a[N];
int k, groupMax;
int dp[N], n, m;
vi res[N];

bool check(int x, int y) {
    int c1 = 0, c2 = 0;
    for (int i = 1;i <= m;i++) {
        if (a[x].b[i] <= a[y].b[i]) c1++;
        if (a[x].b[i] >= a[y].b[i]) c2++;
    }
    return (c1 == m || c2 == m);
}

bool cmp(node x, node y) {
    int sum1 = 0, sum2 = 0;
    for (int i = 1;i <= m;i++) {
        sum1 += x.b[i];
        sum2 += y.b[i];
    }
    return (sum1 > sum2);
}
int main() {
	freopen("exam.INP","r", stdin); freopen("exam.OUT","w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	fr(i, 1, n) {
	    a[i].t = i;
	    fr(j, 1, m) scanf("%d", &a[i].b[j]);
	}
	sort(a + 1, a + n + 1, cmp);
    fill(dp, 0); groupMax = 0;
    /*for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++)
            printf("%d ", a[i][j]);
            printf("\n");
    }*/
	for (int i = 1;i <= n;i++) {
        for (int j = i - 1;j >= 1;j--)
            if ( check(i, j) ) {
                dp[i] = max(dp[i], dp[j] + 1);
                groupMax = max(groupMax, dp[i]);
            }
	}
	
	for (int i = 1;i <= n;i++) res[dp[i]].pb(a[i].t);
    //cout << groupMax << endl;
	groupMax++;
	
	if (k < groupMax) {
	    puts("-1");
	    return 0;
	}
	if (groupMax < k) {
	    int diff = k - groupMax, j;
	    for (int i = 0;i < groupMax;i++) {
	        if (diff > res[i].size()) {
	            diff -= res[i].size();
	            for (int j = 0;j < res[i].size();j++)
                    printf("%d\n", res[i][j]);
                diff++;
	        }
	        else {
	            for (int j = 0;j < diff;j++)
                    printf("%d\n", res[i][j]);
                for (int j = diff;j < res[i].size();j++) {
                    if (j == res[i].size() - 1) printf("%d", res[i][j]);
                    else printf("%d ", res[i][j]);
                }
                puts("");
                diff = 0;
	        }
	    }
	    return 0;
	}
	for (int i = 0;i < groupMax;i++) {
        for (int j = 0;j < res[i].size();j++) {
            if (j) printf(" ");
            printf("%d", res[i][j]);
        }
        puts("");
    }
	return 0;
}
