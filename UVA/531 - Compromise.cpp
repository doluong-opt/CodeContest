/***********************************************
* Author LUONG VAN DO                        *
* Problem 531 - Compromise
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
#define N 1100

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
string a[N], b[N], ch;
int dp[N][N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    char s[3 * N];
    int x, y, id, n, i1, i2;
    while ( gets(s) ) {
        id = 0; n = strlen(s); x = y = 0;
        stack <string> S;
        while (id < n) {
            while (id < n && s[id] == ' ') id++;
            ch = "";
            while (id < n && isalpha(s[id])) ch = ch + s[id++];
            if (ch.size()) a[x++] = ch;
        }
        while ( gets(s) && strcmp(s, "#")) {
            id = 0; n = strlen(s);
            while (id < n) {
                while (id < n && s[id] == ' ') id++;
                ch = "";
                while (id < n && isalpha(s[id])) ch = ch + s[id++];
                if (ch.size()) a[x++] = ch;
            }
        }
        while ( gets(s) && strcmp(s, "#")) {
            id = 0; n = strlen(s);
            while (id < n) {
                while (id < n && s[id] == ' ') id++;
                ch = "";
                while (id < n && isalpha(s[id])) ch = ch + s[id++];
                if (ch.size()) b[y++] = ch;
            }
        }
        fill(dp, 0);
        fr(i, 1, x)
            fr(j, 1, y)
                if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                
        i1 = x; i2 = y;
        while (i1 >= 1 && i2 >= 1) {
            if (a[i1 - 1] == b[i2 - 1]) {
                S.push(a[i1 - 1]);
                i1--;
                i2--;
            }
            else
            if (dp[i1][i2] == dp[i1 - 1][i2]) i1--;
            else i2--;
        }
        int flag = 0;
        while ( !S.empty()) {
            if (flag) printf(" ");
            flag = 1;
            cout << S.top();
            S.pop();
        }
        puts("");
    }
}
