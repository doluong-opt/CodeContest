/***********************************************
* Author - LUONG VAN DO                        *
* 119 - Greedy Gift Givers ->AC
* Algorithm Adhoc
* Time Limit 0.016s
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
map <string, int> M;
string Name[maxN];
int money[maxN], gived, m;
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    string ss;
    int x, blank, n, so, du;
    blank = 0;
    while ( scanf(" %d ",&n)!=EOF ){
        M.clear();
        REP(i, n) {
            cin >> Name[i];
            M[Name[i]] = i;
        }
        REP(i, n)
            money[i] = 0;
        REP(i, n) {
            cin >> ss;
            x = M[ss];
            cin >> gived >> m;
            if (m !=0) so = gived / m;
            if (m !=0) du = gived % m;
            money[x]-=(so * m);
            REP(j, m) {
                cin >> ss;
                x = M[ss];
                money[x]+=so;
            }
        }
        if ( blank ) puts("");
        else blank = 1;
        REP(i, n)
            cout << Name[i] <<" "<<money[i]<<endl;
    }
    return 0;
}
