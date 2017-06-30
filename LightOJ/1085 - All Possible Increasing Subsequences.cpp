/***********************************************
* Author LUONG VAN DO                        *
* Problem 1085 - All Possible Increasing Subsequences 
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
#define N 100010
#define M 1000100
#define MOD 1000000007

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
struct node{
    int val, id;
    node(){}
    node(int _val, int _id){
        val = _val;
        id = _id;
    }
    bool operator < (const node& other) const {
        return (val < other.val);
    }
}a[N];
int b[N], n, m, k, len;
int64 f[N], tree[N];
char s[M];
void updateBIT(int i, int v) {
    while ( i <= m ) {
        tree[i] += v;
        tree[i] %= MOD;
        i+=(i&-i);
    }
}
int64 getBIT(int i) {
    int64 result = 0;
    while ( i ) {
        result += tree[i];
        result %= MOD;
        i-=(i&-i);
    }
    return result % MOD;
}
int getInt() {
    int v = 0, sign = 0;
    while (k < len && s[k] != ' ') {
        if (s[k] == '-') {
            sign = 1;
            k++;
            continue;
        }
        v = v * 10 + s[k++] - '0';
    }
    k++;
    if (sign) v = -v;
    return v;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, caseno = 0;
    gets(s); len = strlen(s); k = 0;
    cases = getInt();
    while (cases--) {
        gets(s); len = strlen(s); k = 0;
        n = getInt();
        gets(s); len = strlen(s); k = 0;
        fr(i, 1, n) a[i] = node(getInt(), i);
        sort(a + 1, a + n + 1);
        a[0].val = a[1].val - 1; m = 0;
        fr(i, 1, n) {
            f[i] = 1;
            tree[i] = 0;
            if (a[i].val > a[i - 1].val) m++;
            b[a[i].id] = m;
        }
        b[n + 1] = m + 1; f[n + 1] = tree[n + 1] = 0;
        fr(i, 1, n) {
            updateBIT(b[i], f[i]);
            f[i + 1] += getBIT(b[i + 1] - 1);
            f[i + 1] %= MOD;
        }
        printf("Case %d: %lld\n", ++caseno, f[n + 1]);
    }
}
