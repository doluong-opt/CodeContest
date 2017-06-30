/***********************************************
* Author - LUONG VAN DO
*
* Algorithm
* Time Limit 0.003s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fillarr(arr, c) memset(arr, c, sizeof(arr))
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 101
#define N 20
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
long long dp[N][2][10][10];
long long L, R, ans;
int digit[N], n;
long long getAns(int cur, int isSmall, int first, int last) {
        if (cur == n) {
                        cout<<first<<" "<<last<<endl;
                return (first == last ? 1 : 0);
        }
        long long &res = dp[cur][isSmall][first][last];
        if (res != -1) return res;
        res = 0LL;
        int m = (isSmall == 0 ? digit[cur] : 9);
        for (int d = 0;d <= m;d++) {
                int nextIsSmall = (isSmall | (d < digit[cur] ? 1 : 0));
                res += getAns(cur + 1, nextIsSmall, first, d);
        }
        return res;
}
void split(long long x) {
        n = 0;
        while (x > 0) {
                digit[n++] = x % 10;
                x /= 10;
        }
        reverse(digit, digit + n);
}
int main() {
        freopen("exam.inp","r", stdin);
        freopen("exam.out","w", stdout);
        scanf("%lld %lld", &L, &R);

        split(R);
        ans = 0LL;

        //for (int i = 0;i < n;i++) cout<<digit[i]<<endl;
        //for (int i = 1;i <= n;i++) {
                for (int lastDigit = 2;lastDigit <= 2;lastDigit++) {
                        fillarr(dp, -1);
                        ans = getAns(0, 0, lastDigit, lastDigit);
                        cout<<ans<<endl;
                }
        //}
        cout<<ans<<endl;
        return 0;
}
