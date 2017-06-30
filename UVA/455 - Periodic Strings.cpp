/***********************************************
* Author - LUONG VAN DO                        *
* 455 - Periodic Strings ->AC
* Algorithm matching string
* Time Limit 0.024s
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
int ans;
char s[81];
bool check(int x, int y) {
    int d = y - x + 1;
    for (int i=0;i<strlen(s);i+=d)
        for (int j=x;j<=y;j++)
            if (s[i+j] != s[j]) return false;
    ans = min(ans, d);
    return true;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, blank = 0;
    scanf(" %d ",&test);
    FOR(t, 1, test) {
        gets(s); ans = INF;
        REP(i, strlen(s))
            FOR(j, i, strlen(s) - 1)
                check(i, j);
        if (blank) puts("");
        blank = 1;
        printf("%d\n",ans);
        gets(s);
    }
    return 0;
}
