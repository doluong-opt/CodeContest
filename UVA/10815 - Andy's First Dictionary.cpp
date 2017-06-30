/***********************************************
* Author - LUONG VAN DO                        *
* Problem 10815 - Andy's First Dictionary ->AC
* Algorithm Adhoc
* Time Limit 0.044s
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
    char s[M];
    vector <string> res;
    int n, k;
    string ch;
    while ( gets(s) ) {
        n = strlen(s); k = 0;
        if (n == 0) continue;
        while (k < n) {
            while (k < n && !isalpha(s[k])) ++k;
            ch = "";
            while (k < n && isalpha(s[k])) ch+=tolower(s[k++]);
            if (ch.size()) res.pb(ch);
        }
    }
    sort(res.begin(), res.end());
    for (int i=0;i<res.size();i++)
        if (i && res[i] == res[i-1]) continue;
        else cout<<res[i]<<endl;
}
