/***********************************************
* Author - LUONG VAN DO                        *
* 1006 - Hex-a-bonacci ->AC
* Algorithm Adhoc
* Time Limit 0.005s
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
#define For(i, a, b) for (int i=a; i<=b; i++)
#define Ford(i,a,b) for (int i=a;i>=b;i--)
#define Rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 10005
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int a,b,c,d,e,f,n;
int64 dp[maxN];
int fn(int n){
    dp[0] = a; dp[1] = b; dp[2] = c; dp[3] = d; dp[4] = e; dp[5] = f;
    for (int i=6;i<=n;i++)
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]) % 10000007;
    return dp[n];
}
void Read_Input(){
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        for (int i=0;i<=n;i++) dp[i] = -1;
        printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    return 0;
}
