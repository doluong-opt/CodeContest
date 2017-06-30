/***********************************************
* Author - LUONG VAN DO                        *
* 1258 - Nowhere Money
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
#define maxN 50001
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<uint64, uint64> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
uint64 f[maxN];
ii a[maxN];
void init() {
    f[0] = 1; f[1] = 1;
    FOR(i, 2, 90)
        f[i] = f[i-1] + f[i-2];
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    uint64 n, ind, nm, blank = 0, x;
    init();
    while ( cin >> n ) {
        cout<<n<<endl;
        nm = 0; ind = 90;
        while (n > 0) {
            if (n < f[ind]) ind--;
            else {
                a[nm++] = ii(ind, f[ind]);
                n-=f[ind];
                ind--;
            }
        }
        REP(i, nm) {
            cout<<a[i].A<<" ";
        }
        cout<<endl;
        REP(i, nm) {
            cout<<a[i].B<<" ";
        }
        cout<<endl<<endl;
    }
    return 0;
}
