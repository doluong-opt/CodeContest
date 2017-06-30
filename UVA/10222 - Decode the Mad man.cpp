/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10222 - Decode the Mad man ->AC
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

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
char *f = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
char *g = "~!@#$%^&*()_+{}|:\"<>?";
int num[M + 1];
int n;
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    string s;
    REP(i, strlen(f)) num[f[i]] = i;
    REP(i, strlen(g)) num[g[i]] = i;
    while ( getline(cin, s) ) {
        n = s.length();
        REP(i, n) {
            if (isalpha(s[i])) s[i] = tolower(s[i]);
            if (s[i] == ' ') cout<<" ";
            else cout<<f[num[s[i]]-2];
        }
        printf("\n");
    }
}
