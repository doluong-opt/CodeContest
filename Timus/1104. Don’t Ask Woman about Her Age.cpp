/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1104. Don’t Ask Woman about Her Age ->AC
* Algorithm number theory
* Time Limit 0.375s
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
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 1000010

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
char s[N];
bool check(int x) {
    int64 base = 1;
    int64 sum = 0;
    for (int i=strlen(s)-1;i>=0;i--) {
        if (isalpha(s[i])) {
            if (((s[i]-'A') + 10) >= x) return false;
            sum+=((s[i] - 'A') + 10) * base;
            sum%=(x - 1);
        }
        else {
            if ((s[i]-'0') >= x) return false;
            sum+=((s[i] - '0')) * base;
            sum%=(x - 1);
        }
        base*=x; base%=(x - 1);
    }
    return (sum == 0);
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int f = 0, k;
    scanf("%s",&s);
    for (k=2;k<=36 && !f;k++) {
        if (check(k)) f = 1;
    }
    if (f) printf("%d\n",k - 1);
    else puts("No solution.");
}
