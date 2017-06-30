/***********************************************
* Author LUONG VAN DO                        *
* Problem CWAY
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

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 111222333
#define N 1010

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
string dp[N];
int numa[N], numb[N];
int res[N * N];

string mutiple(string x, int b){
    int l1, l2, n;
    char y[N];
    sprintf(y,"%d", b);
    l1 = x.length(); l2 = strlen(y);
    rep(i, l1) numa[l1 - i - 1] = x[i];
    rep(i, l2) numb[l2 - i - 1] = y[i];
    n = l1 + l2 - 2; fill(res, 0);
    rep(i, l1)
        rep(j, l2)
            res[i + j]+= numa[i] * numb[j];
    for (int i = 0;i <= n;i++) {
        if (res[i] > 9) {
            res[i + 1] += res[i] / 10;
            res[i] = res[i] % 10;
        }
    }
    x = "";
    if (res[n + 1] > 0) n++;
    frr(i, 0, n)
        x+=char(res[i] + 48);
    return x;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int x, n;
    dp[2] = "1";
    fr(i, 3, 1000) {
        dp[i] = mutiple(dp[i - 1], i - 2);
        x = dp[i].length() - 1;
        while (x >= 0 && dp[i][x] == '9')
            dp[i][x--] = '0';
        
        if (x < 0) dp[i] = "10" + dp[i];
        else dp[i][x] = (dp[i][x] - '0') + 49;
    }
    scanf("%d", &n);
    cout << dp[n] << endl;
}
