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

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0;i<n;i++)
#define uint64 unsigned long long
#define int64 long long

#define MOD 4294967296LL
#define MAX 100000000
#define LMT 10000
#define N 200005
using namespace std;
int n, a[N];
int64 sum[N];
int main() {
	freopen("exam.inp","r", stdin);
	freopen("exam.out","w",stdout);
	scanf("%d", &n);
	sum[0] = 0;
	for (int i = 1;i <= n;i++) {
	      scanf("%d", &a[i]);
	      sum[i] = sum[i - 1] + a[i];
	}

	return 0;
}
