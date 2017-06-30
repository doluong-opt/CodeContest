/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10487 - Closest Sums ->AC
* Algorithm Adhoc
* Time Limit 0.064s
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
#define INF 50000000000000LL
#define M 1010

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
vector <int64> number, sum;
int a[M];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, m, cases = 0, sz, x;
    int64 Ans;
    while ( scanf("%d",&n) && n){
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a + 1, a + n + 1); number.clear(); sum.clear();
        a[0] = a[1] - 1;
        for (int i=1;i<=n;i++) {
            if (a[i] == a[i-1]) continue;
            number.pb(a[i]);
        }
        sz = number.size();
        for (int i=0;i<sz-1;i++)
            for (int j=i+1;j<sz;j++)
                sum.pb(number[i] + number[j]);
        sz = sum.size();
        scanf("%d",&m);
        printf("Case %d:\n",++cases);
        while (m-- ) {
            scanf("%d",&x);
            int64 diff = INF;
            for (int i=0;i<sz;i++)
                if ( abs(x - sum[i]) < diff) {
                    diff = abs(x - sum[i]);
                    Ans = sum[i];
                }
            printf("Closest sum to %d is %lld.\n",x, Ans);
        }
    }
}
