/***********************************************
* Author - LUONG VAN DO                        *
* Problem C. Fruits ->AC
* Algorithm adhoc
* Time Limit 30ms
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
#define M 100000

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
int n, m;
int price[M];
map <string, int> mx;
int a[M];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    char s[100];
    int nm = 0, k;
    int minx, maxx;
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++) scanf("%d ",&price[i]);
    for (int i=0;i<m;i++) {
        gets(s);
        mx[s]++;
    }
    sort(price, price + n);
    for (map <string, int> ::iterator it = mx.begin(); it!=mx.end(); it++)
        a[nm++] = it->second;
    sort(a, a + nm);
    minx = maxx = 0; k = n - 1;
    for (int i=0;i<nm;i++) {
        minx+=a[nm-i-1] * price[i];
        maxx+=a[nm-i-1] * price[k];
        k--;
    }
    printf("%d %d\n",minx, maxx);
}
