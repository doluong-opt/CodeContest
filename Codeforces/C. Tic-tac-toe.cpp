/***********************************************
* Author - LUONG VAN DO                        *
* Problem C. Tic-tac-toe ->AC
* Algorithm Adhoc
* Time Limit 30ms
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
char s[5][5];
int draw, first, second;
bool xwin() {
    int x = 0;
    int won = 0;
    for (int i=0;i<3;i++) {
        x = 0;
        for (int j=0;j<3;j++)
            if (s[i][j] == 'X') x++;
        if (x == 3) won++;
    }
    for (int i=0;i<3;i++) {
        x = 0;
        for (int j=0;j<3;j++)
            if (s[j][i] == 'X') x++;
        if (x == 3) won++;
    }
    x = 0;
    for (int i=0;i<3;i++)
        if (s[i][i] == 'X') x++;
    if (x == 3) won++;
    if (s[0][2] == 'X' && s[1][1] == 'X' && s[2][0] == 'X') won++;
    return (won == 1 || (won == 2 && first == 5));
}
bool owin() {
    int x = 0;
    int won = 0;
    for (int i=0;i<3;i++) {
        x = 0;
        for (int j=0;j<3;j++)
            if (s[i][j] == '0') x++;
        if (x == 3) won++;
    }
    for (int i=0;i<3;i++) {
        x = 0;
        for (int j=0;j<3;j++)
            if (s[j][i] == '0') x++;
        if (x == 3) won++;
    }
    x = 0;
    for (int i=0;i<3;i++)
        if (s[i][i] == '0') x++;
    if (x == 3) won++;
    if (s[0][2] == '0' && s[1][1] == '0' && s[2][0] == '0') won++;
    return (won == 1);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif

    draw = first = second = 0;
    for (int i=0;i<3;i++)
        gets(s[i]);
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++) {
            if (s[i][j]!='.') draw++;
            if (s[i][j]=='0') second++;
        else
            if (s[i][j]=='X') first++;
        }
    if (abs(first - second) > 1 || first < second) puts("illegal");
    else
    if (owin() && first > second) puts("illegal");
    else
    if (xwin() && owin()) puts("illegal");
    else
    if (xwin() && first == second) puts("illegal");
    else
    if (xwin() && !owin()) puts("the first player won");
    else
    if (!xwin() && owin()) puts("the second player won");
    else
    if (draw == 9) puts("draw");
    else
    if (first > second) puts("second");
    else
    if (first == second) puts("first");
}
