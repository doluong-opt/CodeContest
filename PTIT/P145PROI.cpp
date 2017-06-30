/***********************************************
* Author - LUONG VAN DO                        *
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

#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i = b;i >= a;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define pb push_back
#define ff first
#define ss second
#define fill(arr, val) memset(arr, val, sizeof(arr))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define uint32 unsigned int
#define INF 1000000000
#define N 1000100

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
char s[N];
int n, j, x, y, z;
int64 ans;
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	gets(s); n = strlen(s); ans = 0;
	x = y = z = 0;
	for (int i = 0;i < min(5, n);i++)
        if (s[i] >= 'a' && s[i] <= 'z') x++;
    else
        if (s[i] >= 'A' && s[i] <= 'Z') y++;
    else 
        if (s[i] >= '0' && s[i] <= '9') z++;
    j = 0;
    for (int i = 5;i < n;i++) {
        if (s[i] >= 'a' && s[i] <= 'z') x++;
        else
        if (s[i] >= 'A' && s[i] <= 'Z') y++;
        else
        if (s[i] >= '0' && s[i] <= '9') z++;
        if (x >= 1 && y >= 1 && z >= 1) {
            if (i - j >= 5) ans += (n - i);
            while (i - j >= 5) {
                if (s[j] >= 'a' && s[j] <= 'z') x--;
                else
                if (s[j] >= 'A' && s[j] <= 'Z') y--;
                else 
                if (s[j] >= '0' && s[j] <= '9') z--;
                j++;
                if (i - j >= 5 && x >= 1 && y >= 1 && z >= 1) ans += (n - i);
                if (x <= 0 || y <= 0 || z <= 0) break;
            }
        }
    }
    printf("%lld\n", ans);
	return 0;
}
