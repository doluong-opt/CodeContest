/***********************************************
* Author - LUONG VAN DO                        *
* 10019 - Funny Encryption Method
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
    int test, n;
    int b1, b2, m;
    uint64 nn, base;
    scanf("%d",&test);
    FOR(t, 1, test) {
        scanf("%d",&n);
        m = n; b1 = b2 = 0;
        while ( n ) {
            b1+=(n % 2);
            n/=2;
        }
        nn = 0; base = 1;
        while ( m ){
            nn = nn + (m % 10) * base;
            m/=10;
            base*=16;
        }
        while ( nn ) {
            b2+=(nn % 2);
            nn/=2;
        }
        printf("%d %d\n",b1,b2);
    }
    return 0;
}
