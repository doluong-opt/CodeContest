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
#define INF 1000000009
#define N 100005
#define C 8888
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
int n;
char s[N];
int f[30], b[30];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("exam.inp","r", stdin); 
        freopen("exam.out","w", stdout);
    #endif
    gets(s); n = strlen(s);
    if (n < 26) {
        puts("-1");
    }
    else {
        bool found = false;
        for (int i = 0;i < n && !found;i++) {
            int j = i + 25;
            for (int k = 0;k < 26;k++) f[k] = 0;

            if (j < n) {
                int cnt1 = 0, cnt2 = 0;
                for (int k = i;k <= j;k++)
                    if (s[k] == '?') cnt1++;
                    else f[s[k] - 'A'] = 1;

                for (int k = 0;k < 26;k++)
                    if (f[k] == 0) b[cnt2++] = k;
                if (cnt2 == cnt1) {
                    found = true;
                    int x = 0;
                    for (int k = i;k <= j;k++)
                        if (s[k] == '?')
                            s[k] = char(b[x++] + 'A');
                }
            }
        }
        if (found) {
            for (int i = 0;i < n;i++)
                if (s[i] == '?') s[i] = 'A';
            cout << s << endl;
        }
        else puts("-1");
    }
    return 0;
}
    