/***********************************************
* Author - LUONG VAN DO                        *
* Problem 11760 - Brother Arif, Please feed us! ->AC
* Algorithm Adhoc
* Time Limit 0.032s
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
#define M 10000

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
int n, r, c;
bool row[M + 1], col[M + 1];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int x, y, cases;
    cases = 0;
    while ( scanf("%d %d %d",&r,&c,&n) && (r + c + n)){
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        REP(i, n) {
            scanf("%d %d",&x,&y);
            row[x] = col[y] = true;
        }
        bool escape = false;
        scanf("%d %d",&x,&y);
        if (x - 1 >=0 && !(row[x - 1] || col[y])) escape = true;
        else
        if (y - 1 >=0 && !(row[x] || col[y - 1])) escape = true;
        else
        if (x + 1 < r && !(row[x + 1] || col[y])) escape = true;
        else
        if (y + 1 < c && !(row[x] || col[y + 1])) escape = true;
        else
        if (!(row[x] || col[y])) escape = true;
        
        if ( escape )
            printf ("Case %d: Escaped again! More 2D grid problems!\n", ++cases);
        else
            printf ("Case %d: Party time! Let's find a restaurant!\n", ++cases);
    }
}
