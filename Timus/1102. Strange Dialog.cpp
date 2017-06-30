/***********************************************
* Author - LUONG VAN DO                        *
* Problem 1102. Strange Dialog
* Algorithm
* Time Limit
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
#define N 10000010

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
char *s1 = "one";
char *s2 = "puton";
char s[N];
int next1[10], next2[10];
void preKmp(char s[], int next[]) {
    int i, j, m;
    i = 0; j = next[0] = -1; m = strlen(s);
    while (i < m) {
        while (j>=0 && s[i] != s[j]) j = next[j];
        ++i; ++j;
        next[i] = j;
    }
}
bool isOk(char s[]) {
    int n = strlen(s), i, j;
    i = j = 0;
    while (i < n) {
        while (j>=0 && s[i] != s1[j]) j = next1[j];
        ++i; ++j;
        if (j == 3) return true;
    }
    i = j = 0;
    while (i < n) {
        while (j>=0 && s[i] != s2[j]) j = next2[j];
        ++i; ++j;
        if (j == 5) return true;
    }
    return false;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases;
    scanf(" %d ",&cases);
    preKmp(s1, next1);
    preKmp(s2, next2);
    while (cases--) {
        gets(s);
//        cout<<s<<endl;
        if (isOk(s)) puts("YES");
        else puts("NO");
    }
}
