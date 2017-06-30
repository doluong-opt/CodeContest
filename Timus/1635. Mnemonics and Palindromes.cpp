/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1635. Mnemonics and Palindromes
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
#define N 4010

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
bool dp[N][N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    string s;
    int n, j;
    cin >> s; n = s.length();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) dp[i][j] = false;
    for (int i=1;i<=n;i++) {
        dp[i][i] = true;
        if (s[i-1] == s[i]) dp[i][i+1] = true;
    }
    for (int k=1;k<=n;k++) {
        for (int i=1;i<=n-k;i++) {
            j = i + k;
            dp[i][j] = dp[i+1][j-1] & (s[i-1] == s[j-1]);
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
}
