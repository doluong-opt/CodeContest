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
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint unsigned int

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

#define INF 111222333
#define N 100000

int64 K, result, m, aj, a_m, P, d, x, y, num, ans;
void eculid(int64 a, int64 b) {
    if (b == 0) {
        x = 1; y = 0; d = a;
        return;
    }
    eculid(b, a % b);
    int64 x1 = y;
    int64 y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}
int64 power(int64 x, int64 y) {
    int64 res = 1;
    while ( y ) {
        if (y & 1) res = (res * x) % P;
        x = (x * x) % P;
        y>>=1;
    }
    return res;
}
int main(){
	//freopen("exam.inp","r",stdin);
	//freopen("exam.out","w",stdout);
    int cases, caseno = 0, i, j;
    P = 100000007;
    scanf("%d", &cases);
    m = 10001;
    while (cases--) {
        scanf("%lld %lld", &K, &result);
        map <int64, int64> idx;
        map <int64, int64> :: iterator it;
        for (j = 0, aj = 1;j < m;j++) {
            idx.insert(ii(aj, j));
            aj = (aj * K) % P;
        }
        eculid(K, P);
        while (x < 0) x += P;
        a_m = power(x, m); num = result;
        for (i = 0;i < m;i++) {
            it = idx.find(num);
            if (it != idx.end()) {
                ans = i * m + it->second;
                break;
            }
            num *= a_m;
            num %= P;
        }
        printf("Case %d: %lld\n", ++caseno, ans);
    }
}
