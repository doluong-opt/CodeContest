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

using namespace std;
int cases, n, sz;
int a[LMT];
int64 ans;
int main() {
	//freopen("exam.inp","r", stdin);
	//freopen("exam.out","w",stdout);
	scanf("%d", &cases);
	while (cases--)
	{
	      scanf("%d", &n);
	      if (n == 0)
	      {
	            printf("1\n");
	            continue;
	      }
	      sz = ans = 0;
	      while ( n )
	      {
	            if (n % 2 == 0) a[sz++] = 1;
	            else a[sz++] = 0;
	            n >>= 1;
	      }
	      reverse(a, a + sz);
	      for (int i = 0;i < sz;i++) ans = ans * 2 + a[i];
	      printf("%lld\n", ans);
	}
	return 0;
}
