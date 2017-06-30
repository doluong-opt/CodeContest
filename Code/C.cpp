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
char s[N];
int n, ans;
int cntx, cnty;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("exam.inp","r", stdin); 
        freopen("exam.out","w", stdout);
    #endif
    scanf(" %d ", &n);
    gets(s);
    ans = cntx = cnty = 0;
    for (int i = 0;i < n;i++)
    	if (s[i] == 'r') cntx++;
    	else
    	if (s[i] == 'b') cnty++;

    for (int i = 1;i < n;i++) {
    	if (s[i] != s[i - 1]) continue;
    	if (i + 1 < n && s[i] != s[i + 1]) {
    		swap(s[i], s[i + 1]);
    		ans++;
    	}
    	else
    	if (i + 1 < n && s[i] == s[i + 1]) {
    		if (s[i] == 'b') s[i] = 'r';
    		else s[i] = 'b';
    		ans++;
    	}
    }
    cout<<s<<endl;
    if (n % 2 == 0) {
    	if (cntx == n || cnty == n)
    		ans = n / 2;
    }
    cout << ans << endl;
    return 0;
}
    