/***********************************************
* Author - LUONG VAN DO                        *
* 11495 - Bubbles and Buckets ->AC
* Algorithm sort
* Time Limit 0.24s
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
#define maxN 100001
#define EM 0.5772156649015328606065120900824
using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) {if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) {return a * (b / gcd(a, b) ); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int a[maxN];
int main(){
    #ifndef ONLINE_JUDGE
    FileIn("exam"); FileOut("exam");
    #endif
    int n, temp;
    while ( scanf("%d",&n) && n){
        FOR(i, 1, n) scanf("%d",&a[i]);
        bool win = 1;
        for (int i=1;i<=n;) {
            if (a[i]!=i) {
                temp = a[i];
                a[i] = a[ a[i] ];
                a[temp] = temp;
                win = !win;
            }
            else ++i;
        }
        if (win) puts("Carlos");
        else puts("Marcelo");
    }
    return 0;
}
