/***********************************************
* Author - LUONG VAN DO                        *
* 1253 - Misere Nim - >AC
* Algorithm Nim
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
#define maxN 50001
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int a[maxN];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, n;
    int ans, sum;
    scanf("%d",&test);
    FOR(t, 1, test) {
        sum = 0;
        scanf("%d",&n);
        REP(i, n) {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
            if (sum == n && n % 2) printf("Case %d: Bob\n",t);
        else
            if (sum == n && n % 2 == 0) printf("Case %d: Alice\n",t);
        else {
            ans = a[0];
            FOR(i, 1, n - 1)
                ans = ans ^ a[i];
            if (ans) printf("Case %d: Alice\n",t);
            else printf("Case %d: Bob\n",t);
        }
    }
    return 0;
}
