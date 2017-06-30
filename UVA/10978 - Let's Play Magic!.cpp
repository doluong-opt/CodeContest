/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10978 - Let's Play Magic! ->AC
* Algorithm Adhoc
* Time Limit 0.012s
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
#define M 55

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
int n, p;
int pos[M + 1];
string Ans[M + 1];
string x, y;
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int run, sz;
    while ( scanf(" %d ",&n) && n){
        REP(i, n) pos[i] = 0;
        p = 0;
        REP(i, n) {
            cin >> x >> y;
            run = 1; sz = y.size();
            while (run != sz) {
                if (!pos[p]) {
                    p = (p + 1) % n;
                    run++;
                }
                else p = (p + 1) % n;
            }
            while ( pos[p] ) p = (p + 1) % n;
            pos[p] = 1;
            Ans[p] = x;
        }
        REP(i, n) {
            if (i > 0) printf(" ");
            cout<< Ans[i];
        }
        cout<<endl;
    }
}
