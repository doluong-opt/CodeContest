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
#define N 200001
#define C 1000000
using namespace std;
int a[N], n, m, lo, hi, posCur, valMax, posValMax, preVal, xx;
int64 ans;
vector <int> f[2 * C + 1];
bool found;
int main() {
	freopen("exam.inp","r", stdin);
	freopen("exam.out","w",stdout);
	scanf("%d", &n);
	for (int i = 1;i <= n;i++)
	{
	      scanf("%d", &a[i]);
	      a[i] += C;
	      f[a[i]].push_back(i);
	}
	posCur = n; ans = 0LL;
	for (int i = 2 * C;i >= 0;i--)
            if (f[i].size() > 0)
            {
                  m = (int)f[i].size() - 1;
                  while (posCur >= 1 && m >= 0 && f[i][m] == posCur)
                  {
                        m--;
                        posCur--;
                  }
                  if (m == -1) continue;
                  valMax = i;
                  posValMax = posCur;
                  xx = f[i][m];
                  break;
            }
      cout<<valMax<<" "<<posValMax<<" "<<xx<<endl;
      a[xx] = a[posValMax];
      for (int i = 1;i < posValMax - 1;i++) a[i] = a[i + 1];
      a[posValMax] = valMax;
      preVal = a[posValMax - 1];
      for (int i=  1;i <= n;i++) cout<<a[i] - C<<endl;
      cout<<endl;
      if (xx == 1)
      {
            ans = 0LL;
            for (int i = 1;i <= n;i++)
                  ans += (int64)(a[i] - C) * (int64)i;
      }
      else{
            int yy = posValMax - 1;
            posValMax--;
            while (posValMax - 1 >= 1 && preVal < a[posValMax - 1]) posValMax--;
            posValMax++;
            for (int i = yy;i >= posValMax;i--)
                  a[i] = a[i - 1];
            a[posValMax] = preVal;
            for (int i=  1;i <= n;i++) cout<<a[i] - C<<endl;
      }
	return 0;
}
