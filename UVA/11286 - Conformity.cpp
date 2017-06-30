/***********************************************
* Author - LUONG VAN DO                        *
* 11286 - Conformity ->AC
* Algorithm Adhoc
* Time Limit 0.176s
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

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int n;
map <uint64, int> h;
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int x[6], ans;
    uint64 maxi, m;
    while ( scanf("%d",&n) && n){
        maxi = ans = 0;
        h.clear();
        REP(i, n) {
            REP(j, 5) scanf("%d",&x[j]);
            sort(x, x + 5);
            m = 0;
            REP(j, 5)
                m = m * 500 + x[j];
            maxi = max(maxi, ++h[m]);
        }
        for (map <uint64, int> :: iterator it = h.begin(); it!=h.end(); it++)
            if (it->second == maxi) ans+=maxi;
        printf("%d\n",ans);
    }
    return 0;
}
