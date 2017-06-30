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
#define N 100111
#define MAX_LOG 20
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
int n, at, s, cnt;
int visit[20], st[20];
vector <int> ans[N];
bool isPrime(int x) {
       if (x == 2 || x == 3) return true;
       for (int i = 2;i * i <= x;i++)
              if (x % i == 0) return false;
       return true;
}
void go(int at, int &cnt) {
       visit[at] = 1;
       st[s++] = at + 1;
       if (s == n && isPrime(at + 1 + st[0])) {
              if (cnt <= 9999) {
                     rep(i, n)
                            ans[cnt].pb(st[i]);
                     cnt++;
              }
       }
       else {
              rep(i, n)
                     if (!visit[i] && isPrime(at + i + 2)) go(i, cnt);
       }
       s--;
       visit[at] = 0;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
       scanf("%d", &n); n = 2 * n;
       rep(i, n) visit[i] = 0;
       cnt = s = 0; go(0, cnt);
       printf("%d\n", cnt);
       rep(i, cnt) {
              rep(j, n) {
                     if (j) printf(" %d", ans[i][j]);
                     else printf("%d", ans[i][j]);
              }
              puts("");
       }
	return 0;
}
