// =============================================================================
// Author LUONG VAN DO
// Problem
// Algorithm
// Time Limit
// =============================================================================
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
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 50005

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
char s[N];
int n, x, ans, j;
int visit[N];
int main() {
        //freopen("exam.inp","r", stdin);
        //freopen("exam.out","w", stdout);
        gets(s); n = strlen(s);
        j = ans = 0;
        for (int i = 0;i < n;i++) {
                while (j < n && !visit[s[j]]) {
                        visit[s[j]]++;
                        j++;
                }
                visit[s[i]]--;
                ans = max(ans, j - i);
        }
        printf("%d\n", ans);
        return 0;
}
