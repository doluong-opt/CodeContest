/***********************************************
* Author LUONG VAN DO                        *
* Problem 
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
#define N 2010
#define C 3137
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
int n, m, x;
uint64 h[N], r1, r2, p[N], d;
char s[N];
uint64 f(int l, int r) {
    if (!l) return h[r];
    int len = r - l + 1;
    uint64 total;
    total = (h[r] - h[l - 1] * p[len - 1]) * p[n - len];
    return total;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int ans;
    p[0] = 1;
    for (int i = 1;i < N;i++)
        p[i] = p[i - 1] * C;
    gets(s); n = strlen(s);
    h[0] = s[0];
    for (int i = 1;i < n;i++)
        h[i] = h[i - 1] * C + s[i];
    gets(s); m = strlen(s);
    r1 = s[0];
    for (int i = 1;i < m;i++)
        r1 = r1 * C + s[i];
        
    gets(s); m = strlen(s);
    r2 = s[0];
    for (int i = 1;i < m;i++)
        r2 = r2 * C + s[i];
    ans = x = 0;
    for (int i = 0;i < n;i++)
        for (int j = i;j < n;j++) {
            d = f(i, j);
            cout<<i<<" "<<j<<" "<<r1 * p[i]<<" "<<r2 * p[j]<<" "<<d<<endl;
            if (d == r1 * p[i]) x++;
            if (d == r2 * p[j] && x > 0) {
                x--;
                ans++;
            }
        }
    printf("%d\n", ans);
}
