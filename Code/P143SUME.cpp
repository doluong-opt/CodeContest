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
#define N 33

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
char a[N][N], b[N][N];
int n, m, k, turn, x, y;
vector <ii> tankA, tankB, target;
int main() {
	//freopen("exam.inp","r", stdin); freopen("exam.out","w", stdout);
	int cases;
	scanf(" %d ", &cases);
	while (cases--) {
	    scanf(" %d %d %d ", &n, &m, &k);
	    rep(i, m) gets(a[i]);
	    rep(i, m) gets(b[i]);
	    tankA.clear(); tankB.clear(); target.clear();
	    rep(i, m) rep(j, n) {
            if (a[i][j] == '#') tankA.pb(ii(m - i - 1, j));
            if (b[i][j] == '#') tankB.pb(ii(m - i - 1, j));
	    }
	    rep(i, k) {
	        scanf(" %d %d ", &y, &x);
	        target.pb(ii(x, y));
	    }
	    
	    turn = 0;
	    rep(i, k) {
	        bool found = false;
	        if (turn == 0) {
	            int nb = tankB.size();
	            rep(j, nb)
                    if (tankB[j].ff == target[i].ff &&  tankB[j].ss == target[i].ss) {
                        tankB.erase(tankB.begin() + j);
                        found = true;
                        break;
                    }
                if (tankB.size() == 0 || !found) turn ^= 1;
	        }
	        else {
	            int na = tankA.size();
	            rep(j, na)
                    if (tankA[j].ff == target[i].ff &&  tankA[j].ss == target[i].ss) {
                        tankA.erase(tankA.begin() + j);
                        found = true;
                        break;
                    }
                if (tankA.size() == 0 || !found) turn ^= 1;
                if (tankA.size() == 0) break;
	        }
	    }
	    if (tankA.size() > 0 && tankB.size() > 0) puts("draw");
	    if (tankA.size() == 0 && tankB.size() == 0) puts("draw");
	    if (tankA.size() == 0 && tankB.size() > 0) puts("player two wins");
	    if (tankB.size() == 0 && tankA.size() > 0) puts("player one wins");
	}
	return 0;
}
