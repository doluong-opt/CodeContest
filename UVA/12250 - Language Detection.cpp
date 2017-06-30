/***********************************************
* Author - LUONG VAN DO                        *
* 12250 - Language Detection ->AC
* Algorithm Adhoc 
* Time Limit 0.02s
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
#define maxN 50001
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    string s;
    int Case = 0;
    while ( cin >> s ) {
        if (s == "#") break;
            if (s == "HELLO") printf("Case %d: ENGLISH\n",++Case);
        else
            if (s == "HOLA") printf("Case %d: SPANISH\n",++Case);
        else
            if (s == "HALLO") printf("Case %d: GERMAN\n",++Case);
        else
            if (s == "BONJOUR") printf("Case %d: FRENCH\n",++Case);
        else
            if (s == "CIAO") printf("Case %d: ITALIAN\n",++Case);
        else
            if (s == "ZDRAVSTVUJTE") printf("Case %d: RUSSIAN\n",++Case);
        else printf("Case %d: UNKNOWN\n",++Case);
    }
    return 0;
}
