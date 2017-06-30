/***********************************************
* Author - LUONG VAN DO                        *
* 357 - Let Me Count The Ways ->AC
* Algorithm dp
* Time Limit 0.012s
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
#define maxN 30005

using namespace std;
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int coins[] = {1, 5, 10, 25, 50};
int n;
uint64 dp[maxN];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    dp[0] = 1;
    REP(i, 5)
        FOR(j, coins[i], 30000)
            dp[j] += dp[j - coins[i]];
    while ( scanf("%d",&n) !=EOF) {
        if (n <= 4) printf("There is only 1 way to produce %d cents change.\n",n);
        else printf("There are %lld ways to produce %d cents change.\n",dp[n],n);
    }    
    return 0;
}
