/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10295 - Hay Points ->AC
* Algorithm Adhoc
* Time Limit 0.008s
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
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define A first
#define B second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define M 100000

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
struct block {
	int value;
	char str [20];
} a [1020];

int m;

int call ( char x [] ) 
{
	for ( int i = 0; i < m; i++ ) {
		if ( strcmp (a [i].str, x) == 0 )
			return a [i].value;
	}

	return 0;
}

int main () {
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    
	int n, length, res;
	char line [10000];
	char partial [100];

	while ( scanf ("%d %d", &m, &n) != EOF ) {

		int i;
		for ( i = 0; i < m; i++ )
			scanf ("%s %d", a [i].str, &a [i].value);
		gets (line);

		for ( i = 0; i < n; i++ ) {

			res = 0;
			gets (line);
			while ( strcmp (line, ".") != 0 ) {
				length = strlen (line);

				int j = 0;
				while ( j < length ) {
					int k = 0;
					while ( line [j] != ' ' && line [j] != 0 )
						partial [k++] = line [j++];
					partial [k++] = '\0';
					j++;
					res += call ( partial );
				}
				gets (line);
			}
			printf ("%d\n", res);
		}	
	}
	return 0;
}

