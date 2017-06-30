/***********************************************
* Author - LUONG VAN DO                        *
* 11661 - Burger Time? ->AC
* Algorithm Adhoc
* Time Limit 0.068s
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

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, x, y, ans;
    char s[2000001];
    while ( scanf(" %d ",&n) && n) {
        gets(s);
        bool found = false;
        x = y = -1;
        ans = INF;
        for (int i=0;i<n && !found;i++) {
            if (s[i] == 'R') x = i;
            if (s[i] == 'D') y = i;
            if (s[i] == 'Z') found = true;
            if (x >=0 && y>=0)
                if ( ans > abs(x - y) ) ans = abs(x - y);
        }
        if ( found ) printf("0\n");
        else printf("%d\n",ans);
    }
    return 0;
}
