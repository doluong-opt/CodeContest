/***********************************************
* Author - LUONG VAN DO                        *
*
* Algorithm
* Time
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <stack>
#include <vector>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <set>

#define fill(ar, val) memset(ar, val, sizeof(ar))
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0;i<n;i++)
#define uint64 unsigned long long
#define int64 long long

#define MOD 4294967296LL
#define MAX 100000000
#define LMT 10000
#define 18 M
int64 dp[18][2][10];
int64 run(int cur, int smaller, int m1,) {
    if (cur == n)
        return (m1 == 0 && m2 == 0 ? 1 : 0);
    }
    int64 &res = dp[cur][smaller][m1][m2];
    if ( res != -1) return res;
    res = 0;
    int m = (smaller == 0 ? num[cur] : 9);
    for (int d = 0; d <= m; d++) {
        int nextSmaller = smaller | (d < num[cur] ? 1 : 0);
        res += run(cur + 1, nextSmaller, (m1 + d) % k, (m2 * 10 + d) % k);
    }
    return res;
}
int64 cal(int x) {
    n = 0;
    while ( x ) {
        num[n++] = x % 10;
        x/=10;
    }
    reverse(num, num + n);
    fill(dp, -1); ans = 0;
    for (int i = 1;i <= num;i++)
        ans += run(0, 0, i);
    return ans;
}
int main() {
	freopen("exam.inp",r, stdin);
	freopen("exam.out",w,stdout);
    scanf("%d",&n);
    scanf("%lld %lld", &l, &r);
    printf("%lld\n", cal(r) - cal(l - 1));
	return 0;
}
