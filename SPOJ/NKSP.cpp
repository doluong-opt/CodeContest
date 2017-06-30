/***********************************************
* Author - LUONG VAN DO                        *
* NKSP ->AC
* Algorithm dp 
* Time Limit 1.25s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <map>
#include <set>
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
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define maxN 1001
using namespace std;
int dp[maxN][maxN], rs, n;
string x;
void Read_Input(){
    cin >> x;
    n = x.length();
    x = " " + x;
}
void Solve(){
    int j;
    rs = 0;
    For(i,1,n) dp[i][i] = 1;
    For(i,1,n-1) {
        if (x[i]==x[i+1]) dp[i][i+1] = 1;
        if (dp[i][i+1]) rs++;
    }
    For(k,2,n-1)
        For(i,1,n-k) {
            j = i + k;
            dp[i][j] = (dp[i+1][j-1] && x[i]==x[j]);
        }
    For(k,2,n-1)
        For(i,1,n-k) {
            j = i + k;
            if (dp[i][j]) rs++;
            else
            For(h,i+1,j-2)
                if (dp[i][h] && dp[h+1][j]) {
                    rs++;
                    dp[i][j] = 1; break;
                }
        }
}
void Write_Output(){
    printf("%d\n",rs);
}
main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    Read_Input();
    Solve();
    Write_Output();
}
