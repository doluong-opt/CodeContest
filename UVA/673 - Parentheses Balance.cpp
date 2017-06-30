/***********************************************
* Author - LUONG VAN DO                        *
* 673 - Parentheses Balance ->AC
* Algorithm Stack
* Time Limit 0.084s
* *********************************************/
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
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
#define maxN 130
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
stack <char> S;
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int test;
    char s[maxN], ch;
    bool ok;
    scanf(" %d ",&test);
    FOR(t, 1, test) {
        gets(s);
        ok = true;
        REP(i, strlen(s)) {
            if (s[i] == '(' || s[i] =='[' ) S.push( s[i] );
        else
            if (s[i] == ')' || s[i] == ']') {
                if (S.size()) ch = S.top();
                else ch = 'a';
                    if (s[i] == ')' && ch == '(' ) S.pop();
                else
                    if (s[i] == ']' && ch == '[' ) S.pop();
                else {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok || !S.empty() ) puts("No");
        else puts("Yes");
        while ( !S.empty() ) S.pop();
    }
    return 0;
}
