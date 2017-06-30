/***********************************************
* Author - LUONG VAN DO                        *
* 10424 - Love Calculator ->AC
* Algorithm Adhoc
* Time Limit 0.04s
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
    char s[maxN];
    int r1, r2, tmp;
    while ( gets(s) ) {
        r1 = r2 = 0;
        REP(i, strlen(s))
            if (s[i]>='a' && s[i]<='z') r1 = r1 + (s[i] -'a') + 1;
            else
            if (s[i]>='A' && s[i]<='Z') r1 = r1 + (s[i] -'A') + 1;
        gets(s);
        REP(i, strlen(s))
            if (s[i]>='a' && s[i]<='z') r2 = r2 + (s[i] -'a') + 1;
            else
            if (s[i]>='A' && s[i]<='Z') r2 = r2 + (s[i] -'A') + 1;
        tmp = 0;
        while ( r1 >= 10) {
            tmp = 0;
            while ( r1 >= 10) {
                tmp+=(r1 % 10);
                r1/=10;
            }
            tmp+=r1;
            r1 = tmp;
        }
        tmp = 0;
        while ( r2 >= 10) {
            tmp = 0;
            while ( r2 >= 10) {
                tmp+=(r2 % 10);
                r2/=10;
            }
            tmp+=r2;
            r2 = tmp;
        }
        if (r1 > r2) swap(r1, r2);
        printf("%.2lf %%\n",((double)r1 / (double)r2) * 100.0);
    }
    return 0;
}
