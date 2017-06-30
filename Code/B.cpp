// =============================================================================
// Author LUONG VAN DO
// Problem 
// Algorithm
// Time Limit
// =============================================================================
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
#define INF (long long) 1e17
#define N (int) (1e6 + 5)
#define C 8888
#define md 1000000007
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
char s[N];
int n, cases;
int f[26];
string digits[] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE",
"SIX","SEVEN","EIGHT","NINE"};
char c[] = { 'Z', 'X', 'G', 'W', 'H', 'R', 'S', 'F', 'I', 'O' };
int num[] = { 0, 6, 8, 2, 3, 4, 7, 5, 9, 1 };
vector<int> ans;
void solve(int pos) {
    while (f[c[pos] - 'A'] > 0) {
        ans.push_back(num[pos]);
        rep(i, digits[num[pos]].size()) {
            char ch = digits[num[pos]][i];
            f[ch - 'A']--;
        }
    }
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("exam.inp","r", stdin);
        freopen("exam.out","w", stdout);
    #endif
    int casesNo = 0;
    scanf(" %d ", &cases);
    while (cases--) {
        gets(s); n = strlen(s);
        ans.clear();
        rep(i, 26) f[i] = 0;
        rep(i, n) f[s[i] - 'A']++;
        printf("Case #%d: ", ++casesNo);
        rep(i, 10) solve(i);
        sort(ans.begin(), ans.end());
        rep(i, ans.size()) printf("%d", ans[i]);
        printf("\n");
    }
    return 0;
}