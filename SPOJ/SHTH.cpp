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
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i = n - 1;i >= 0;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 100111
#define BASE 1000000000
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
int a[N];
string c[400][400], s;
string add(string x, string y) {
    while (x.length() < y.length()) x = "0" + x;
    while (x.length() > y.length()) y = "0" + y;
    int sum = 0, nho = 0;
    string c = "";
    for (int i = x.length() - 1;i >= 0;i--) {
        sum = (x[i] - '0') + (y[i] - '0') + nho;
        nho = (sum / 10);
        c = char(sum % 10 + 48) + c;
    }
    if (nho > 0) c = "1" + c;
    return c;
}
string sub(string x, string y) {
    while (x.length() < y.length()) x = "0" + x;
    while (x.length() > y.length()) y = "0" + y;
    int sum = 0, nho = 0;
    string c = "";
    for (int i = x.length() - 1;i >= 0;i--) {
        sum = (x[i] - '0') - (y[i] - '0') - nho;
        if (sum < 0) {
            sum += 10;
            nho = 1;
        }
        else nho = 0;
        c = char(sum % 10 + 48) + c;
    }
    while (c.length() > 1 && c[0] == '0') c.replace(0, 1,"");
    return c;
}
int main() {
	freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	string ans;
	scanf("%d %d", &n, &k);
	cin >> s;
	for (int i = 1;i <= k;i++) scanf("%d", &a[i]);
	for (int i = 0;i <= 300;i++) c[i][0] = "1";
	for (int i = 1;i <= 300;i++)
        for (int j = 1;j <= i;j++) c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
    ans = "0";
    for (int i = 1;i <= k;i++) {
        for (int j = 1;j <= a[i] - 1;j++)
            ans = add(ans, c[n - j][k - i]);
        
        for (int j = i + 1;j <= k;j++)
            if (a[j] > a[i]) a[j] -= a[i];
        n -= a[i];
    }
    
    cout << add(ans, "1") << endl;
    
	return 0;
}
