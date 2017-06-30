/***********************************************
* Author LUONG VAN DO                        *
* Problem 1261 - String Popping
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
#define N 100000

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
int f(string a, int i) {
    int n = a.size(), i1;
    for (i1 = i + 1;i1 <= n;i1++)
        if (a[i] == a[i1]) continue;
        else break;
    return i1 - 1;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, i, flag, j;
    string x, y;
    scanf(" %d ", &cases);
    while (cases--) {
        gets(s); n = strlen(s);
        if (n == 1) {
            puts("1");
            continue;
        }
        x = s;
        i = 0; flag = 0;
        while ( true ) {
            j = f(x, i);
            if (j - i + 1 > 1) {
                y = "";
                for (int i1 = 0;i1 < i;i1++) y+=x[i1];
                for (int i1 = j + 1;i1 < n;i1++) y+=x[i1];
                n = y.size();
                x = y;
                i = 0;
                if (n == 0) {
                    flag = 1;
                    break;
                }
            }
            else {
                i++;
                if (i >= n) break;
            }
        }
        if (flag) puts("1");
        else puts("0");
    }
}
