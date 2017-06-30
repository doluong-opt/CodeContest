/***********************************************
* Author LUONG VAN DO                        *
* Problem 10100 - Longest Match
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
int dp[N][N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    char s1[N], s2[N];
    string a[N], b[N], ch;
    int x, y, caseno = 0, n, m, id;    
    while ( gets(s1) ) {
        gets(s2);
        n = strlen(s1); m = strlen(s2);
        x = y = 0;
        if (n == 0 || m == 0) {
            printf("%2d. Blank!\n", ++caseno);
            continue;
        }
        id = 0;
        while (id < n) {
            while (id < n && !isalpha(s1[id]) && !isdigit(s1[id])) id++;
            ch = "";
            while (id < n && isalpha(s1[id]) || isdigit(s1[id])) ch = ch + s1[id++];
            //rep(i, ch.size()) ch[i] = tolower(ch[i]);
            if (ch.size()) a[x++] = ch;
        }
        id = 0;
        while (id < m) {
            while (id < m && !isalpha(s2[id]) && !isdigit(s2[id])) id++;
            ch = "";
            while (id < m && isalpha(s2[id]) || isdigit(s2[id])) ch = ch + s2[id++];
            //rep(i, ch.size()) ch[i] = tolower(ch[i]);
            if (ch.size()) b[y++] = ch;
        }
        fr(i, 1, x)
            fr(j, 1, y)
                if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        printf("%2d. Length of longest match: %d\n", ++caseno, dp[x][y]);
    }
}
