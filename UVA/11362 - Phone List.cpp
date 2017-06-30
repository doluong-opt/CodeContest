/***********************************************
* Author - LUONG VAN DO                        *
* 11362 - Phone List ->AC
* Algorithm matching string
* Time Limit 0.368s
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
string ss[maxN];
bool check(string x, string y) {
    if (x.length() > y.length()) return false;
    REP(i, x.length())
        if (x[i]!=y[i]) return false;
    return true;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test, n;
    bool found;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf(" %d ",&n);
        REP(i, n)
            cin >> ss[i];
        sort(ss, ss + n);
        found = true;
        REP(i, n - 1)
            if ( check(ss[i], ss[i+1]) ) found = false;
        if (found) puts("YES");
        else puts("NO");
    }
    return 0;
}
