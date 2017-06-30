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
int n, val[N];
char s[N];
string str[N];
bool is(string x, string y) {
    int nx = x.size(), ny = y.size(), id = 0;
    if (nx <= ny) {
        while (id < nx && val[x[id] - 'A'] == val[y[id] - 'A']) id++;
        if (id == nx) return false;
        if (val[x[id] - 'A'] > val[y[id] - 'A']) return true;
        return false;
    }
    if (nx > ny) {
        while (id < ny && val[x[id] - 'A'] == val[y[id] - 'A']) id++;
        if (id == ny) return true;
        if (val[x[id] - 'A'] > val[y[id] - 'A']) return true;
        return false;
    }
}
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int caseno = 0;
	while ( scanf(" %d ", &n) && n){
	    scanf(" %s ", &s);
	    rep(i, 26) val[i] = 0;
	    rep(i, strlen(s)) val[s[i] - 'A'] = i;
	    rep(i, n) cin >> str[i];
	    rep(i, n) 
            fr(j, i + 1, n - 1)
                if ( is(str[i], str[j]) ) swap(str[i], str[j]);
	    printf("year %d\n", ++caseno);
	    rep(i, n) cout << str[i] << endl;
	}
	return 0;
}
