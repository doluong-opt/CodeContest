/***********************************************
* Author LUONG VAN DO                        *
* Problem 963 - Spelling Corrector
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
#define N 15
#define M 100000

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
char s[M][N], p[M];
int dp[N][N], d[M], n, m;
int convert(string a, string b) {
    int n = a.length();
    int m = b.length();
    for (int i = 1;i <= m;i++) dp[0][i] = 3 * i;
    for (int i = 1;i <= n;i++) dp[i][0] = 3 * i;
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++)
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
        else
            dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]) + 3, dp[i - 1][j - 1] + 5);
            
    /*for (int i = 0;i <= n;i++) {
        for (int j = 0;j <= m;j++)
            printf("%d ", dp[i][j]);
            cout<<endl;
    }*/
    return dp[n][m];
}
string solve(string a) {
    int best = INF;
    string ans = "";
    fill(dp, 0);
    rep(i, n) {
        d[i] = convert(s[i], a);
        best = min(best, d[i]);
    }
    rep(i, n)
        if (best == d[i]) {
            if (!ans.size()) ans = s[i];
            else
            if (ans > string(s[i])) ans = s[i];
        }
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, l, j;
    string temp;
    while (scanf(" %d ", &n) != EOF) {
        map <string, bool> f;
        vector <string> res;
        res.clear();
        rep(i, n) {
            gets(s[i]);
            f[s[i]] = true;
        }
        scanf(" %d ", &m);
        while ( m > 0 ) {
            gets(p); l = strlen(p); j = 0;
            while (j < l) {
                while (j < l && !isalpha(p[j]) ) j++;
                temp = "";
                while (j < l && isalpha(p[j])) temp+=p[j++];
                if (temp.size()) {
                    if ( f[temp] ) res.pb(temp);
                    else res.pb(solve(temp));
                }
            }
            m-=10;
        }
        rep(i, res.size()) {
            if (i && (i + 1) % 10 == 0) {
                cout << res[i];
                puts("");
            }
            else
            if (i != res.size() - 1) cout<<res[i]<<" ";
            else cout<<res[i];
        }
        puts("");
    }
}
