/***********************************************
* Author - LUONG VAN DO                        *
* 11734 - Big Number of Teams will Solve This ->AC
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
#define maxN 101
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
    int test;
    char team[maxN], judge[maxN];
    scanf(" %d ",&test);
    FOR(t, 1, test) {
        gets(team);
        gets(judge);
        if ( !strcmp(team, judge) ) {
            printf("Case %d: Yes\n",t);
            continue;
        }
        int cnt = 0;
        int i, j;
        for (i = 0, j = 0; team[i] && judge[j];) {
            if (team[i] == judge[j]) {
                cnt++;
                ++i;
                ++j;
            }
            else ++i;
        }
        if (cnt == strlen(judge)) printf("Case %d: Output Format Error\n",t);
        else printf("Case %d: Wrong Answer\n",t);
    }
    return 0;
}
