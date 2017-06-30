/***********************************************
* Author - LUONG VAN DO                        *
* Problem 587 - There's treasure everywhere! ->AC
* Algorithm Adhoc
* Time Limit 0.008s
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
#define M 210

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
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    char s[M];
    string ch;
    int n, num, ind, cases = 0;
    double Ans, x, y;
    while ( gets(s) && strcmp(s,"END")) {
        n = strlen(s); ind = 0;
        x = y = 0.0;
        while (ind < n) {
            while (ind < n && s[ind]!=',') {
                num = 0;
                while (ind < n && isdigit(s[ind])) {
                    num = num * 10 + (s[ind] - '0');
                    ++ind;
                }
                ch = s[ind++];
                if (isalpha(s[ind])) ch = ch + s[ind++];
                if (num == 0) continue;
                if (ch == "N") y += double(num);
                else 
                if (ch == "E") x += double(num);
                else
                if (ch == "S") y -= double(num);
                else
                if (ch == "W") x -= double(num);
                else
                if (ch == "NE") {
                    double tmp = double(num) * sqrt(2.0);
                    x+=(tmp / 2.0);
                    y+=(tmp / 2.0);
                }
                else
                if (ch == "SE") {
                    double tmp = double(num) * sqrt(2.0);
                    x+=(tmp / 2.0);
                    y-=(tmp / 2.0);
                }
                else
                if (ch == "SW") {
                    double tmp = double(num) * sqrt(2.0);
                    x-=(tmp / 2.0);
                    y-=(tmp / 2.0);
                }
                else
                if (ch == "NW") {
                    double tmp = double(num) * sqrt(2.0);
                    x-=(tmp / 2.0);
                    y+=(tmp / 2.0);
                }
            }
            ++ind;
        }
        printf("Map #%d\n",++cases);
        printf("The treasure is located at (%.3lf,%.3lf).\n",x, y);
        printf("The distance to the treasure is %.3lf.\n\n",sqrt(x * x + y * y));
    }
}
