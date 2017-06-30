/***********************************************
* Author - LUONG VAN DO                        *
* Problem 377 - Cowculations ->AC
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
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int N, Num1, Num2, n, result;
    char s[M + 1];
    scanf(" %d ",&N);
    puts("COWCULATIONS OUTPUT");
    REP(i, N) {
        gets(s); n = strlen(s);
        Num1 = Num2 = 0;
        REP(i, n) {
            Num1*=4;
            if (s[i] == 'U') Num1++;
            else
            if (s[i] == 'C') Num1+=2;
            else
            if (s[i] == 'D') Num1+=3;
        }
        gets(s); n = strlen(s);
        REP(i, n) {
            Num2*=4;
            if (s[i] == 'U') Num2++;
            else
            if (s[i] == 'C') Num2+=2;
            else
            if (s[i] == 'D') Num2+=3;
        }
        REP(i, 3) {
            gets(s);
            if (s[0] == 'N') continue;
            else
            if (s[0] == 'A') Num2+=Num1;
            else
            if (s[0] == 'L') Num2*=4;
            else Num2/=4;
        }
        gets(s); n = strlen(s);
        result = 0;
        REP(i, n) {
            result*=4;
            if (s[i] == 'U') result++;
            else
            if (s[i] == 'C') result+=2;
            else
            if (s[i] == 'D') result+=3;
        }
        if (Num2 == result) puts("YES");
        else puts("NO");
    }
    puts("END OF OUTPUT");
}
