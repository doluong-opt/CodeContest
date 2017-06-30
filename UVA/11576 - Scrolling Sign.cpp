/***********************************************
* Author LUONG VAN DO                        *
* Problem 11576 - Scrolling Sign
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
#define N 110

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
int n, k;
char s[N][N];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, x, y, k1, k2, posMax;
    scanf("%d", &cases);
    string first, a;
    while (cases--) {
        scanf(" %d %d ", &n, &k);
        rep(i, k)
            gets(s[i]);
        first = s[0];
        fr(i, 1, k - 1) {
            a = s[i];
            x = first.size();
            y = a.size();
            posMax = 0;
            fr(j, x - n, x - 1) {
                k1 = j;
                k2 = 0;
                while (k1 < x && k2 < y && a[k2] == first[k1]) {
                    k1++;
                    k2++;
                }
                if (k1 == x) posMax = max(posMax, k2);
            }
            fr(j, posMax, y - 1) first+=a[j];
        }
        printf("%d\n", first.size());
    }
}
