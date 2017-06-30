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
#define N 100100

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
char str[1111];
int n, x, y, vLeft, exist;
int getSign(int &pos) {
    if (str[pos] == '-') { pos++; return -1; };
    if (str[pos] == '+') { pos++; return 1; };
    return 1;
}
int getX(int &pos) {
    if (str[pos] == 'x') { pos++; return 1; };
    return 0;
}
int getNumber(int &pos) {
    int v = 0; exist = 0;
    //cout<<"d"<<" "<<pos<<endl;
    while (pos < n && isdigit(str[pos])) {
        v = v * 10 + str[pos++] - '0';
        exist = 1;
    }
    return v;
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases, i;
	scanf(" %d ",&cases);
	while (cases--) {
	    gets(str); n = strlen(str);
	    x = y = 0; vLeft = 1; i = 0;
	    // 2x-4+5x+300=98x
	    while (i < n) {
	        if ( str[i] == '=' ) {
	            vLeft = -vLeft;
	            ++i;
	        }
	        int sign = getSign(i);
	        int number = getNumber(i);
	        int xx = getX(i);	        
	        if ( xx && !exist ) number = 1;
	        if (xx)
                x += number * sign * vLeft;
            else
                y += number * sign * vLeft;
	    }
	    if (x == 0 && y == 0) puts("IDENTITY");
	    else
	    if (x == 0 && y != 0) puts("IMPOSSIBLE");
	    else {
	        double ans = -(double)y / (double)x;
	        printf("%d\n", (int)floor(ans));
	    }
	}
	return 0;
}
