/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1005. Stone Pile ->AC
* Algorithm backtracking
* Time Limit 0.046s
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
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 22

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
vector <int> num;
int a[N], n;
void trySum(int i, int sum) {
    for (int j=0;j<=1;j++) {
        sum+=(a[i] * j);
        if (i < n - 1) trySum(i + 1, sum);
    }
    num.pb( sum );
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int sum, ans;
    while (scanf("%d",&n) != EOF) {
        sum = 0; num.clear();
        for (int i=0;i<n;i++) {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        trySum(0, 0); ans = INF;
        for (int i=0;i<num.size();i++)
            ans = min(ans, abs(sum - 2 * num[i]));
        printf("%d\n",ans);
    }
}
