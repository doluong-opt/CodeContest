/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10070 - Leap Year or Not Leap Year and ... ->AC
* Algorithm Adhoc
* Time Limit 0.024s
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
#define M 100000

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
bool mod(char num[], int m) {
    int64 d = 0;
    for (int i=0;i<strlen(num);i++)
        d = (d * 10 + (num[i] - '0')) % m;
    return (d == 0);
}
bool leap_year(char num[]) {
    if (mod(num, 4) && !mod(num, 100)) return true;
    return (mod(num, 400));
}
bool hulu(char num[]) {
    return (mod(num, 15));
}
bool bulu(char num[]){
    return (mod(num, 55));
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int found, blank = 0;
    char s[M];
    while ( gets(s) ) {
        if ( blank ) puts("");
        blank = 1;
        found = 0;
        if ( leap_year(s) ) {
            puts("This is leap year.");
            found = 1;
        }
        if ( hulu(s) ) {
            puts("This is huluculu festival year.");
            found = 1;
        }
        if (leap_year(s) && bulu(s) ) {
            puts("This is bulukulu festival year.");
            found = 1;
        }
        if (!found) puts("This is an ordinary year.");
    }
}
