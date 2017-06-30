/***********************************************
* Author - LUONG VAN DO                        *
* Problem 642 - Word Amalgamation ->AC
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
#define M 110

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
    char t[M][M];
    map <string, bool> f;
    vector <string> res;
    string g[M];
    int n = 0;
    while ( scanf("%s",s)) {
        if (strcmp(s, "XXXXXX") == 0) break;
        g[n++] = s;
        sort(s, s + strlen(s));
        strcpy(t[n], s);
        f[s] = true;
    }
    while ( scanf("%s",s)) {
        if (strcmp(s, "XXXXXX") == 0) break;
        sort(s, s + strlen(s));
        if ( !f[s] ) {
            puts("NOT A VALID WORD");
            puts("******");
        }
        else {
            res.clear();
            for (int i=1;i<=n;i++)
                if (strcmp(t[i], s) == 0) res.pb( g[i-1] );
            sort(res.begin(), res.end());
            for (int i=0;i<res.size();i++) cout<<res[i]<<endl;
            puts("******");
        }
    }
}
