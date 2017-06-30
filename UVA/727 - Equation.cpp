/***********************************************
* Author - LUONG VAN DO                        *
* Problem 727 - Equation ->AC
* Algorithm adhoc
* Time Limit 0.064s
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
#define FileIn(file) freopen(file".inp", "r", stdin)
#define FileOut(file) freopen(file".out", "w", stdout)
#define fr(i,a,b) for (int i=a;i<=b;i++)
#define frr(i,a,b) for (int i=a;i>=b;i--)
#define rep(i, n) for (int i=0; i<n; i++)
#define repr(i, n) for (int i=n - 1; i>=0; i--)
#define pb push_back
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 500000000
#define N 100000

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
int pri(char c) {
    if (c == '(' || c == ')' ) return 0;
    if (c == '+' || c == '-' ) return 1;
    if (c == '*' || c == '/' ) return 2;
}
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int cases, n, caseno = 0;
    char s[20];
    scanf(" %d ",&cases);
    while (cases--) {
        stack <char> st;
        if ( caseno ) puts("");
        ++caseno;
        while (gets(s)) {
            if (strlen(s) == 0) break;
            int i = 0, n = strlen(s);
            if (isdigit(s[0])) printf("%s",s);
            else
            if (s[0] == '(') st.push(s[0]);
            else
            if (s[0] == ')') {
                while ( !st.empty() && st.top() != '(' ) {
                    printf("%c",st.top());
                    st.pop();
                }
                if (st.size()) st.pop();
            }
            else
            if (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/') {
                while ( !st.empty() && pri(s[0]) <= pri( st.top() ) ) {
                    printf("%c", st.top());
                    st.pop();
                }
                st.push( s[0] );
            }
        }
        while ( !st.empty() ) {
            printf("%c", st.top());
            st.pop();
        }
        puts("");
    }
}
