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
#define N 1000111
#define P 999983

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

int n;
char s[N];
uint64 hf, hr, hp;
void edit(char *s, int &len) {
    while(len > 0) {
        if(s[len - 1] < 33) len--;
        else break;
    }
    s[len] = 0;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
	gets(s); cases = 0;
	for (int i = 0;i < strlen(s);i++)
        if (s[i] >= '0' && s[i] <= '9') cases = cases * 10 + s[i] - '0';
	while (cases--) {
	    int i, j, len;
	    gets(s); n = strlen(s);
	    edit(s, n);
	    if (n == 0) {
	        puts("YES");
	        continue;
	    }
	    if (n & 1) {
	        puts("NO");
	        continue;
	    }
        for (i = 0;i < n;i++) {
            hf = hr = 0; hp = 1LL;
            for (j = i;j < n;j++) {
                len = j - i + 1;
                hf = hf + hp * s[j];
                hr = hr * P + s[j];
                hp = hp * P;
                
                if (len % 2 == 0 && hf == hr) {
                    i = j;
                    break;
                }
            }
            if (j == n) break;
        }
        if (i == n) puts("YES");
        else puts("NO");
	}
	return 0;
}
